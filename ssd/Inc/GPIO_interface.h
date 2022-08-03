/***************************************************************/
/******************       Author : Ahmad Bassiony *************/
/***********************   Layer : MCAL   **********************/
/************************  Version : 1.00  *********************/
/************************** SWC : GPIO   ************************/
/***************************************************************/



#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
	
#define GPIO_u8_PIN_OUTPUT						01
#define GPIO_u8_PIN_INPUT						00
#define GPIO_u8_PIN_ALTERNATE_MODE				10
#define GPIO_u8_PIN_ANALOG_MODE					11

#define GPIO_u8_PIN_HIGH						1
#define GPIO_u8_PIN_LOW			 				0
#define GPIO_u32_PORT_OUTPUT					0x55555555
#define GPIO_u32_PORT_INPUT						0
#define GPIO_u32_PORT_ALTERNATE_MODE			0xaaaaaaaa
#define GPIO_u32_PIN_ANALOG_MODE				0xffffffff

#define GPIO_u16_PORT_HIGH						0xffff
#define GPIO_u16_PORT_LOW						0

#define GPIO_u8_PORTA							0
#define GPIO_u8_PORTB							1
#define GPIO_u8_PORTC							2


#define GPIO_u8_PIN0							0
#define GPIO_u8_PIN1							1
#define GPIO_u8_PIN2							2
#define GPIO_u8_PIN3							3
#define GPIO_u8_PIN4							4
#define GPIO_u8_PIN5							5
#define GPIO_u8_PIN6							6
#define GPIO_u8_PIN7							7
#define GPIO_u8_PIN8							8
#define GPIO_u8_PIN9							9
#define GPIO_u8_PIN10							10	
#define GPIO_u8_PIN11							11	
#define GPIO_u8_PIN12							12	
#define GPIO_u8_PIN13							13	
#define GPIO_u8_PIN14							14	
#define GPIO_u8_PIN15							15	



#define GPIO_PIN_PUSH_PULL						0
#define GPIO_PIN_OPEN_DRAIN						1
		
#define GPIO_PIN_LOW_SPEED      				0
#define GPIO_PIN_MEDIUM_SPEED           		1
#define GPIO_PIN_HIGH_SPEED           			2
#define GPIO_PIN_VERY_HIGH_SPEED          		3




#define GPIO_PIN_NO_PULL_UP_PULL_DOWN			00
#define GPIO_PIN_PULL_UP						01
#define GPIO_PIN_PULL_DOWN						10

#define DEFAULT_SPEED  				GPIO_PIN_HIGH_SPEED
#define DEFAULT_OUTPUT_TYPE  		GPIO_PIN_PUSH_PULL
#define DEFAULT_INPUT_TYPE  		GPIO_PIN_PULL_UP



//Sets the Direction of the Port 
/* op: 0-> No error
	   1-> wrong pin id
	   2-> wrong port id
	   3-> wrong mode  
	   4-> illegal pin value change
***********************************/
u8	GPIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

u8 GPIO_u8SetPortDirection(u8 Copy_u8Port ,u8 Copy_u8Direction);

u8 GPIO_u8SetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

u8	GPIO_u8SetPortValue (u8 Copy_u8Port  , u16 Copy_u16Value);

u8 GPIO_u8GetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8 * Copy_pu8Value);

u8 GPIO_u8GetPortValue (u8 Copy_u8Port , u16 *  Copy_pu16Value);
 
u8 GPIO_u8SetOutputPinType (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type);
u8 GPIO_u8SetIntputPinType (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type);
u8 GPIO_u8SetPinSpeed	   (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Speed);
#endif
