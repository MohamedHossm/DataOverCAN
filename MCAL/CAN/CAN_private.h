/*********************************************************************************/
/* Author    : Islam Abdo                                                        */
/* Version   : V01                                                               */
/* Date      : 17 OCT  2020                                                      */
/*********************************************************************************/
#ifndef CAN_PRIVATE_H
#define CAN_PRIVATE_H

typedef void (*CAN_Interrupt_Callbacks)(void);/**  CAN Operating Mode **/


#define CAN_MODE_NORMAL           			  ((u32)(0x0))                        			       /*!< Normal mode   */
#define CAN_MODE_LOOPBACK        		 	  ((u32)(0x1<<30))                					   /*!< Loopback mode BIT 30 < 0x40000000 > */
#define CAN_MODE_SILENT            			  ((u32)(0x1<<31))                					   /*!< Silent mode  BIT 31 < 0x80000000 > */
#define CAN_MODE_SILENT_LOOPBACK  			  ((u32)(CAN_MODE_LOOPBACK | CAN_MODE_SILENT)) 	 	   /*!< Loopback combined with silent mode */


/*******************   BoudRate Definition     ***********************/
enum BITRATE{CAN_50KBPS, CAN_100KBPS, CAN_125KBPS, CAN_250KBPS, CAN_500KBPS, CAN_800KBPS, CAN_1MBPS};

typedef const struct
{
	u8 TS2;
	u8 TS1;
	u8 BRP;
} CAN_BitTimingConfig;

/******** BoudRate value rating to table at web site {http://www.bittiming.can-wiki.info/}
 * 1. select ST Microelectronics bxCAN
 * 2. put freq with 36Mhz (APB1 freq)
 * 3. click Request Table						        ***********************************/
CAN_BitTimingConfig CAN_bitRateConfig[7] = {{2, 13, 45}, {2, 15, 20}, {2, 13, 18}, {2, 13, 9}, {2, 15, 4},{2, 12, 3}, {2, 15, 2}};






#endif /* CAN_PRIVATE_H */
