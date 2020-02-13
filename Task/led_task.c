#include "led_task.h"
#include "led.h"

//������ƿ�
OS_TCB Led0TaskTCB;
//�����ջ
CPU_STK LED0_TASK_STK[LED0_STK_SIZE];

//led0������
void led0_task(void *p_arg)
{
	OS_ERR err;
	p_arg = p_arg;
	while (1)
	{
		LED0 = 0;
		OSTimeDlyHMSM(0, 0, 1, 0, OS_OPT_TIME_HMSM_STRICT, &err);
		LED0 = 1;
		OSTimeDlyHMSM(0, 0, 1, 0, OS_OPT_TIME_HMSM_STRICT, &err);
		//printf("printf successful!!\n"); //fflush(stdout);//If there is not /n after your string,fflush() is must be needed!
	}
}
