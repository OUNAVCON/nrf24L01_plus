/* ###################################################################
 **     Filename    : mqx_tasks.c
 **     Project     : Test
 **     Processor   : MK22FN512VLH12
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2017-10-12, 12:40, # CodeGen: 1
 **     Abstract    :
 **         This is user's event module.
 **         Put your event handler code here.
 **     Contents    :
 **         task_idle - void task_idle(uint32_t task_init_data);
 **
 ** ###################################################################*/
/*!
 ** @file mqx_tasks.c
 ** @version 01.00
 ** @brief
 **         This is user's event module.
 **         Put your event handler code here.
 */
/*!
 **  @addtogroup mqx_tasks_module mqx_tasks module documentation
 **  @{
 */
/* MODULE mqx_tasks */

#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "mqx_inc.h"
/*
 ** ===================================================================
 **     Event       :  task_idle (module mqx_tasks)
 **
 **     Component   :  Task1 [MQXLite_task]
 **     Description :
 **         MQX task routine. The routine is generated into mqx_tasks.c
 **         file.
 **     Parameters  :
 **         NAME            - DESCRIPTION
 **         task_init_data  -
 **     Returns     : Nothing
 ** ===================================================================
 */
void task_idle(uint32_t task_init_data) {
	while(1){
		LED_GREEN_ToggleFieldBits(LED_GREEN_DeviceData,LED_GREEN_FIELD_0_PIN_0,LED_GREEN_GREEN_MASK);
		_time_delay_ticks(5);
	}
}

/*
** ===================================================================
**     Event       :  NRF_task (module mqx_tasks)
**
**     Component   :  Task2 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/
void NRF_task(uint32_t task_init_data)
{
	uint8_t data[8];
	int counter = 0;
	LDD_TDeviceData* nrf24L01_Struct;
	LDD_TDeviceData* SM1_Device;
	//Enable SPI chip.
	SM1_Device = SM1_Init(NULL);

	nrf24L01_Struct = nrf24l01_Init(NULL);
//  nrf24l01_SetFieldValue(nrf24L01_Struct, Enable, nrf24l01_Enable_MASK); //Set the bit to on.
	nrf24l01_SetFieldBits(nrf24L01_Struct, Enable, nrf24l01_Enable_MASK);
	while (1) {
		counter++;
		SM1_SendBlock(SM1_Device,data, 1);
		SM1_ReceiveBlock(SM1_Device,data, 1);
		_time_delay_ticks(5);

	}
}

/* END mqx_tasks */

#ifdef __cplusplus
} /* extern "C" */
#endif 

/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.5 [05.21]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
