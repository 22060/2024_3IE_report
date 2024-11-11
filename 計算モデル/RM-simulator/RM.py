'''
=====================================================================
    「計算モデル論」 RMシミュレータ RM.c

    機能等：
        1) 命令読込・解読・実行サイクルの実装
        2) 命令の実行過程の表示
        3) ファイルからプログラムの読み込み (*.ram, *.rm)
        4) オプションの処理 (-s, -t)
        5) コメント対応   //...
        6) 正常終了，連続実行への切替機能 c, q
        7) 命令名の変更（add1->succ, sub1->pred）
            2017/09/18  作成者 T.Inomata
        8) 命令の追加（PLUS, MINUS）即値との加算・減算
            2018/04/24  作成者 T.Inomata
        9) 配列名称・印字文字変更（ R[]<-->M[] ）
            プログラムの印字（命令コード形式）オプション -p 追加
            2018/08/07  作成者 T.Inomata
        10) 命令名の変更（setd->setc）
            2018/08/31  作成者 T.Inomata     
        11) 命令の追加（JEQ0）
            2019/03/01  作成者 T.Inomata
        12) python への移植
            2021/05/19  製作者 K.Yamada     
---------------------------------------------------------------------
実行の仕方:
    RMプログラム書かれたファイル名を sample.ram とした場合：
    $ RM [-s -t]  sample.ram
        -s : ワンサイクル実行（リターンキーで再開） 
        -t : ワンサイクル毎にレジスタの内容印字
        -r n : レジスタ表示個数 n の指定（デフォルト 7）

    プログラムの強制終了は，Cntrl-c 
=====================================================================
'''

# VERSION 2.1 バージョン番号

import sys
import re

memory_max = 100  # レジスタ群(データ領域)の最大サイズ

'''
シミュレータの動作モード
    RUN  通常実行モード(default)
    STEP  ステップ実行モード(サイクル単位)
    TRACE  トレースモード(サイクル毎にレジスタを表示する)
    PRINT  プログラムの印字(印字後終了)
    HALT  実行停止
'''

# レジスタ機械の命令セットアーキテクチャ
instructions = [
    'NOP',  # 0: ダミー命令(No Operation)
    'LOAD',  # 1: Acc <-- M[x]
    'STORE',  # 2: M[x] <-- Acc
    'JUMP',  # 3: Ic <-- x 無条件ジャンプ
    'JZERO',  # 4: (Acc=0 ?) ==> Ic <-- x ゼロ判定ジャンプ
    'HALT',  # 5: quit 実行終了
    'SETC',  # 6: Acc <-- x
    'SUCC',  # 7: Acc <-- Acc + 1 後者
    'PRED',  # 8: Acc <-- Acc - 1 前者
    'ADD',  # 9: Acc <-- Acc + M[x] 加算
    'SUB',  # 10: Acc <-- Acc - M[x] 減算
    'LOADI',  # 11: Acc <-- M[M[x]] 間接アドレス
    'STOREI',  # 12: M[M[x]] <-- Acc 間接アドレス
    'PLUS',  # 13: Acc <-- Acc + x 加算(即値x)
    'MINUS',  # 14: Acc <-- Acc - x 減算(即値x)
    'JEQ0'  # 15: (Acc=M[0] ?) ==> Ic<--x
]

# レジスタ機械の構成要素
ic = 0  # 命令カウンタ IC
acc = 0  # 累算器(accumelator) Acc
ir = {'op':0, 'ord':0}  # 命令レジスタ IR
m = [0 for _ in range(memory_max)]  # データ記憶装置 M
r = []  # プログラム記憶装置 R

# シミュレータの状態管理
rm_state = 'RUN'  # RMシミュレータ実行モード
reg_max = 7  # レジスタ表示個数(default = 7)
n_cycle  = 0  # 命令実行サイクルカウンタ
file_name = '' # 実行する .rm ファイルのファイル名

def print_usage():
    print('usage:')
    print('python RM.py [-s] [-t] [-r n] [-p] [-h] filename.rm')
    print('    -s: ステップ実行(リターン入力で再開)')
    print('    -t: レジスタ情報(IC, IR, Acc, M[])のサイクル毎の印字')
    print('    -r n: レジスタ表示個数 n の指定(デフォルト 7)')
    print('    -p: プログラム(R[]の内容)の表示，表示後終了')
    print('    -h: このメッセージを表示')
    print('    filename.rm: RM のプログラムコード．filename.ram でも可')

