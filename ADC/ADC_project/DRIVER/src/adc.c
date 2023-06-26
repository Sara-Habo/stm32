/*
 * adc.c
 *
 *  Created on: May 31, 2022
 *      Author: Dell
 */
#include "stm32f4xx.h"
#include "adc.h"
#include "gpio.h"
//void ENInterupt(void);

void ADC_Init(struct ADCConfigType* ConfigParamPtr)
{
	//enable clock to ADC1
	RCC->APB2ENR|=(1u<<8);

	//turn ADC on
	ADC1->CR2 |=(1u<<0);

	//set resolution
	if(ConfigParamPtr->RES==bit_12){
		ADC1->CR1&=~(1<<24);
		ADC1->CR1&=~(1<<25);
	}
	else if(ConfigParamPtr->RES==bit_10){
			ADC1->CR1|=(1<<24);
			ADC1->CR1&=~(1<<25);
		}
	else if(ConfigParamPtr->RES==bit_8){
			ADC1->CR1&=~(1<<24);
			ADC1->CR1|=(1<<25);
		}
	else if(ConfigParamPtr->RES==bit_6){
			ADC1->CR1|=(1<<24);
			ADC1->CR1|=(1<<25);
		}

	//if continues mode
	if(ConfigParamPtr->ConMode==continues){
		ADC1->CR2|=(1u<<1);
	}
	else if(ConfigParamPtr->ConMode==single){
		ADC1->CR2|=(1u<<1);
	}

	//set channel length to 1
	ADC1->SQR1&=~(1u<<20);
	ADC1->SQR1&=~(1u<<21);
	ADC1->SQR1&=~(1u<<22);
	ADC1->SQR1&=~(1u<<23);

	//Enable interrupt if USE_POLLING=1
	#if (USE_POLLING==0)
	//ENInterupt();
	//enable EOC interrupt
	ADC1->CR1|=(1u<<5);
	//enable NVIC
	NVIC->ISER[0]|=(1u<<18);
	#endif

}
/*
void ENInterupt(void){
	//enable EOC interrupt
	ADC1->CR1|=(1u<<5);
	//enable NVIC
	NVIC->ISER[0]|=(1u<<18);
}*/

void ADC_StartConv(unsigned char ChannelNum){
	//select channel
	ADC1->SQR3=ChannelNum;

	//channels[0:7] connected to GPIOA[0:7]
	for(int i=0;i<=7;i++){
		if(ChannelNum==i){
			GPIO_Init(GPIOA,i,2,0,0); //port,pin dir(analog,no PUPD),RCC,PUPD
			break;
		}
	}

	//channels[8:9] connected to GPIOB[0:1]
	if(ChannelNum==8){
		GPIO_Init(GPIOB,0,2,1,0);
		ADC1->SQR3=8;
	}
	else if(ChannelNum==9){
		GPIO_Init(GPIOB,1,2,1,0);
	}

	//channels[10:15] connected to GPIOC[0:5]
	for(int i=0;i<=5;i++){
		if(ChannelNum==i+10){
			GPIO_Init(GPIOC,i,2,2,0); //port,pin dir(analog),RCC,PUPD
			break;
		}
	}

	//start conversion
	ADC1->CR2 |=(1u<<30);
}

