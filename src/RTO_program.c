/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RTO_interface.h"
#include "RTO_private.h"
#include "RTO_config.h"
#include "SYSTICK_interface.h"


static TCB Array_of_tasks[MAX_NUM_OF_TASKS];
static u8  Array_of_flags[MAX_NUM_OF_TASKS];


void   RTO_VidCreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,u16 Copy_u16FirstDelay,void(*Copy_LpFunction)(void) )
{
	if((Copy_LpFunction != NULL) && (Copy_u8Priority < MAX_NUM_OF_TASKS) && (Array_of_flags[Copy_u8Priority]==0) )
	{
		/*********MAKING THE ENTERED PERIODICITY IN TCB***********/
		Array_of_tasks[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
		/*********MAKING THE ENTERED FIRST DELAY IN TCB***********/
		Array_of_tasks[Copy_u8Priority].FirstDelay =Copy_u16FirstDelay;
		/*********MAKING THE ENTERED TASK FUNCTION IN TCB***********/
		Array_of_tasks[Copy_u8Priority].TaskHandler =Copy_LpFunction;
		/****************INCREMENT THE FLAG*****************************/
		Array_of_flags[Copy_u8Priority]=1;
	}
}

static void   RTO_VidSchedulerAlgorithm(void)
{
	for(u8 Local_u8Counter=0;Local_u8Counter < MAX_NUM_OF_TASKS;Local_u8Counter++)
	{
		if(Array_of_tasks[Local_u8Counter].FirstDelay == 0)
		{
			    /************CALLING TASK FUNCTION WHEN FIRST DELAY =0**********/
			Array_of_tasks[Local_u8Counter].TaskHandler();
   /************GIVING (PERIODICITY VALUE -1) TO  FIRST DELAY TO REPEAT THE TASK IN THE GIVEN PERIODIC TIME**********/
			Array_of_tasks[Local_u8Counter].FirstDelay=Array_of_tasks[Local_u8Counter].Periodicity-1;
		}
		else
		{
			/************DECREMENT THE FIRST DELAY ONE STEP TO REACH THE CALLING FUNCTION STATE**********/
			Array_of_tasks[Local_u8Counter].FirstDelay--;
		}
	}
}

void   RTO_VidStartScheduler(void)
{
	/****************SysTick Init***************/
	MSysTick_VidInit();
	/*************SysTick Interrupt Enable****/
	MSysTick_VidSetIntervalPeriodic(RTO_TICKTIME,RTO_VidSchedulerAlgorithm);	
}
