/* ===================================================================
      「計算モデル論」 チューリング機械 turing.c

          機能：1) コマンド行における定義ファイルの指定
               2) テープの初期状態の対話的な入力
               3) 状態表示の変更 [x]
               4) 終了方法の変更 （テープ入力字に"quit"でおしまい）

                                2019/03/01
                                作成者 T.Inomata
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
            [ i] の i は，状態（0,1,・・・）を表す．a
    
    プログラムを終えるは「quit」を入力する．
====================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAPE_MAX   100  // テープのマス目の最大値(配列のサイズ)
#define SYMBOL_MAX  20  // 記号の種類の最大値(配列のサイズ)
#define STATE_MAX   20  // 状態の種類数の最大値(配列のサイズ)
#define BLANK ('_');

int  State_Num;        //  状態の種類数(定義ファイルで指定)
int  Symbol_Num;       //  記号の種類数(定義ファイルで指定)
char Symbol_Table[SYMBOL_MAX]; //  記号を区別するための識別番号(0,1,2,...)との対応表

// テープの表現
int  Max_Tape = 20;  //  シミュレーションする対象の記号数(両端の空白列も含む)
char Tape[TAPE_MAX]; //  テープの記号列を格納する配列
int  Head = 1;       //  現在のヘッドの位置，初期値は1

// TM の状態の表現
int Init_State = 0;// 初期状態を表す変数．値は 0
int Now_State;     // 現在の状態を表す変数(0,1,2,3,...)
int Halt_State;    // 停止状態のを表す変数(状態の種類数に定義ファイルより設定)

struct Action_Data {   // 動作関数の表すための構造体
  int  st;   // 状態の遷移先
  char sym;  // 書き込み記号
  int  dir;  // ヘッドの移動方向  R or L
} Action_Func[STATE_MAX][SYMBOL_MAX];  // 動作関数を表す２次元配列
// 現在の状態 i, 読込み記号 j について，
//           Action_Func[i][j].st  次の状態 
//           Action_Func[i][j].sym 書込み記号 
//           Action_Func[i][j].sym ヘッドの移動方向 

//  【テープからのヘッド位置の記号を読込む関数】
//      読込んだ記号に対応する識別番号をリターン
//      Action_Func[i][j] の添字 j として用いられる
int input()
{
  char c;
  int i;
  c = Tape[Head];
  for (i = 0; i < Symbol_Num; i++)
    if (Symbol_Table[i] == c)  return i;

  return Symbol_Num - 1;
}

// 【現在の状態を更新する関数】
void action_state(int now, char c)
{
  Now_State = Action_Func[now][c].st;
}

// 【ヘッド上のマス目に記号を書込む関数】
void action_write(int now, char c)
{
  Tape[Head] = Action_Func[now][c].sym;
}

// 【ヘッドを１マス移動する関数】
void action_head(int now, char c)
{
  Head = Head + Action_Func[now][c].dir;
}


// 【テープの記号列を印字する関数】
void print_tape()
{
  int i;
  printf(" [%2d] : ", Now_State); // 現在の状態を「qx」として印字，x は状態番号 
  for (i = 0; i <= Max_Tape; i++) // テープ記号列を Max_Tape 文字分を印字
    printf("%c", Tape[i]);
  printf("\n");
  printf("        ");
  for (i = 0; i < Head; i++) // ヘッド位置を印字
    printf(" ");
  printf("^\n");
}

// 【定義ファイルからTMの定義内容を読込んでデータ構造に格納する関数】
void init(char *fname)   // fname 定義ファイル名
{
  int i, j, k;
  char c, d;
  FILE *fp;

  // ファイル名が存在しているかどうかのチェック
  if ((fp = fopen(fname, "r")) == NULL)
  {
    printf("ERROR : file name [%s] not found !!\n", fname);
    return;    // ファイルが存在しないときには強制終了
  }

  fscanf(fp, "%d", &State_Num); // 定義ファイルから「状態の種類数」を読込み
  Init_State = 0;             // 初期状態の番号を「 0」にする
  Halt_State = State_Num - 1; // 停止状態の番号を，「状態の種類数-1」にする
  //    (状態の番号を 0 から付け始めたため)

  fscanf(fp, "%d", &Symbol_Num); // 定義ファイルから「記号の種類数」を読込み
  for (i = 0; i < Symbol_Num; i++)
  {
    fscanf(fp, " %c", &c); // 定義ファイルから記号を順に読込み
    Symbol_Table[i] = c;   // 識別番号 0,1,2,...を付けて配列で記憶しておく
  }
  for (i = 0; i < State_Num; i++) // 定義ファイルから動作関数の各要素を読込む
    for (j = 0; j < Symbol_Num; j++)
    {
      fscanf(fp, "%d %c %c", &k, &c, &d);// 状態 i，読込み記号 j の動作関数の読込み
      Action_Func[i][j].st = k;          // 次の状態 k
      Action_Func[i][j].sym = c;         // 書込み記号 c
      Action_Func[i][j].dir = d == 'R' ? 1 : (-1); // ヘッドの移動方向 d
    }
}

// 【チューリング機械の初期状態を設定する関数】
void init_TM()
{
  int i;
  for (i = 0; i < TAPE_MAX; i++)
    Tape[i] = BLANK;
  Now_State = Init_State; // 現在の状態を初期状態に設定
  Head = 1;               // ヘッドの位置を２文字目に設定
  return;
}

// 【入力語を読込む関数】
void read_tape()
{
  int i;
  printf("Sigma = {"); // 記号の集合の印字
  printf("%c", Symbol_Table[0]);
  for (i = 1; i < Symbol_Num; i++)
  {
    printf(", %c", Symbol_Table[i]);
  }
  printf("}\n");
  printf("Input Initial Tape ? "); // 入力語を読込む
  scanf("%s", Tape + 1);
//printf(" ? |%s|\n", Tape);
  if (strcmp(Tape+1, "quit")==0)   // quit の入力？
     { printf("bye.\n"); exit(0);} //　終了
  for (i = strlen(Tape); i < TAPE_MAX; i++)
    Tape[i] = BLANK;
}

// 【チューリング機械の動作のシミュレーションをする関数】
void TM_simulation()
{
  int x;

  Max_Tape = 20;
  while (1)
  {
    init_TM();
    read_tape();   // テープの初期状態を入力
    do
    {
      print_tape();                //  現在のテープの印字
      x = input();                 //  ヘッド上の記号を読込み
      action_write(Now_State, x);  //  記号の書込み 
      action_head(Now_State, x);   //  ヘッドの移動
      action_state(Now_State, x);  //  状態の遷移
    } while (Now_State != Halt_State); // シミュレーションの停止判定
    print_tape();
    printf(" Halt ! \n\n");
  }
}

// 【メイン関数】
int main(int argc, char *argv[])
{
  char fname[80];

  if (argc > 1) init(argv[1]); // コマンド引数の個数チェック 
  else                         //  引数を定義ファイル名として読込み開始
  {
    printf("Usage : %s file_name\n", argv[0]);
    return 1;
  }

  TM_simulation();   // シミュレーションの開始
  return 0;
}