def init():
    '''
    ========== オプションの処理 ==========
        -s : ステップ実行(リターン入力で再開)
        -t : レジスタ情報(IC, IR, Acc, M[])のサイクル毎の印字
        -r n : レジスタ表示個数 n の指定(デフォルト 7)
        -p : プログラム(R[]の内容)の表示，表示後終了
    '''
    global rm_state
    global reg_max
    global file_name

    args = sys.argv

    # オプションも .rm ファイルも指定されていなければ終了する
    if len(args) == 1:
        print_usage()
        sys.exit()

    i = 1
    while i < len(args):
        if args[i] == '-s':
            rm_state = 'STEP'
        elif args[i] == '-t':
            rm_state = 'TRACE'
        elif args[i] == '-r':
            i = i + 1
            if i < len(args):
                reg_max = int(args[i])
            else:
                print_usage()
                sys.exit()
        elif args[i] == '-p':
            rm_state = 'PRINT'
        elif re.search(r'(.rm|.ram)$', args[i]):
            file_name = args[i]
        else:
            print_usage()
            sys.exit()
        i = i + 1

    '''
    ========== ファイルの読み込み ==========
        ファイルを読み込みながらプログラムを R[] に格納する
    '''
    with open(file_name, mode='r', encoding='UTF-8') as f:
        # コメントを切り離し，命令列だけを lines に取り出す
        lines = []
        for line in f:
            line = line.replace('\n', '')  # 末尾の改行コードを取り除く
            line = line.split('//').pop(0)  # コメントを削除する
            if line != '':
                lines.append(line)
        # 命令をオペコードとオペランドにわけて，R[] に格納する
        for line in lines:
            inst = line.split()
            op = instructions.index(inst[0])
            ord = 0 if len(inst) <= 1 else int(inst[1])
            r.append(op)
            r.append(ord)

def print_program():
    print('-- 命令記憶装置 --')
    for i in range(len(r)):
        print('    R[{:2}] = {:2}'.format(i, r[i]))

def print_inst():
    print('Cycle= {}'.format(n_cycle))
    print(' IC[{}]  IR[{:7}{}]  Acc[{}]'.format(ic, 
        instructions[ir['op']], ir['ord'], acc))

def print_register():
    for i in range(reg_max):
        print('    M[{:2}] = {:3}'.format(i, m[i]))

def read_inst():
    global ic
    global ir
    
    ir['op'] = r[ic]
    ic = ic + 1
    ir['ord'] = r[ic]
    ic = ic + 1

def decode_exec():
    global ic
    global acc
    global rm_state
    
    # 命令のデコード
    opcode = instructions[ir['op']]
    operand = ir['ord']

    # 命令の実行
    if opcode == 'NOP':
        pass
    elif opcode =='LOAD':
        acc = m[operand]
    elif opcode =='STORE':
        m[operand] = acc
    elif opcode =='JUMP':
        ic = operand
    elif opcode =='JZERO':
        if acc == 0:
            ic = operand
    elif opcode =='HALT':
        rm_state = 'HALT'
    elif opcode =='SETC':
        acc = operand
    elif opcode =='SUCC':
        acc = acc + 1
    elif opcode =='PRED':
        acc = acc - 1
        if acc < 0:
            acc = 0
    elif opcode =='ADD':
        acc = acc + m[operand]
    elif opcode =='SUB':
        acc = acc - m[operand]
        if acc < 0:
            acc = 0
    elif opcode =='LOADI':
        acc = m[m[operand]]
    elif opcode =='STOREI':
        m[m[operand]] = acc
    elif opcode =='PLUS':
        acc = acc + operand
    elif opcode =='MINUS':
        acc = acc - operand
        if acc < 0:
            acc = 0
    elif opcode =='JEQ0':
        if acc == m[0]:
            ic = operand
    else:
        pass

def rm_simulation():
    global rm_state
    global n_cycle

    while rm_state != 'HALT':
        n_cycle = n_cycle + 1
        if rm_state == 'TRACE' or rm_state == 'STEP':
            print_inst()
            print_register()
            print()
        if rm_state == 'STEP':
            cmd = input(' --(1サイクル実行：Return  連続実行：c   終了： q) ? ')
            if cmd == 'c':
                rm_state = 'RUN'
            elif cmd == 'q':
                print('bye.')
                sys.exit()
        read_inst()
        decode_exec()
    print_inst()
    print_register()

init()
if rm_state == 'PRINT':
    print_program()
    sys.exit()
rm_simulation()
