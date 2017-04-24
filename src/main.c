#include "bsp.h"
#include <stdio.h>
#include <stdlib.h>
#include "draw.h"
#include "tick.h"
#include "InitDevice.h"
#include <SI_EFM8BB3_Register_Enums.h>
#include "spi.h"
#include "blinky.h"
SI_SBIT(LED1, SFR_P1, 4);
SI_SBIT(LED2, SFR_P1, 5);
SI_SBIT(BTR, SFR_P0, 2);
SI_SBIT(BTL, SFR_P0, 3);

int lap=0;

int x1 = 0;
int x2 = 0;
int x3 = 0;
int clear=0;
bool BR;
bool BL;
int i;
int ii;
int sw=0;
int count=1;
int screenLocation=0;


static SI_SEGMENT_VARIABLE(line[16], uint8_t, RENDER_LINE_SEG);

void Delay(uint8_t x){
	for(ii=0;ii<x;ii++)
		_nop_();
}

//interrupts &timer
SI_INTERRUPT (TIMER0_ISR, TIMER0_IRQn)
{
	count=1;
	//LED1 = !LED1;
	TCON_TR0 = 0;             // timercontrol
	TH0 = 0xEC;       //    ori:00111100  T1:11101100
    TL0 = 0x10;       //    ori:11001000  T1:01111000

    Delay(100);
    TCON_TR0 = 1;
	x1 = x1 + sw;
}




SI_INTERRUPT (PMATCH_ISR, PMATCH_IRQn) {
	if (BTR==0) {
		if (BR==false) {
			if (sw == 0) {  //Stopped
				sw = 1;     //start the clock
				BR = true;
			}
			else {         //running
				sw = 0;    //stop the clock
				BR = true;
			}
		}
	}
	else if (BTL==0) {
		if (BL==false) {
			if (sw==0) { //pause
				x1=0;
				x2=0;
				x3=0;
				clear=1;
			}
			else {
				lap=1;
			}
		}
		BL = true;
	}
	 else {
		BR = false;
		BL = false;
	 	}
	}

char text[16];
int multilap=0;

void main(void)
{

 enter_DefaultMode_from_RESET();
  blinky();
  IE_EA = 1;
  DISP_Init();

  while (1)
  {
	if (count){
		text[0]='\0';
		if(x1>=100){
			x2=x2+1;
			x1=0;
		}
		if(x2==60){
		x3=x3+1;
		x2=0;
		}
		sprintf(text,"LAP    ""%02d:%02d,%02d",x3,x2,x1);
		DrawScreenText1(text,20,21);
		count=0;
		if (multilap == 2){		//enables multiple laps
			EIE1 |=0x02;  //re enable
			multilap = 0;
		}
		multilap++;
	}


	else if (lap){

			SFRPAGE = 0x00;              // EIE1 interrupt on SFRPAGE 0x00
			EIE1 &= ~0x02;           //disable
			screenLocation ++;
			text[0]='\0';
			sprintf(text,"%02d     %02d:%02d,%02d",screenLocation,x3,x2,x1);		//print to string
			DrawScreenText1(text, 20, screenLocation*10+25);

			lap=0;
			IE_EA=1;

		}

	else if (clear){
			for(i=35;i<25+10*(screenLocation+1)+1;i=i+10){
			DrawScreenText("", i);
			}
			clear=0;
			screenLocation=0;


		}
  }
}
