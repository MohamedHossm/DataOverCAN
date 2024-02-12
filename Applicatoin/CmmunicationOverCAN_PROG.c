/*****************************************************************************/
/* Author         : Mohamed Hoasm                                            */
/* Date           : 11/2/2022                                                */
/* Version        : 1.0                                                      */
/*sw              : CmmunicationOverCAN                                      */
/*****************************************************************************/
#include <stdio.h>

#include "STD_TYPES.h"

#include "RCC_Interface.h"
#include "NVIC_Interface.h"

#include "GPIO_Interface.h"
#include "UART_Interface.h"
#include "CAN_interface.h"
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

	RCC_voidEnablePeriphralCLK(APB1_CANEN);

	// NVIC Enable UART interrupt
	NVIC_u8Set_EN_IRQ(INTERRUPT_USART1);

	//init  GPIO
	GPIO_u8Init();
	//CAN init
	CAN_voidInit();
	CAN_FilterConfig();
	CAN_voidStart();
	//init  UART1
	UART1_voidInit();
	UART1_u8EnterruptCallBackRX(CommApp_voidUart_ISRFunction);
	UART1_u8EnterruptEnRX();

	//init  UART2  for testing
	UART2_voidInit();

}

void CommApp_voidRunnable(void) {

	if (CommApp_enuSerialDataCheck() == COM_TRUE) {

		CommApp_enuCANSend(CommApp_voidReadClearUartVar());

	} else {
		// do nothing for now
	}
	if (CommApp_enuCANDataCheck() == COM_TRUE) {
		// value for test
		CommApp_enuSerialSend(15);

	} else {
		// do nothing for now
	}
}

CommAppError_t CommApp_enuCANDataCheck() {

	// void CAN_RX(void) ;
	return COM_TRUE;
}

/*****************************************************************************/
/*void CAN_RX(void) {
 CAN_RxHeaderTypeDef Rx_header;
 //while(CAN_voidRXPending(CAN_RX_FIFO0) == 0);
 u8 DATA[5];
 CAN_voidGetRxMsg(CAN_RX_FIFO0, &Rx_header, DATA);
 }
 void CAN_TX(void) {

 }
 */
u16 Std_id_High(u16 local_u16Std_Id) {
	return (local_u16Std_Id << 5);
}
void CAN_FilterConfig(void) {
	CAN_FilterTypeDef CAN_FilterInit;
	CAN_FilterInit.FilterActivation = ENABLE;
	CAN_FilterInit.FilterBank = 0;
	CAN_FilterInit.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	CAN_FilterInit.FilterIdHigh = Std_id_High(0x65d);
	CAN_FilterInit.FilterIdLow = 0x0000;
	CAN_FilterInit.FilterMaskIdHigh = 0x0000;
	CAN_FilterInit.FilterMaskIdLow = 0x0000;
	CAN_FilterInit.FilterMode = CAN_FILTERMODE_IDMASK;
	CAN_FilterInit.FilterScale = CAN_FILTERSCALE_32BIT;

	CAN_voidConfigFilter(&CAN_FilterInit);
}

CommAppError_t CommApp_enuCANSend(u8 Copy_u8DataSend) {
	CommAppError_t Local_enuErorr = COM_TRUE;
//for testing
	UART2_u8SendByteBusyw8(Copy_u8DataSend);
	CAN_TxHeaderTypeDef tx_header;
	tx_header.StdId = 0x65d;
	tx_header.IDE = CAN_ID_STD;
	tx_header.RTR = CAN_RTR_DATA;
	tx_header.DLC = 1;
	tx_header.TransmitGlobalTime = DISABLE;
	u8 DATA[1] = { Copy_u8DataSend };
	CAN_voidAddTxMsg(&tx_header, DATA);

	return Local_enuErorr;
}

/**************************************************************************************/

CommAppError_t CommApp_enuSerialDataCheck() {
	CommAppError_t Local_enuErorr = COM_TRUE;
	if (Global_UartDataRecive == 0) {
		Local_enuErorr = COM_FALSE;
	} else {
		// do nothing
	}
	return Local_enuErorr;
}

CommAppError_t CommApp_enuSerialSend(u8 Copy_u8DataSend) {
	CommAppError_t Local_enuErorr = COM_TRUE;

	UART1_u8SendByteBusyw8(Copy_u8DataSend);
	return Local_enuErorr;

}
void CommApp_voidClearUartVar() {
	Global_UartDataRecive = 0;
}
u8 CommApp_voidReadUartVar() {
	return Global_UartDataRecive;
}
u8 CommApp_voidReadClearUartVar() {
	u8 local_temp = Global_UartDataRecive;
	Global_UartDataRecive = 0;
	return local_temp;
}

void CommApp_voidUart_ISRFunction() {
	UART1_u8RecieveByte(&Global_UartDataRecive);
}
