#include "TIM2setUp.h"
#include "sysClockConfig.h"

void TIM2_config(void){
	
	RCC->APB1ENR |= (1 << 0);   //ENABLE TIM2 PERIPHERAL CLOCK
	
	TIM2->PSC = 79;     //SET TIM2 FREQUENCY TO 1 MHZ (80000000/(79+1)) USING PRESCALER
	
	TIM2->ARR = (uint32_t)500000;   //SET COUNTER RESET TIME
	
	//TIM2->CNT = 0;    //SET TIM2 COUNTER TO 0
	
	TIM2->DIER |= TIM_DIER_UIE;   //(1 << 0) ENABLE TIM2 INTERRUPT
	
	TIM2->SR &= ~TIM_SR_UIF;  //CLEAR TIM2 INTERRUPT STATUS
	
	NVIC_EnableIRQ(TIM2_IRQn);  //ENABLE GLOBAL NVIC INTERRUPTS FOR TIM2
	
	TIM2->CR1 = TIM_CR1_CEN;  // |= (1 << 0);  //ENABLE COUNTER FOR TIM2
	}