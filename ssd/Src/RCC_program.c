/***************************************************************/
/******************       Author : Ahmad Bassiony *************/
/***********************   Layer : MCAL   **********************/
/************************  Version : 1.00  *********************/
/************************** SWC :  RCC  ************************/
/***************************************************************/
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_register.h"

#include "RCC_config.h"



void RCC_voidSysClockInit(void)
{
	#if(Enable_HSI)
	RCC_EnableHSI();
#elif(Enable_HSE)
	RCC_EnableHSE();
#elif(Enable_PLL)
	RCC_EnablePLL(PLL_CLK_Source, PLL_Multiplication_Factor);
#else
	#error "invalid Config"
#endif	
}
void RCC_EnableHSI(void){
	SET_BIT(RCC_CR, RCC_CR_HSION); //Enable HSI.
	while(GET_BIT(RCC_CR, RCC_CR_HSIRDY)); //Polling until HSI is ready.
	SET_BIT(RCC_CIR, RCC_CIR_HSIRDYC); //Clear HSI ready flag.
	CLR_BIT(RCC_CFGR, RCC_CFGR_SW0); //Select HSI as system clock.
	CLR_BIT(RCC_CFGR, RCC_CFGR_SW1); //Select HSI as system clock.
}

void RCC_EnableHSE(void){
	SET_BIT(RCC_CR, RCC_CR_HSEON); //Enable HSE.
	while(GET_BIT(RCC_CR, RCC_CR_HSERDY)); //Polling until HSE is ready.
	SET_BIT(RCC_CIR, RCC_CIR_HSERDYC); //Clear HSE ready flag.
	SET_BIT(RCC_CFGR, RCC_CFGR_SW0); //Select HSE as system clock.
	CLR_BIT(RCC_CFGR, RCC_CFGR_SW1); //Select HSE as system clock.
}




void	RCC_voidEnablePerClk(u8 Bus,u8 Per)
{
	/*		Range Check			*/
	if(Per < 32)
	{
		switch(Bus)
		{
			case	RCC_AHB1 : SET_BIT(RCC_AHB1ENR,Per);
			case	RCC_AHB2 : SET_BIT(RCC_AHB2ENR,Per);
			case	RCC_APB1 : SET_BIT(RCC_APB1ENR,Per);
			case	RCC_APB2 : SET_BIT(RCC_APB2ENR,Per);
		}
	}
	else
	{			/*		OUT OF RANGE		*/		}
}
void	RCC_voidDisablePerClk(u8 Bus,u8 Per)
{
	/*		Range Check			*/
	if(Per < 32)
	{
		switch(Bus)
		{
			case	RCC_AHB1 : CLR_BIT(RCC_AHB1ENR,Per);
			case	RCC_AHB2 : CLR_BIT(RCC_AHB2ENR,Per);
			case	RCC_APB1 : CLR_BIT(RCC_APB1ENR,Per);
			case	RCC_APB2 : CLR_BIT(RCC_APB2ENR,Per);
		}
	}
	else
	{			/*		OUT OF RANGE		*/		}	
}
