/*
 * Copyright (C) 2018-2019 RC-AUV.
 * All rights reserved.
 */

#ifndef _WS2812B_H_
#define _WS2812B_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f4xx_hal.h"

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define WS2812B_DELAY_LEN 		48
#define WS2812B_LEDS_COUNT 		4
#define WS2812B_ARRAY_LEN 		WS2812B_DELAY_LEN + WS2812B_LEDS_COUNT*24

#define WS2812B_HIGH 					65
#define WS2812B_LOW 					26

#define WS2812B_BIT_IS_SET(reg, bit) ((reg & (1<<bit)) != 0)

void WS2812bInit( void );

void WS2812bPixelRGBtoDMA( uint8_t r , uint8_t g, uint8_t b, uint16_t posX );

#ifdef __cplusplus
}
#endif

#endif /* _WS2812B_H_ */
