/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/
#ifndef   _RTO_INTERFACE_H_
#define   _RTO_INTERFACE_H_




void   RTO_VidCreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,u16 Copy_u16FirstDelay,void(*Copy_LpFunction)(void) );



void   RTO_VidStartScheduler(void);


#endif
