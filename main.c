#include "stm32f4xx.h"
int hiz=0, d=0;
int i;
	unsigned int adc, v;
	void EXTI15_10_IRQHandler(){
EXTI->PR |= EXTI_PR_PR15;
		d++;
	 adc=ADC1->DR;
   v= ((float)adc/4095)*3; 
	USART2->DR=v;
	USART2->DR=d;
	while(!(USART2->SR & USART_SR_TXE));
	while(!(USART2->SR & USART_SR_TC));		
}

int main(){
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOAEN;
	GPIOD->MODER |= GPIO_MODER_MODER14_0 | GPIO_MODER_MODER15_0;
		RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
		GPIOA->MODER |= GPIO_MODER_MODE2_1; //Tx PA2
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_2 | GPIO_AFRL_AFSEL2_1 | GPIO_AFRL_AFSEL2_0;
	GPIOA->MODER |= GPIO_MODER_MODER6_1;
	GPIOA->AFR[0] |= GPIO_AFRL_AFRL6_1;
	GPIOA->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER0_1; 
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
{
SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
SysTick->LOAD |=  (SysTick_LOAD_RELOAD_Msk &  16000000UL);
SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	NVIC_EnableIRQ(SysTick_IRQn);
}
{
	ADC1->CR2 |= ADC_CR2_ADON; 
  ADC1->CR2 |=ADC_CR2_CONT;
  ADC1->CR2 |= ADC_CR2_SWSTART; 
}
{	
	USART2->BRR =  0x683U; //9600
	USART2->CR1 |= USART_CR1_UE;
	USART2->CR1 |= USART_CR1_TE;
}
{
EXTI->IMR |= EXTI_IMR_IM8  | EXTI_IMR_IM10| EXTI_IMR_IM15| EXTI_IMR_IM2; // KESME GIRISI PA8, PA10, PA15
	EXTI->RTSR |= EXTI_RTSR_TR8 |  EXTI_RTSR_TR10 |  EXTI_RTSR_TR15 |  EXTI_RTSR_TR2; 
	EXTI->FTSR |= EXTI_FTSR_TR8 |  EXTI_FTSR_TR10 |  EXTI_FTSR_TR15 |  EXTI_FTSR_TR2;	
	NVIC_EnableIRQ(40); //10_15 ARASI INTERRUPT
}
{
	TIM3->PSC &= ~TIM_PSC_PSC;
	TIM3->PSC |= 15U;
	
	TIM3->ARR &= ~TIM_PSC_PSC;
	TIM3->ARR |= 1000U;
	
	TIM3->CCR1 &= ~TIM_PSC_PSC;
	TIM3->CCR1 |= 0;
	
	TIM3->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;
	
	TIM3->CCER |= TIM_CCER_CC1E;
	
	TIM3->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM3_IRQn);
	
	TIM3->CR1 |= TIM_CR1_CEN;
}
	while(1){
		for(i=0;i<6;i++){
		SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD |=  (SysTick_LOAD_RELOAD_Msk &  16000000UL);
		TIM3->CCR1 &= ~TIM_PSC_PSC;
	TIM3->CCR1 |= 100U;
		}	
		for(i=0;i<6;i++){
		SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD |=  (SysTick_LOAD_RELOAD_Msk &  16000000UL);
		TIM3->CCR1 &= ~TIM_PSC_PSC;
	TIM3->CCR1 |= 200U;
		}
		for(i=0;i<6;i++){
		SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD |=  (SysTick_LOAD_RELOAD_Msk &  16000000UL);
		TIM3->CCR1 &= ~TIM_PSC_PSC;
	TIM3->CCR1 |= 300U;
		}
		for(i=0;i<6;i++){
		SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD |=  (SysTick_LOAD_RELOAD_Msk &  16000000UL);
		TIM3->CCR1 &= ~TIM_PSC_PSC;
	TIM3->CCR1 |= 400U;
		}
		for(i=0;i<6;i++){
		SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD |=  (SysTick_LOAD_RELOAD_Msk &  16000000UL);
		TIM3->CCR1 &= ~TIM_PSC_PSC;
	TIM3->CCR1 |= 500U;
		}
		for(i=0;i<6;i++){
		SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD |=  (SysTick_LOAD_RELOAD_Msk &  16000000UL);
		TIM3->CCR1 &= ~TIM_PSC_PSC;
	TIM3->CCR1 |= 600U;
		}
		for(i=0;i<6;i++){
		SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD |=  (SysTick_LOAD_RELOAD_Msk &  16000000UL);
		TIM3->CCR1 &= ~TIM_PSC_PSC;
	TIM3->CCR1 |= 700U;
		}
	for(i=0;i<6;i++){
		SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD |=  (SysTick_LOAD_RELOAD_Msk &  16000000UL);
		TIM3->CCR1 &= ~TIM_PSC_PSC;
	TIM3->CCR1 |= 800U;
	}
	for(i=0;i<6;i++){
		SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD |=  (SysTick_LOAD_RELOAD_Msk &  16000000UL);
		TIM3->CCR1 &= ~TIM_PSC_PSC;
	TIM3->CCR1 |= 900U;
	}
	for(i=0;i<6;i++){
		SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;
	SysTick->LOAD |=  (SysTick_LOAD_RELOAD_Msk &  16000000UL);
		TIM3->CCR1 &= ~TIM_PSC_PSC;
	TIM3->CCR1 |= 999U;
	}
	}
} 
