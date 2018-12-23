/*
 * Copyright (C) 2018-2019 RC-AUV.
 * All rights reserved.
 */
 
#include "WS2812/ws2812b_drv.h"

extern TIM_HandleTypeDef htim2;

uint16_t ws2812b_buff_DMA [WS2812B_ARRAY_LEN] = {0};

void WS2812bInit( void )
{
  int i;
	
  for ( i = WS2812B_DELAY_LEN; i < WS2812B_ARRAY_LEN; i++ )
	{
		ws2812b_buff_DMA[i] = WS2812B_LOW;
	}
}

void WS2812bPixelRGBtoDMA( uint8_t r , uint8_t g, uint8_t b, uint16_t posX )
{
  volatile uint16_t i;

  for( i = 0; i < 8 ; i++ )
  {
    if ( WS2812B_BIT_IS_SET( r, (7 - i) ) == 1 )
    {
      ws2812b_buff_DMA[WS2812B_DELAY_LEN + posX*24 + i + 8] = WS2812B_HIGH;
    }else
    {
      ws2812b_buff_DMA[WS2812B_DELAY_LEN + posX*24 + i + 8] = WS2812B_LOW;
    }
    if ( WS2812B_BIT_IS_SET( g, (7 - i) ) == 1 )
    {
      ws2812b_buff_DMA[WS2812B_DELAY_LEN + posX*24 + i + 0] = WS2812B_HIGH;
    }else
    {
      ws2812b_buff_DMA[WS2812B_DELAY_LEN + posX*24 + i + 0] = WS2812B_LOW;
    }
    if ( WS2812B_BIT_IS_SET( b, (7 - i) ) == 1 )
    {
      ws2812b_buff_DMA[WS2812B_DELAY_LEN + posX*24 + i + 16] = WS2812B_HIGH;
    }else
    {
      ws2812b_buff_DMA[WS2812B_DELAY_LEN + posX*24 + i + 16] = WS2812B_LOW;
    }
  }
}
