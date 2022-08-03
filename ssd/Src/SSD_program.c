#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"

void SSD_voidInit(SSD_struct* Copy_pSSD_structInfo)
{
	
RCC_voidSysClockInit();
if (Copy_pSSD_structInfo->SSD_u8PORT==GPIO_u8_PORTA)
	RCC_voidEnablePerClk(RCC_AHB1,AHB1_GPIOA );
else if (Copy_pSSD_structInfo->SSD_u8PORT==GPIO_u8_PORTB)
	RCC_voidEnablePerClk(RCC_AHB1,AHB1_GPIOB );

	


GPIO_u8SetPinDirection(Copy_pSSD_structInfo->SSD_u8PORT, Copy_pSSD_structInfo->SSD_u8PIN0, GPIO_u8_PIN_OUTPUT);
GPIO_u8SetPinDirection(Copy_pSSD_structInfo->SSD_u8PORT, Copy_pSSD_structInfo->SSD_u8PIN1, GPIO_u8_PIN_OUTPUT);
GPIO_u8SetPinDirection(Copy_pSSD_structInfo->SSD_u8PORT, Copy_pSSD_structInfo->SSD_u8PIN2, GPIO_u8_PIN_OUTPUT);
GPIO_u8SetPinDirection(Copy_pSSD_structInfo->SSD_u8PORT, Copy_pSSD_structInfo->SSD_u8PIN3, GPIO_u8_PIN_OUTPUT);
GPIO_u8SetPinDirection(Copy_pSSD_structInfo->SSD_u8PORT, Copy_pSSD_structInfo->SSD_u8PIN4, GPIO_u8_PIN_OUTPUT);
GPIO_u8SetPinDirection(Copy_pSSD_structInfo->SSD_u8PORT, Copy_pSSD_structInfo->SSD_u8PIN5, GPIO_u8_PIN_OUTPUT);
GPIO_u8SetPinDirection(Copy_pSSD_structInfo->SSD_u8PORT, Copy_pSSD_structInfo->SSD_u8PIN6, GPIO_u8_PIN_OUTPUT);
GPIO_u8SetPinDirection(Copy_pSSD_structInfo->SSD_u8PORT, Copy_pSSD_structInfo->SSD_u8PIN7, GPIO_u8_PIN_OUTPUT);

}

void SSD_voidSetNumber(u8 Copy_u8Number, SSD_struct* Copy_pSSD_structInfo)
{
	u8 Local_u8arrayNumbersSSD[]={ZERO  ,ONE   , TWO   ,  THREE , FOUR  , FIVE  
	, SIX   , SEVEN , EIGHT , NINE }  ;
	

	
	if(Copy_pSSD_structInfo->SSD_u8Type==COMMON_ANODE)
	{
		GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN0,~GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],0));
		GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN1,~GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],1));
		GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN2,~GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],2));
		GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN3,~GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],3));
		GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN4,~GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],4));
		GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN5,~GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],5));
		GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN6,~GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],6));
		GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN7,~GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],7));
	}
	
	if(Copy_pSSD_structInfo->SSD_u8Type==COMMON_CATHODE)
		{
			GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN0,GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],0));
			GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN1,GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],1));
			GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN2,GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],2));
			GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN3,GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],3));
			GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN4,GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],4));
			GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN5,GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],5));
			GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN6,GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],6));
			GPIO_u8SetPinValue(Copy_pSSD_structInfo->SSD_u8PORT,Copy_pSSD_structInfo->SSD_u8PIN7,GET_BIT(Local_u8arrayNumbersSSD[Copy_u8Number],7));

		}
	
	
}
