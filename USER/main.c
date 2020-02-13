#include "includes.h"
#include "stm32f10x.h"
#include "led.h"
#include "usart.h"
#include "task.h"

void BSP_init(void);

int main(void)
{
	OS_ERR err;
	CPU_SR_ALLOC();
	BSP_init();
	OSInit(&err);
	OS_CRITICAL_ENTER();
	OSTaskCreate((OS_TCB *)&StartTaskTCB,
				 (CPU_CHAR *)"start task",
				 (OS_TASK_PTR)start_task,
				 (void *)0,
				 (OS_PRIO)START_TASK_PRIO,
				 (CPU_STK *)&START_TASK_STK[0],
				 (CPU_STK_SIZE)START_STK_SIZE / 10,
				 (CPU_STK_SIZE)START_STK_SIZE,
				 (OS_MSG_QTY)0,
				 (OS_TICK)0,
				 (void *)0,
				 (OS_OPT)OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR,
				 (OS_ERR *)&err);
	OS_CRITICAL_EXIT();
	OS_CPU_SysTickInit(72000000/200);//5ms OS 时基
	OSStart(&err);
    while(1);//if OSStart() error
}

void BSP_init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_init();
	uart_init(9600);
}
