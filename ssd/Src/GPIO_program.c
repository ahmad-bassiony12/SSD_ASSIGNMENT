#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_private.h"
#include "GPIO_reg.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"




u8	GPIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState= 0 ;
	// THE BITS THAT WILL BE ACCESSED TO SET THE DIRECTION IN THE MODE REGISTER TO SET A CERTIAN PIN
	u8 Local_u8Config_Bit1=Copy_u8Pin*2;
	u8 Local_u8Config_Bit2=(Copy_u8Pin*2)+1;
	if(((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN13))||((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN14)))
	{
		Local_u8ErrorState=4;
		return Local_u8ErrorState;
	}
	if(((Copy_u8Port ==GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN3))||((Copy_u8Port == GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN4)))
	{
		Local_u8ErrorState=4;
		return Local_u8ErrorState;
	}
	if(Copy_u8Pin<=GPIO_u8_PIN15)
	{
		if(Copy_u8Direction==GPIO_u8_PIN_INPUT)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					
					CLR_BIT(GPIOA_MODER,Local_u8Config_Bit1);
					CLR_BIT(GPIOA_MODER,Local_u8Config_Bit2);
					
					
					break;
				}
				case GPIO_u8_PORTB  :
				{
					CLR_BIT(GPIOB_MODER,Local_u8Config_Bit1);
					CLR_BIT(GPIOB_MODER,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTC :
				{
					CLR_BIT(GPIOC_MODER,Local_u8Config_Bit1);
					CLR_BIT(GPIOC_MODER,Local_u8Config_Bit2);
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
			GPIO_u8SetIntputPinType(Copy_u8Port,Copy_u8Pin,DEFAULT_INPUT_TYPE);
		}
		else if (Copy_u8Direction==GPIO_u8_PIN_OUTPUT)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					SET_BIT(GPIOA_MODER,Local_u8Config_Bit1);
					CLR_BIT(GPIOA_MODER,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTB  :
				{
					SET_BIT(GPIOB_MODER,Local_u8Config_Bit1);
					CLR_BIT(GPIOB_MODER,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTC :
				{
					SET_BIT(GPIOC_MODER,Local_u8Config_Bit1);
					CLR_BIT(GPIOC_MODER,Local_u8Config_Bit2);
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
			GPIO_u8SetOutputPinType(Copy_u8Port,Copy_u8Pin,DEFAULT_OUTPUT_TYPE);
		}
		else if (Copy_u8Direction==GPIO_u8_PIN_ALTERNATE_MODE)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					SET_BIT(GPIOA_MODER,Local_u8Config_Bit2);
					CLR_BIT(GPIOA_MODER,Local_u8Config_Bit1);
					break;
				}
				case GPIO_u8_PORTB  :
				{
					SET_BIT(GPIOB_MODER,Local_u8Config_Bit2);
					CLR_BIT(GPIOB_MODER,Local_u8Config_Bit1);
					break;
				}
				case GPIO_u8_PORTC :
				{
					SET_BIT(GPIOC_MODER,Local_u8Config_Bit2);
					CLR_BIT(GPIOC_MODER,Local_u8Config_Bit1);
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
		}
		else if (Copy_u8Direction==GPIO_u32_PIN_ANALOG_MODE	)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					SET_BIT(GPIOA_MODER,Local_u8Config_Bit1);
					SET_BIT(GPIOA_MODER,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTB  :
				{
					SET_BIT(GPIOB_MODER,Local_u8Config_Bit1);
					SET_BIT(GPIOB_MODER,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTC :
				{
					SET_BIT(GPIOC_MODER,Local_u8Config_Bit1);
					SET_BIT(GPIOC_MODER,Local_u8Config_Bit2);
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
		}
		else 	Local_u8ErrorState=3;
		
	}
	else Local_u8ErrorState=1 ;
	GPIO_u8SetPinSpeed(Copy_u8Port,Copy_u8Pin,DEFAULT_SPEED);
	return Local_u8ErrorState ;
}
u8 GPIO_u8SetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	u8 Local_u8ErrorState= 0 ;
	if (Copy_u8Pin<=GPIO_u8_PIN15 ){
		if(((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN13))||((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN14)))
		{
			Local_u8ErrorState=4;
			return Local_u8ErrorState;
		}
		if(((Copy_u8Port ==GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN3))||((Copy_u8Port == GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN4)))
		{
			Local_u8ErrorState=4;
			return Local_u8ErrorState;
		}
		else
		{
			if(Copy_u8Value == GPIO_u8_PIN_HIGH)
			{
				switch(Copy_u8Port)
				{
					case GPIO_u8_PORTA	:	SET_BIT(GPIOA_ODR,Copy_u8Pin);	break;
					case GPIO_u8_PORTB	:	SET_BIT(GPIOB_ODR,Copy_u8Pin);	break;
					case GPIO_u8_PORTC	:	SET_BIT(GPIOC_ODR,Copy_u8Pin);	break;
					default : Local_u8ErrorState=2 ;						break;
				}
			}
			else if(Copy_u8Value == GPIO_u8_PIN_LOW)
			{
				switch(Copy_u8Port)
				{
					case GPIO_u8_PORTA	:	CLR_BIT(GPIOA_ODR,Copy_u8Pin);	break;
					case GPIO_u8_PORTB	:	CLR_BIT(GPIOB_ODR,Copy_u8Pin);	break;
					case GPIO_u8_PORTC:		CLR_BIT(GPIOC_ODR,Copy_u8Pin);	break;
					default : Local_u8ErrorState=2 ;				break;
				}
			}
		}
	}
	else Local_u8ErrorState=1;
	return Local_u8ErrorState ;
	
}
u8 GPIO_u8GetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 * Copy_pu8Value)
{
	
	u8 Local_u8ErrorState= 0 ;
	if (Copy_u8Pin<=GPIO_u8_PIN15 ){
		if(((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN13))||((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN14)))
		{
			Local_u8ErrorState=4;
			return Local_u8ErrorState;
		}
		if(((Copy_u8Port ==GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN3))||((Copy_u8Port == GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN4)))
		{
			Local_u8ErrorState=4;
			return Local_u8ErrorState;
		}
		else
		{
			
			
			switch(Copy_u8Port)
			{
				case GPIO_u8_PORTA	: *Copy_pu8Value=	GET_BIT(GPIOA_IDR,Copy_u8Pin);	break;
				case GPIO_u8_PORTB	: *Copy_pu8Value=	GET_BIT(GPIOB_IDR,Copy_u8Pin);	break;
				case GPIO_u8_PORTC	: *Copy_pu8Value=	GET_BIT(GPIOC_IDR,Copy_u8Pin);	break;
				default : Local_u8ErrorState=2 ;				break;
			}
		}
		
	}
	else Local_u8ErrorState=1;
	return Local_u8ErrorState ;
}

u8	GPIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState= 0 ;
	

	if(Copy_u8Direction==GPIO_u8_PIN_INPUT)
	{
		switch (Copy_u8Port)
		{
			case GPIO_u8_PORTA  :
			{
				// to make sure that pin 13 and 14 are at reset value
				
				GPIOA_MODER=GPIO_u32_PORT_INPUT ;
				CLR_BIT(GPIOA_MODER,26);
				CLR_BIT(GPIOA_MODER,27);
				CLR_BIT(GPIOA_MODER,28);
				CLR_BIT(GPIOA_MODER,29);

				break;
			}
			case GPIO_u8_PORTB  :
			{// to make sure that pin 3 and 4 are at reset value
				GPIOB_MODER=GPIO_u32_PORT_INPUT ;
				CLR_BIT(GPIOB_MODER,6);
				CLR_BIT(GPIOB_MODER,7);
				SET_BIT(GPIOB_MODER,8);
				CLR_BIT(GPIOB_MODER,9);
				break;
			}
			case GPIO_u8_PORTC :
			{
				GPIOC_MODER=GPIO_u32_PORT_INPUT ;
				break;
			}
			
			default: Local_u8ErrorState=2;
		}
	}
	else if (Copy_u8Direction==GPIO_u8_PIN_OUTPUT)
	{
		switch (Copy_u8Port)
		{
			case GPIO_u8_PORTA  :
			{
				GPIOA_MODER=GPIO_u32_PORT_OUTPUT ;
				CLR_BIT(GPIOA_MODER,26);
				CLR_BIT(GPIOA_MODER,27);
				CLR_BIT(GPIOA_MODER,28);
				CLR_BIT(GPIOA_MODER,29);
				break;
			}
			case GPIO_u8_PORTB  :
			{
				GPIOB_MODER=GPIO_u32_PORT_OUTPUT ;
				CLR_BIT(GPIOB_MODER,6);
				CLR_BIT(GPIOB_MODER,7);
				SET_BIT(GPIOB_MODER,8);
				CLR_BIT(GPIOB_MODER,9);
				break;
			}
			case GPIO_u8_PORTC :
			{
				GPIOC_MODER=GPIO_u32_PORT_OUTPUT ;
				break;
			}
			
			default: Local_u8ErrorState=2;
		}
	}
	else if (Copy_u8Direction==GPIO_u8_PIN_ALTERNATE_MODE)
	{
		switch (Copy_u8Port)
		{
			case GPIO_u8_PORTA  :
			{
				GPIOA_MODER=GPIO_u8_PIN_ALTERNATE_MODE ;
				CLR_BIT(GPIOA_MODER,26);
				CLR_BIT(GPIOA_MODER,27);
				CLR_BIT(GPIOA_MODER,28);
				CLR_BIT(GPIOA_MODER,29);
				break;
			}
			case GPIO_u8_PORTB  :
			{
				GPIOB_MODER=GPIO_u8_PIN_ALTERNATE_MODE ;
				CLR_BIT(GPIOB_MODER,6);
				CLR_BIT(GPIOB_MODER,7);
				SET_BIT(GPIOB_MODER,8);
				CLR_BIT(GPIOB_MODER,9);
				break;
			}
			case GPIO_u8_PORTC :
			{
				GPIOC_MODER=GPIO_u8_PIN_ALTERNATE_MODE ;
				break;
			}
			
			default: Local_u8ErrorState=2;
		}
	}
	else if (Copy_u8Direction==GPIO_u8_PIN_ANALOG_MODE	)
	{
		switch (Copy_u8Port)
		{
			case GPIO_u8_PORTA  :
			{
				GPIOA_MODER=GPIO_u8_PIN_ANALOG_MODE ;
				CLR_BIT(GPIOA_MODER,26);
				CLR_BIT(GPIOA_MODER,27);
				CLR_BIT(GPIOA_MODER,28);
				CLR_BIT(GPIOA_MODER,29);
				break;
			}
			case GPIO_u8_PORTB  :
			{
				GPIOB_MODER=GPIO_u8_PIN_ANALOG_MODE ;
				CLR_BIT(GPIOB_MODER,6);
				CLR_BIT(GPIOB_MODER,7);
				SET_BIT(GPIOB_MODER,8);
				CLR_BIT(GPIOB_MODER,9);
				break;
			}
			case GPIO_u8_PORTC :
			{
				GPIOC_MODER=GPIO_u8_PIN_ANALOG_MODE ;
				break;
			}
			
			default: Local_u8ErrorState=2;
		}
	}
	else 	Local_u8ErrorState=3;
	
	
	
	return Local_u8ErrorState ;
}
u8	GPIO_u8SetPortValue (u8 Copy_u8Port  , u16 Copy_u16Value)
{
	u8 Local_u8ErrorState= 0 ;
	
	
	
	
	switch(Copy_u8Port)
	{
		case GPIO_u8_PORTA	:
		{
			CLR_BIT(Copy_u16Value,26);
			CLR_BIT(Copy_u16Value,27);
			CLR_BIT(Copy_u16Value,28);
			CLR_BIT(Copy_u16Value,29);
			GPIOA_ODR= Copy_u16Value;
			break;
		}
		case GPIO_u8_PORTB	:
		{
			CLR_BIT(Copy_u16Value,6);
			CLR_BIT(Copy_u16Value,7);
			CLR_BIT(Copy_u16Value,8);
			CLR_BIT(Copy_u16Value,9);
			GPIOB_ODR= Copy_u16Value;
			break;
		}
		case GPIO_u8_PORTC	:	GPIOC_ODR= Copy_u16Value; 	break;
		default : Local_u8ErrorState=2 ;
		
	}
	

	return Local_u8ErrorState ;
}
u8 GPIO_u8GetPortValue (u8 Copy_u8Port , u16 *  Copy_pu16Value)
{
	u8 Local_u8ErrorState=0 ;
	switch(Copy_u8Port)
	{
		case GPIO_u8_PORTA	: *Copy_pu16Value=GPIOA_IDR	;	break;
		case GPIO_u8_PORTB	: *Copy_pu16Value=GPIOB_IDR	;	break;
		case GPIO_u8_PORTC	: *Copy_pu16Value=GPIOC_IDR	;	break;
		default : Local_u8ErrorState=2 ;				break;
	}
	return Local_u8ErrorState;;
}

u8 GPIO_u8SetOutputPinType (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type)
{
	u8 Local_u8ErrorState= 0 ;
	// THE BITS THAT WILL BE ACCESSED TO SET THE DIRECTION IN THE MODE REGISTER TO SET A CERTIAN PIN
	
	if(((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN13))||((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN14)))
	{
		Local_u8ErrorState=4;
		return Local_u8ErrorState;
	}
	if(((Copy_u8Port ==GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN3))||((Copy_u8Port == GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN4)))
	{
		Local_u8ErrorState=4;
		return Local_u8ErrorState;
	}
	if(Copy_u8Pin<=GPIO_u8_PIN15)
	{
		if(Copy_u8Type==GPIO_PIN_PUSH_PULL)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					
					CLR_BIT(GPIOA_OTYPER,Copy_u8Pin);
					
					
					
					break;
				}
				case GPIO_u8_PORTB  :
				{
					CLR_BIT(GPIOB_OTYPER,Copy_u8Pin);
					
					break;
				}
				case GPIO_u8_PORTC :
				{
					CLR_BIT(GPIOC_OTYPER,Copy_u8Pin);
					
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
			
		}
		else if (Copy_u8Type==GPIO_PIN_OPEN_DRAIN)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					SET_BIT(GPIOA_OTYPER,Copy_u8Pin);
					
					break;
				}
				case GPIO_u8_PORTB  :
				{
					SET_BIT(GPIOB_OTYPER,Copy_u8Pin);
					
					break;
				}
				case GPIO_u8_PORTC :
				{
					SET_BIT(GPIOC_OTYPER,Copy_u8Pin);
					
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
			
		}
		
		
		else 	Local_u8ErrorState=3;
		
	}
	else Local_u8ErrorState=1 ;
	
	return Local_u8ErrorState ;
}
u8 GPIO_u8SetIntputPinType (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type)
{
	u8 Local_u8ErrorState= 0 ;
	// THE BITS THAT WILL BE ACCESSED TO SET THE DIRECTION IN THE MODE REGISTER TO SET A CERTIAN PIN
	u8 Local_u8Config_Bit1=Copy_u8Pin*2;
	u8 Local_u8Config_Bit2=(Copy_u8Pin*2)+1;
	if(((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN13))||((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN14)))
	{
		Local_u8ErrorState=4;
		return Local_u8ErrorState;
	}
	if(((Copy_u8Port ==GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN3))||((Copy_u8Port == GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN4)))
	{
		Local_u8ErrorState=4;
		return Local_u8ErrorState;
	}
	if(Copy_u8Pin<=GPIO_u8_PIN15)
	{
		if(Copy_u8Type==GPIO_PIN_NO_PULL_UP_PULL_DOWN)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					
					CLR_BIT(GPIOA_PUPDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOA_PUPDR,Local_u8Config_Bit2);
					
					
					break;
				}
				case GPIO_u8_PORTB  :
				{
					CLR_BIT(GPIOB_PUPDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOB_PUPDR,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTC :
				{
					CLR_BIT(GPIOC_PUPDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOC_PUPDR,Local_u8Config_Bit2);
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
			
		}
		else if (Copy_u8Type==GPIO_PIN_PULL_UP)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					SET_BIT(GPIOA_PUPDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOA_PUPDR,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTB  :
				{
					SET_BIT(GPIOB_PUPDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOB_PUPDR,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTC :
				{
					SET_BIT(GPIOC_PUPDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOC_PUPDR,Local_u8Config_Bit2);
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
			
		}
		else if (Copy_u8Type==GPIO_PIN_PULL_DOWN)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					SET_BIT(GPIOA_PUPDR,Local_u8Config_Bit2);
					CLR_BIT(GPIOA_PUPDR,Local_u8Config_Bit1);
					break;
				}
				case GPIO_u8_PORTB  :
				{
					SET_BIT(GPIOB_PUPDR,Local_u8Config_Bit2);
					CLR_BIT(GPIOB_PUPDR,Local_u8Config_Bit1);
					break;
				}
				case GPIO_u8_PORTC :
				{
					SET_BIT(GPIOC_PUPDR,Local_u8Config_Bit2);
					CLR_BIT(GPIOC_PUPDR,Local_u8Config_Bit1);
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
		}
		
		else 	Local_u8ErrorState=3;
		
	}
	else Local_u8ErrorState=1 ;
	
	return Local_u8ErrorState ;
}
u8 GPIO_u8SetPinSpeed	   (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Speed)
{
	u8 Local_u8ErrorState= 0 ;
	// THE BITS THAT WILL BE ACCESSED TO SET THE DIRECTION IN THE MODE REGISTER TO SET A CERTIAN PIN
	u8 Local_u8Config_Bit1=Copy_u8Pin*2;
	u8 Local_u8Config_Bit2=(Copy_u8Pin*2)+1;
	if(((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN13))||((Copy_u8Port == GPIO_u8_PORTA)&&(Copy_u8Pin == GPIO_u8_PIN14)))
	{
		Local_u8ErrorState=4;
		return Local_u8ErrorState;
	}
	if(((Copy_u8Port ==GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN3))||((Copy_u8Port == GPIO_u8_PORTB)&&(Copy_u8Pin == GPIO_u8_PIN4)))
	{
		Local_u8ErrorState=4;
		return Local_u8ErrorState;
	}
	if(Copy_u8Pin<=GPIO_u8_PIN15)
	{
		if(Copy_u8Speed==GPIO_PIN_LOW_SPEED)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					
					CLR_BIT(GPIOA_OSPEEDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOA_OSPEEDR,Local_u8Config_Bit2);
					
					
					break;
				}
				case GPIO_u8_PORTB  :
				{
					CLR_BIT(GPIOB_OSPEEDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOB_OSPEEDR,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTC :
				{
					CLR_BIT(GPIOC_OSPEEDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOC_OSPEEDR,Local_u8Config_Bit2);
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
		}
		else if (Copy_u8Speed==GPIO_PIN_MEDIUM_SPEED)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					SET_BIT(GPIOA_OSPEEDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOA_OSPEEDR,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTB  :
				{
					SET_BIT(GPIOB_OSPEEDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOB_OSPEEDR,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTC :
				{
					SET_BIT(GPIOC_OSPEEDR,Local_u8Config_Bit1);
					CLR_BIT(GPIOC_OSPEEDR,Local_u8Config_Bit2);
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
		}
		else if (Copy_u8Speed==GPIO_PIN_HIGH_SPEED)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					SET_BIT(GPIOA_OSPEEDR,Local_u8Config_Bit2);
					CLR_BIT(GPIOA_OSPEEDR,Local_u8Config_Bit1);
					break;
				}
				case GPIO_u8_PORTB  :
				{
					SET_BIT(GPIOB_OSPEEDR,Local_u8Config_Bit2);
					CLR_BIT(GPIOB_OSPEEDR,Local_u8Config_Bit1);
					break;
				}
				case GPIO_u8_PORTC :
				{
					SET_BIT(GPIOC_OSPEEDR,Local_u8Config_Bit2);
					CLR_BIT(GPIOC_OSPEEDR,Local_u8Config_Bit1);
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
		}
		else if (Copy_u8Speed==GPIO_PIN_VERY_HIGH_SPEED	)
		{
			switch (Copy_u8Port)
			{
				case GPIO_u8_PORTA  :
				{
					SET_BIT(GPIOA_OSPEEDR,Local_u8Config_Bit1);
					SET_BIT(GPIOA_OSPEEDR,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTB  :
				{
					SET_BIT(GPIOB_OSPEEDR,Local_u8Config_Bit1);
					SET_BIT(GPIOB_OSPEEDR,Local_u8Config_Bit2);
					break;
				}
				case GPIO_u8_PORTC :
				{
					SET_BIT(GPIOC_OSPEEDR,Local_u8Config_Bit1);
					SET_BIT(GPIOC_OSPEEDR,Local_u8Config_Bit2);
					break;
				}
				
				default: Local_u8ErrorState=2;
			}
		}
		else 	Local_u8ErrorState=3;
		
	}
	else Local_u8ErrorState=1 ;
	
	return Local_u8ErrorState ;
}


