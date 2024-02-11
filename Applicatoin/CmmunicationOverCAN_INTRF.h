/*****************************************************************************/
/* Author         : Mohamed Hoasm                                            */
/* Date           : 11/2/2022                                                */
/* Version        : 1.0                                                      */
/*sw              : CmmunicationOverCAN                                      */
/*****************************************************************************/

#ifndef __CmmunicationOverCAN_INTERF_
#define __CmmunicationOverCAN_INTERF_

typedef enum{
	COM_TRUE=0,
	COM_FALSE ,

}CommAppError_t;


CommAppError_t  CommApp_enuSerialDataCheck();
CommAppError_t CommApp_enuDataSend(u8 Copy_u8DataSend);

// Uart data interfaces
void CommApp_voidClearUartVar(void);
u8 CommApp_voidReadUartVar(void);
u8 CommApp_voidReadClearUartVar(void);
//-------------------------------------------------------
void CommApp_voidInit(void);
void CommApp_voidRunnable(void);
void CommApp_voidUart_ISRFunction(void);
#endif  //__CmmunicationOverCAN_INTERF_

