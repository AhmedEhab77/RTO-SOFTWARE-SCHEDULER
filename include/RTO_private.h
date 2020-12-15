/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/
#ifndef   _RTO_PRIVATE_H_
#define   _RTO_PRIVATE_H_

typedef  struct{
	u16 Periodicity;
	u16 FirstDelay;
	void(*TaskHandler)(void);
}TCB;

static void   RTO_VidSchedulerAlgorithm(void);


#endif
