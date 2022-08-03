#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H


#define COMMON_ANODE           0
#define COMMON_CATHODE         1
#define MINIMUM_ALLOWED_NUMBER 0
#define MAXIMUN_ALLOWED_NUMBER 9


#define  PORTA							0
#define  PORTB							1
#define  PORTC							2

#define  PIN0							0
#define  PIN1							1
#define  PIN2							2
#define  PIN3							3
#define  PIN4							4
#define  PIN5							5
#define  PIN6							6
#define  PIN7							7
#define  PIN8							8
#define  PIN9							9
#define  PIN10							10
#define  PIN11							11
#define  PIN12							12
#define  PIN13							13
#define  PIN14							14
#define  PIN15							15
typedef struct
{
	u8 SSD_u8PORT;
	u8 SSD_u8PIN0;
	u8 SSD_u8PIN1;
	u8 SSD_u8PIN2;
	u8 SSD_u8PIN3;
	u8 SSD_u8PIN4;
	u8 SSD_u8PIN5;
	u8 SSD_u8PIN6;
	u8 SSD_u8PIN7;

/*
COMMON_ANODE
COMMON_ANODE
*/

u8 SSD_u8Type;
}SSD_struct;

void  SSD_voidInit(SSD_struct* Copy_pSSD_structInfo);

void SSD_voidSetNumber(u8 Copy_u8Number, SSD_struct  *Copy_pSSD_structInfo);

#endif
