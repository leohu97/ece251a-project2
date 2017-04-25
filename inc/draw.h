/*
 * draw.h
 *
 *  Created on: Apr 14, 2017
 *      Author: Richard
 */

/////////////////////////////////////////////////////////////////////////////
// draw.h
/////////////////////////////////////////////////////////////////////////////

#ifndef __DRAW_H__
#define __DRAW_H__

#include "disp.h"
#include "render.h"
#include "spi.h"

/////////////////////////////////////////////////////////////////////////////
// Definitions
/////////////////////////////////////////////////////////////////////////////
#define TEXT_AREA_X1 16
#define TEXT_AREA_X2 112
#define TEXT_AREA_Y1 73
#define TEXT_AREA_Y2 116

#define TEXT_ROW0_Y 88
#define TEXT_ROW1_Y 96

/////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////
extern void DrawScreenText(SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG), uint8_t y);
extern void DrawScreenText1(SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG), uint8_t x, uint8_t y);
extern void DrawSplashScreen(void);
extern void writeALot(char * z);
#endif // __DRAW_H__




