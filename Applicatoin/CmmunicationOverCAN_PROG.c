/*****************************************************************************/
/* Author         : Mohamed Hoasm                                            */
/* Date           : 11/2/2022                                                */
/* Version        : 1.0                                                      */
/*sw              : CmmunicationOverCAN                                      */
/*****************************************************************************/

#include "STD_TYPES.h"

#include "RCC_Interface.h"
#include "NVIC_Interface.h"

#include "GPIO_Interface.h"
#include "UART_Interface.h"
/****************************************************************/
#include "Delay.h"
/*****************************************************************/
#include "CmmunicationOverCAN_CONF.h"
#include "CmmunicationOverCAN_PRIV.h"
#include "CmmunicationOverCAN_INTRF.h"

volatile static u8 Global_UartDataRecive;

void CommApp_voidInit(void) {
	Global_UartDataRecive = 0;
	//RCC init clk HSE
	RCC_voidInitSystemClock();
	//Enable RCC For GPIO , UART1 and CAN
	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);

	RCC_voidEnablePeriphralCLK(APB2_USART1EN);

	RCC_voidEnablePeriphralCLK(APB1_USART2EN);

	//RCC_voidEnablePeriphralCLK(APB1_CANEN);

	// NVIC Enable UART interrupt
	NVIC_u8Set_EN_IRQ(INTERRUPT_USART1);

	//init  GPIO
	GPIO_u8Init();

	//init  UART1
	UART1_voidInit();
	UART1_u8EnterruptCallBackRX(CommApp_voidUart_ISRFunction);
	UART1_u8EnterruptEnRX();

	//init  UART2  for testing
	UART2_voidInit();


}

void CommApp_voidRunnable(void) {

	if (CommApp_enuSerialDataCheck() == COM_TRUE) {

	CommApp_enuDataSend(CommApp_voidReadClearUartVar());

	} else {
		// do nothing for now
	}
}

CommAppError_t CommApp_enuSerialDataCheck() {
	CommAppError_t Local_enuErorr = COM_TRUE;
	if (Global_UartDataRecive == 0) {
		Local_enuErorr =COM_FALSE;
	} else {
		// do nothing
	}
	return Local_enuErorr;
}
CommAppError_t CommApp_enuDataSend(u8 Copy_u8DataSend) {
	CommAppError_t Local_enuErorr = COM_TRUE;

	UART2_u8SendByteBusyw8(Copy_u8DataSend);

	return Local_enuErorr;
}

void CommApp_voidClearUartVar(){
	Global_UartDataRecive = 0 ;
}
u8 CommApp_voidReadUartVar(){
	return Global_UartDataRecive;
}
u8 CommApp_voidReadClearUartVar(){
	u8 local_temp = Global_UartDataRecive ;
	Global_UartDataRecive = 0 ;
	return local_temp;
}

void CommApp_voidUart_ISRFunction() {
	UART1_u8RecieveByte(&Global_UartDataRecive);
}
