#include <stdio.h>
int q_rsqrt(int number);
int convert_to_float(int x);
int convert_to_int(int x);
long sqrt_approx_fixed(long n)
{
    if (n <= 0) return 0; // 負の数やゼロは処理しない

    long x = n * 1000000;  // 入力値を固定小数点（100倍）として拡張
    long x_prev;
    int i= 0;

    while (1) {
        i++;
        x_prev = x;
        x = (x + n * 1000000 / x) / 2; // ニュートン法
        if (x == x_prev)  {          // 収束したら終了
            printf("%d\n",i);
            break;
        }
    }

    return x; // 結果を100倍した形で返す
}

int main()
{

    printf("sqrt(%ld) = %d\n", 10,sqrt_approx_fixed(1024*1025+512*512));
    return 0;
}




int convert_to_float(int input)
{
    int sign;
    int exponent;
    int mantissa;
    // 符号を判定
    sign = (input < 0) ? 1 : 0;

    // 入力が0の場合の特別な処理
    if (input == 0) {
        exponent = 0; // ゼロは特別にすべて0
        mantissa = 0;
        return (sign << 31) | (exponent << 23) | mantissa;
    }

    if (sign) input = -input; // 負数の場合は正数に変換

    // 指数部の計算（log2でビット幅を取得）
    int exponent_raw = (int)log2(input);
    exponent = exponent_raw + 127; // バイアス127を加算

    // 仮数部の計算
    int mantissa_bits = 23;
    int shift = exponent_raw - mantissa_bits; // 正規化後のシフト量

    // 仮数部分を計算して23ビットに収める
    int mantissa_raw = (shift < 0) ? (input << -shift) : (input >> shift);
    mantissa = mantissa_raw & ((1 << mantissa_bits) - 1); // 下位23ビットを取り出す


    return (sign << 31) | (exponent << 23) | mantissa;
}

int convert_to_int(int x)
{
    // IEEE 754フォーマットの32ビットを解釈
    int sign = (x >> 31) & 1;         // 符号ビット (最上位ビット)
    int exponent = ((x >> 23) & 0xFF) - 127; // 指数部（8ビット）からバイアス127を引く
    int mantissa = (x & 0x7FFFFF) | (1 << 23); // 仮数部（23ビット）+ 暗黙の1を加える

    // 特殊ケース: 非正規化数やゼロの場合
    if (exponent == -127) {
        return 0; // 非正規化数またはゼロは整数部分が0
    }

    // 指数に基づく値の計算
    int result;
    if (exponent >= 23) {
        // 左シフト: 仮数部を整数として復元
        result = mantissa << (exponent - 23);
    } else if (exponent >= 0) {
        // 右シフト: 小数部分を切り捨て
        result = mantissa >> (23 - exponent);
    } else {
        // 非常に小さい値は整数部分が0
        result = 0;
    }

    // 符号を適用
    return sign ? -result : result;
}

int q_rsqrt(int number)
{
    long i;
    int x2, y;
    int threehalfs = 1.5F;
    x2 = number >>1;
    y  = number;
    printf("%f\n", *(float *)&number);
    y  = 0x5f3759df - ( y >> 1 );               // what the fuck?
    printf("%f\n",(*(float *)&y)) ;
    printf("%f\n",(*(float *)&y)* convert_to_int(number));
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}

int q_rsqrt_int(int number)
{
    int i;
    int x2, y;
    const int threehalfs = 0x3fc00000; // threehalfs = 1.5 in IEEE 754 (binary: 0x3fc00000)

    // x2 = number * 0.5
    x2 = number >> 1; // number / 2 (bit-shift for efficiency)

    // y = number
    y = number;

    // ビットレベルでの操作
    i = y;                       // ビットをそのままコピー
    i = 0x5f3759df - (i >> 1);   // 魔法の定数とシフト演算

    y = i;                       // 再度、ビットをyに戻す

    // 1回目のニュートン法の反復
    // y = y * (threehalfs - (x2 * y * y))
    y = (y * (threehalfs - ((x2 * y >> 23) * y >> 23))) >> 23;

    return y;
}