
#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"

#if 0  
void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{

  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOF, &GPIO_InitStructure);

  while(1){
		//GPIO_SetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		GPIO_SetBits(GPIOF,GPIO_Pin_9);
		GPIO_ResetBits(GPIOF,GPIO_Pin_10);
		Delay(0x7FFFFF);
  		GPIO_ResetBits(GPIOF,GPIO_Pin_9);
		//GPIO_ResetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		GPIO_SetBits(GPIOF,GPIO_Pin_10);
		Delay(0x7FFFFF);
	
	}
}
#endif

void LED_Init(void)
{
	GPIOF->MODER &= ~(3 << 2*9);
	GPIOF->MODER |= (1 << 2*9);

	GPIOF->OSPEEDR &= ~(3 << 2*9);
	GPIOF->OSPEEDR |= (2 << 2*9);
	
	GPIOF->PUPDR &= ~(3 << 2*9);
	GPIOF->PUPDR |= (1 << 2*9);
	
	GPIOF->OTYPER &= ~(1 << 9);
	GPIOF->OTYPER |= (0 << 9);

	GPIOF->ODR |= (1<<9); 

	GPIOF->MODER &= ~(3 << 2*10);
	GPIOF->MODER |= (1 << 2*10);

	GPIOF->OSPEEDR &= ~(3 << 2*10);
	GPIOF->OSPEEDR |= (2 << 2*10);
	
	GPIOF->PUPDR &= ~(3 << 2*10);
	GPIOF->PUPDR |= (1 << 2*10);
	
	GPIOF->OTYPER &= ~(1 << 10);
	GPIOF->OTYPER |= (0 << 10);

	GPIOF->ODR |= (1<<10) ;
	
}



void Clock_enable()
{
	RCC->AHB1ENR |= 0X1<<5;
}

int main()
{
	Clock_enable();
	LED_Init();
	while(1)
	{
		GPIOF->ODR &= ~(1<<9);
		//GPIOF->ODR &= ~(1<<10) ;
		delay_ms(500);

		//GPIOF->ODR |= (1<<10);
		GPIOF->ODR |= (1<<9) ;
		delay_ms(500);
	}
	
}

