#include <stdint.h>
#include "reg.h"
#include "blink.h"

int main(void)
{
	//RCC Enable GPIOA
	SET_BIT(RCC_BASE + RCC_AHB1ENR_OFFSET, GPIO_EN_BIT(GPIO_PORTA));

	//GPIO Configurations
	/*
	PA0 GPIOA0
	GP input mode -> MODER(0) = 00;
	PP -> OTYPER(0) = ignore;
	Speed -> OSPEEDR(0) = ignore;
	PU|PD -> PUPDR(0) = 00;
	*/
	//MODER = 00 => General purpose output mode
	CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_MODER_OFFSET, MODERy_1_BIT(0));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_MODER_OFFSET, MODERy_0_BIT(0));
	//PUPDR led pin = 00 => No pull-up, pull-down
	CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_PUPDR_OFFSET, PUPDRy_1_BIT(0));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_PUPDR_OFFSET, PUPDRy_0_BIT(0));
	
	//RCC Enable SYSCFG
	SET_BIT(RCC_BASE + RCC_APB2ENR_OFFSET, SYSCFGEN_BIT);

	//SYSCFG Configurations
	CLEAR_BIT(SYSCFG_BASE + SYSCFG_EXTICR1_OFFSET, EXTI0_0_BIT);
	CLEAR_BIT(SYSCFG_BASE + SYSCFG_EXTICR1_OFFSET, 1);
	CLEAR_BIT(SYSCFG_BASE + SYSCFG_EXTICR1_OFFSET, 2);
	CLEAR_BIT(SYSCFG_BASE + SYSCFG_EXTICR1_OFFSET, EXTI0_3_BIT);

	//EXTI Configurations
	/*
	enable interrupt -> EXTI_IMR(0) = 0;
	rising trigger -> EXTI_RTSP(0) = 1;
	falling trigger -> EXTI_FTSR(0) = 0;
	pending register -> manual set to 1 if interrupt happened;
	*/
	SET_BIT(EXTI_BASE + EXTI_IMR_OFFSET, 0);
	SET_BIT(EXTI_BASE + EXTI_RTSR_OFFSET, 0);
	CLEAR_BIT(EXTI_BASE + EXTI_FTSR_OFFSET, 0);

	//NVIC Configurations
	SET_BIT(NVIC_ISER_BASE + NVIC_ISERn_OFFSET(0), 6); //IRQ6

	blink(LED_BLUE);
}

void exti0_handler(void)
{
	blink_count(LED_ORANGE, 10);

	//clear pending
	SET_BIT(EXTI_BASE + EXTI_PR_OFFSET, 0);
}
