/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "gpio.h"


int main(void)
{
	//pins 5 >>>output
	GPIO_Init(GPIOB,5,1,1,0); //name,pin,dir,enable_oin,PUPD
	//pins 6 >>>output
	GPIO_Init(GPIOB,6,1,1,0);
	//pins 7 >>>output
	GPIO_Init(GPIOB,7,1,1,0);
	//pin3 >> input, pull-up
	GPIO_Init(GPIOB,3,0,1,1);
	char press=0;
	char current=1,past=1;

	while(1){
		past=current;
		if(GPIO_ReadPin(GPIOB,3)){
			current=1;
		}
		else{
			current=0;
		}
		if((current==0)&&(past==1)){
			press++;
			//different color combinations
			if(press==0){
				GPIO_WritePin(GPIOB,5,0);
				GPIO_WritePin(GPIOB,6,0);
				GPIO_WritePin(GPIOB,7,0);
				for(int i =0 ; i<500000;i++){}// delay for some time
			}
			if(press==1){
				GPIO_WritePin(GPIOB,5,0); //pin5>>low
				GPIO_WritePin(GPIOB,6,0); //pin6>>low
				GPIO_WritePin(GPIOB,7,1); //pin7>>high
				for(int i =0 ; i<500000;i++){}// delay for some time
			}
			if(press==2){
				GPIO_WritePin(GPIOB,5,0);
				GPIO_WritePin(GPIOB,6,1);
				GPIO_WritePin(GPIOB,7,0);
				for(int i =0 ; i<500000;i++){}// delay for some time
			}
			if(press==3){
				GPIO_WritePin(GPIOB,5,0);
				GPIO_WritePin(GPIOB,6,1);
				GPIO_WritePin(GPIOB,7,1);
				for(int i =0 ; i<500000;i++){}// delay for some time
			}
			if(press==4){
				GPIO_WritePin(GPIOB,5,1);
				GPIO_WritePin(GPIOB,6,0);
				GPIO_WritePin(GPIOB,7,0);
				for(int i =0 ; i<500000;i++){}// delay for some time
			}
			if(press==5){
				GPIO_WritePin(GPIOB,5,1);
				GPIO_WritePin(GPIOB,6,0);
				GPIO_WritePin(GPIOB,7,1);
				for(int i =0 ; i<500000;i++){}// delay for some time
			}
			if(press==6){
				GPIO_WritePin(GPIOB,5,1);
				GPIO_WritePin(GPIOB,6,1);
				GPIO_WritePin(GPIOB,7,0);
				for(int i =0 ; i<500000;i++){}// delay for some time
			}
			if(press==7){
				GPIO_WritePin(GPIOB,5,1);
				GPIO_WritePin(GPIOB,6,1);
				GPIO_WritePin(GPIOB,7,1);
				for(int i =0 ; i<500000;i++){}// delay for some time
			}
			if(press==8){
				press=0;
				GPIO_WritePin(GPIOB,5,0);
				GPIO_WritePin(GPIOB,6,0);
				GPIO_WritePin(GPIOB,7,0);
				for(int i =0 ; i<500000;i++){}// delay for some time
			}
		}
	}

}

