/*****************************************************************************/
/* Auther         : Mohamed Hoasm                                            */
/* Date           : 11/2/2022                                                */
/* Version        : 1.0                                                      */
/*sw              : Communicatin OVER CAN                                    */
/*****************************************************************************/
#include "STD_TYPES.h"
#include "CmmunicationOverCAN_INTRF.h"

int main() {
	CommApp_voidInit();

	while (1) {
		CommApp_voidRunnable();
	}
	return 0;
}
