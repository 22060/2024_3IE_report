#include "iodefine.h"
//LCD
#define LCD_RS		(PA.DR.BIT.B22)
#define LCD_E		(PA.DR.BIT.B23)
#define LCD_RW		(PD.DR.BIT.B23)
#define LCD_DATA	(PD.DR.BYTE.HH)
//CMT
#define Timer0 (CMT.CMSTR.BIT.STR0)
#define Timer1 (CMT.CMSTR.BIT.STR1)
#define start_t (1)
#define stop_t (0)
#define timer0_flag (CMT0.CMCSR.BIT.CMF)
#define timer1_flag (CMT1.CMCSR.BIT.CMF)
//STDIO
#define	printf	((int (*)(const char *,...))0x00007c7c)
#define	scanf	((int (*)(const char *,...))0x00007cb8)
//LED
#define  LED6  (PE.DR.BIT.B11)
#define  LED5  (PE.DR.BIT.B9)
#define  LED_ON  (0)
#define  LED_OFF (1)
//SW
#define  SW6   (PD.DR.BIT.B18)
#define  SW5   (PD.DR.BIT.B17)
#define  SW4   (PD.DR.BIT.B16)
#define  SW_ON  (1)
#define  SW_OFF (0)
//SPK
#define  SPK	(PE.DR.BIT.B0)

void init(void){
    //CMT init
    STB.CR4.BIT._CMT = 0;		// モジュールスタンバイ解除
    //CMT0
	CMT0.CMCSR.BIT.CKS = 0;		// ① CKS設定(0:1/8, 1:1/32, 2:1/128, 3:1/512)
	CMT0.CMCOR = 25 - 1;		// ②

	Timer0 = start_t;		// ③ CMT0 カウント開始
	//CMT1
	CMT1.CMCSR.BIT.CKS = 3;		// ① CKS設定(0:1/8, 1:1/32, 2:1/128, 3:1/512)
	CMT1.CMCOR = 10 - 1;		// ②
	Timer1 = start_t;
    //IO init
	//SPK
	PFC.PEIORL.BIT.B0 = 1;		// PE0(SPK) .. 出力
    //LED
	PFC.PEIORL.BIT.B9 = 1;		// PE9(LED5) .. 出力
	PFC.PEIORL.BIT.B11 = 1;		// PE11(LED5) .. 出力
	LED5 = LED_OFF;
	LED6 = LED_ON;
    //SW
    PFC.PDIORH.BIT.B16 = 0;		// PD16(SW4) .. 入力
    PFC.PDIORH.BIT.B17 = 0;		// PD17(SW5) .. 入力
    PFC.PDIORH.BIT.B18 = 0;		// PD18(SW6) .. 入力
    //LCD
	PFC.PAIORH.BIT.B22 = 1;
	PFC.PAIORH.BIT.B23 = 1;
	PFC.PDIORH.BIT.B23 = 1;
	PFC.PDIORH.BYTE.H = 0xff;
};