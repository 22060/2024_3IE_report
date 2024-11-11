'''
===================================================================
「計算モデル論」 チューリング機械 TM.py

    機能：
        1) コマンド行における定義ファイルの指定
        2) テープの初期状態の対話的な入力
        3) 状態表示の変更 [x]
        4) 終了方法の変更 （テープ入力字に"quit"でおしまい）
            2020/09/19
            作成者 K.Yamada
            original(C言語) T.Inomata 2019/03/01
--------------------------------------
実行の仕方:
    チューリング機械の定義が書かれたファイル名を M-2.tm とした場合：
    $ TM M-2.tm
    Sigma = {0, 1, *, N, Y, _}
    Input Initial Tape ? 01
    [ 0] : _01__________________
            ^

    ここで，「01」はテープの初期状態としての記号列(入力語に相当)
    空白文字は「_」．
    入力語の前後に空白記号を自動挿入する
    初期状態ではヘッド「^」は入力語の先頭文字の位置．    
    [ i] の i は，状態（0,1,・・・）を表す．
    
    プログラムを終えるは「quit」を入力する．
======================================================================
'''

import sys

BLANK = '_'

stateNum = 0  # 状態の種類数(定義ファイルで指定する)
symbolNum = 0  # 記号の種類数(定義ファイルで指定する)
symbolTable = [] # アルファベット
actionFunc = [] # 動作関数
# actionFunc[状態][入力記号][0] = 次状態(文字列なので，int に直す必要がある)
# actionFunc[状態][入力記号][1] = テープに書き込む記号
# actionFunc[状態][入力記号][2] = ヘッドの進む向き(L or R)

# テープの表現
tapeLen = 20  # シミュレーションする対象の記号数(両端の空白列も含む)
tape = []  # テープの記号列を格納するリスト
head = 1  # 現在のヘッドの位置，初期値は1

# TM の状態の表現
initState = 0  # 初期状態を表す変数．値は 0
nowState = 0  # 現在の状態を表す変数(0,1,2,3,...,n-1)
haltState = 0  # 停止状態のを表す変数(最後の状態 n-1)

# 定義ファイルからTMの定義内容を読込んでデータ構造に格納する関数
def init(fileName):
    global stateNum, symbolNum, haltState
    global symbolTable
    global actionFunc
    with open(fileName, mode='r') as f:
        TMdef = []
        for line in f:
            line = line.rsplit()
            if line != []:
                TMdef.append(line)
    # print(TMdef)
    stateNum = int((TMdef.pop(0)).pop())  # pop の副作用に注意
    haltState = stateNum - 1
    symbolTable = TMdef.pop(0)
    symbolNum = int(symbolTable.pop(0))
    actionFunc = []
    for _ in range(stateNum - 1):
        af = {}
        for sym in symbolTable:
            af[sym] = TMdef.pop(0)
        actionFunc.append(af)

# テープの記号列を印字する関数
def printTape():
    headerStr = f' [{nowState:2}] : '
    print(headerStr, end='')
    print(''.join(tape))
    for _ in range(len(headerStr) + head):
        print(' ', end='')
    print('^')

# 入力語を読込む関数
def readTape():
    global tape
    print(f'sigma = {symbolTable}')
    str = input('Input Initial Tape ? ')
    if str == 'quit':
        print('bye.')
        exit(0)
    for i in range(len(str)):
        tape[i + 1] = str[i]

# チューリング機械の初期状態を設定する関数
def initTM():
    global tape, nowState, head
    tape = [BLANK for _ in range(tapeLen)]
    nowState = initState
    head = 1

# チューリング機械の動作のシミュレーションをする関数
def TMSimulation():
    global nowState, head
    while(True):
        initTM()
        readTape()
        while(True):
            printTape()
            x = tape[head]
            tape[head] = actionFunc[nowState][x][1]
            if actionFunc[nowState][x][2] == 'R':
                head += 1
            elif actionFunc[nowState][x][2] == 'L':
                head -= 1
            nowState = int(actionFunc[nowState][x][0])
            if nowState == haltState:
                break
        printTape()
        print('Halt !\n')

args = sys.argv
try:
    init(args[1])
except IndexError:
    print(f'Usage : {args[0]} file_name')
except IOError:
    print(f'{args[1]} cannot be opened.')
else:
    # print(f'statelNum = {stateNum}')
    # print(f'symbolNum = {symbolNum}')
    # print(f'symbolTable = {symbolTable}')
    # print(f'actionFunc = {actionFunc}')
    TMSimulation()
