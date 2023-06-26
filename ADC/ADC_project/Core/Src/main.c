#include "stm32f4xx.h"
#include "adc.h"
#include "gpio.h"
#include "interupt.h"
#define USE_POLLING 1

void ADC_IRQHandler(void);
unsigned int data;

int main(void)
{
	struct ADCConfigType adc1;
	adc1.RES=bit_12;
	adc1.ConMode=single;
	adc1.Vref=5;
	//initialize ADC
	ADC_Init(&adc1);
	//Start conversion on channel 1
	ADC_StartConv(1);





}

void ISR_OF_ADC(void){
	if(ADC1->SR&(1u<<1)){ //EOC=1
		data=ADC1->DR;
	}
}

void ADC_IRQHandler(void){
	ISR_OF_ADC();
}


