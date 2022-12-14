/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "GPIO_interface.h"
#include"SSD_interface.h"
#include "SSD_private.h"



void SmallDelay (void)
{
    for(u32 s = 0 ; s<200 ; s++ )
    {
        asm("NOP");
    }
}




int main(void)
{

	SSD_struct     Local_SSD_structNewSSD ={PORTA, PIN0	,PIN1,PIN2,PIN3,PIN4
		,PIN5,PIN6,PIN7,COMMON_CATHODE} ;

	SSD_voidInit (& Local_SSD_structNewSSD);
	 GPIO_u8SetPinDirection(GPIO_u8_PORTA, GPIO_u8_PIN8, GPIO_u8_PIN_OUTPUT);
	 GPIO_u8SetPinDirection(GPIO_u8_PORTA, GPIO_u8_PIN9, GPIO_u8_PIN_OUTPUT);
	 GPIO_u8SetPinValue (GPIO_u8_PORTA, GPIO_u8_PIN8, GPIO_u8_PIN_HIGH);
	 GPIO_u8SetPinValue (GPIO_u8_PORTA, GPIO_u8_PIN9, GPIO_u8_PIN_HIGH);

    u8 Local_u8Counter1=9;
    u8 Local_u8Counter2=0;
    int j=0;
    while(1){
    	j=0;
	for(j;j<2099;j++){

		GPIO_u8SetPinValue (GPIO_u8_PORTA, GPIO_u8_PIN9, GPIO_u8_PIN_HIGH);
		SSD_voidSetNumber(Local_u8Counter1, &Local_SSD_structNewSSD);
		GPIO_u8SetPinValue (GPIO_u8_PORTA, GPIO_u8_PIN8, GPIO_u8_PIN_LOW);


	SmallDelay ();
		GPIO_u8SetPinValue (GPIO_u8_PORTA, GPIO_u8_PIN8, GPIO_u8_PIN_HIGH);
		 SSD_voidSetNumber(Local_u8Counter2, &Local_SSD_structNewSSD);
		GPIO_u8SetPinValue (GPIO_u8_PORTA, GPIO_u8_PIN9, GPIO_u8_PIN_LOW);


		 SmallDelay ();

	}
	Local_u8Counter1++;
	Local_u8Counter2--;
	if(Local_u8Counter1==10)Local_u8Counter1=0;
	if(Local_u8Counter2==255)Local_u8Counter2=9;
    }
}
