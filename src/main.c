/*
 * main.c
 *
 *  Created on: Dec 15, 2020
 *      Author: Ahmed Ehab
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_macros.h"
#include "RCC_interface.h"
#include "RCC_macros.h"
#include "SYSTICK_interface.h"
#include "RTO_interface.h"

void App_VidTask1(void);
void App_VidTask2(void);
void App_VidTask3(void);

int main (void)
{
	 /*******RCC INIT*******/
	MRCC_VidInit();
	/******ENABLE CLOCK********/
	MRCC_VidEnableClock(RCC_APB2,GPIOA_RCC);
	/*******SET PINS DIRCTIONS*******/
	MGPIO_VidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN0,GPIO_OUTPUT_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN1,GPIO_OUTPUT_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN2,GPIO_OUTPUT_10MHZ_PP);
	/****ALLOCATE TCBs IN MEMORY**********/
	RTO_VidCreateTask(0,1000,  0 ,App_VidTask1);
	RTO_VidCreateTask(1,2000,1000,App_VidTask2);
	RTO_VidCreateTask(2,3000,3000,App_VidTask3);
	/******START SCHEDULER*************/
	RTO_VidStartScheduler();
	while(1);
	return 0 ;
}


void App_VidTask1(void)
{
	static u8 flag=0;
	if(flag==0)
	{
		MGPIO_VidSetPinValue(GPIO_U8_A,GPIO_U8_PIN0,GPIO_U8_HIGH);
		flag=1;
	}
	else
	{
		MGPIO_VidSetPinValue(GPIO_U8_A,GPIO_U8_PIN0,GPIO_U8_LOW);
		flag=0;
	}
}

void App_VidTask2(void)
{
	static u8 flag=0;
	if(flag==0)
	{
		MGPIO_VidSetPinValue(GPIO_U8_A,GPIO_U8_PIN1,GPIO_U8_HIGH);
		flag=1;
	}
	else
	{
		MGPIO_VidSetPinValue(GPIO_U8_A,GPIO_U8_PIN1,GPIO_U8_LOW);
		flag=0;
	}
}

void App_VidTask3(void)
{
	static u8 flag=0;
	if(flag==0)
	{
		MGPIO_VidSetPinValue(GPIO_U8_A,GPIO_U8_PIN2,GPIO_U8_HIGH);
		flag=1;
	}
	else
	{
		MGPIO_VidSetPinValue(GPIO_U8_A,GPIO_U8_PIN2,GPIO_U8_LOW);
		flag=0;
	}
}
