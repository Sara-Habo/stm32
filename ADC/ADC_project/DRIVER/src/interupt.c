/*
 * interupt.c
 *
 *  Created on: May 26, 2022
 *      Author: Dell
 */
#include "stm32f4xx.h"
#include "interupt.h"


void EXTI_INIT(GPIO_TypeDef * GPIOx,char EXTI_line,char mask,char RIS ){
	//enable clock access to SYSCFG
	RCC->APB2ENR|=(1u<<14);

	int x; //index of SYSCFG_EXTICR
	int initial_bit; //initial_bit SYSCFG_EXTICR
	for(int i=0;i<4;i++){
	//get x
		if(EXTI_line==i){
			x=0;
			break;
		}
		else if(EXTI_line==(i+4)){
			x=1;
			break;
		}
		else if(EXTI_line==(i+8)){
			x=2;
			break;
		}
		else if(EXTI_line==(i+12)){
			x=3;
			break;
		}
	}

	//get initial-bit
	for (int i=0;i<4;i++){
		if(EXTI_line==x*4+i){
			initial_bit=4*i;
			break;
		}
	}

	if(GPIOx==GPIOA){
		for(int j=0;j<4;j++){
			SYSCFG->EXTICR[x]&=(1u<<(initial_bit+j));
		}
	}
	else if(GPIOx==GPIOB){
		SYSCFG->EXTICR[x]|=(1u<<(initial_bit+0));
		for(int j=1;j<4;j++){
			SYSCFG->EXTICR[x]&=~(1u<<(initial_bit+j));
		}
	}
	else if(GPIOx==GPIOC){
		SYSCFG->EXTICR[x]&=~(1u<<(initial_bit+0));
		SYSCFG->EXTICR[x]|=(1u<<(initial_bit+1));
		SYSCFG->EXTICR[x]&=~(1u<<(initial_bit+2));
		SYSCFG->EXTICR[x]&=~(1u<<(initial_bit+3));
	}
	else if(GPIOx==GPIOD){
		SYSCFG->EXTICR[x]|=(1u<<(initial_bit+0));
		SYSCFG->EXTICR[x]|=(1u<<(initial_bit+1));
		SYSCFG->EXTICR[x]&=~(1u<<(initial_bit+2));
		SYSCFG->EXTICR[x]&=~(1u<<(initial_bit+3));
	}
	else if(GPIOx==GPIOE){
		SYSCFG->EXTICR[x]&=~(1u<<(initial_bit+0));
		SYSCFG->EXTICR[x]&=~(1u<<(initial_bit+1));
		SYSCFG->EXTICR[x]|=(1u<<(initial_bit+2));
		SYSCFG->EXTICR[x]&=~(1u<<(initial_bit+3));
	}
	else if(GPIOx==GPIOH){
		SYSCFG->EXTICR[x]|=(1u<<(initial_bit+0));
		SYSCFG->EXTICR[x]|=(1u<<(initial_bit+1));
		SYSCFG->EXTICR[x]|=(1u<<(initial_bit+2));
		SYSCFG->EXTICR[x]&=~(1u<<(initial_bit+3));
	}



	//configure mask bit
	if(mask){
		//configure mask bit of EXTI_line as not masked
		EXTI->IMR|=(1u<<EXTI_line);
	}
	else{
		//configure mask bit of EXTI_line as masked
		EXTI->IMR&=~(1u<<EXTI_line);
	}

	// Configure the Trigger
	if(RIS){
		// Configure the Trigger as Rising Edge
		EXTI->RTSR|=(1u<<EXTI_line);
	}
	else{
		// Configure the Trigger as falling Edge
		EXTI->FTSR|=(1u<<EXTI_line);
	}


}


void NVIC_EXTI_Enable(char EXTI_line){
	// enable EXTIx interrupt from NVIC
	for(int i=0;i<5;i++){
		//lines 0:4
		if(EXTI_line==i){
			NVIC->ISER[0]|=(1u<<(EXTI_line+6));
			break;
		}
		//lines 5:9
		else if(EXTI_line==(i+5)){
			NVIC->ISER[0]|=(1u<<23);
			break;
		}
		//lines 10:15
		else{
			NVIC->ISER[1]|=(1u<<8);
		}

	}
}

void NVIC_EXTI_Disable(char EXTI_line){
	// enable EXTIx interrupt from NVIC
	for(int i=0;i<5;i++){
		//lines 0:4
		if(EXTI_line==i){
			NVIC->ICER[0]|=(1u<<(EXTI_line+6));
			break;
		}
		//lines 5:9
		else if(EXTI_line==(i+5)){
			NVIC->ICER[0]|=(1u<<23);
			break;
		}
		//lines 10:15
		else{
			NVIC->ICER[1]|=(1u<<8);
		}

	}
}
