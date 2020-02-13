#include "led.h"

void LED_init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);	 //ʹ��PG�˿�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PC�˿�ʱ��
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				 //LED0-->PG15 �˿�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;		  			//LED0-->PC13 �˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
	//GPIO_SetBits(GPIOG,GPIO_Pin_15);		
}
