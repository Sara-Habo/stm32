/*
 * keypad.c
 *
 *  Created on: May 14, 2022
 *      Author: Dell
 */
#include "stm32f4xx.h"
#include "keypad.h"
#include "gpio.h"
const int no_raws = 4;
const int no_cols = 3;
//char rows[4]={3,4,5,6}; //fill the array
//char cols[3]={0,1,2}; //fill the array
char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};// fill the array
char currentvalue;
char current=0,past=0;

void KeyPad_INIT(void)
{
	// get pins from raw and set it as input
	GPIO_Init(GPIOB,4,0,1,0); //pin4>>input (pull-down)
	GPIO_Init(GPIOB,5,0,1,0);
	GPIO_Init(GPIOB,6,0,1,0);
	GPIO_Init(GPIOB,7,0,1,0);

	// get pins from cols and set it as output
	GPIO_Init(GPIOB,0,1,1,0);
	GPIO_Init(GPIOB,1,1,1,0);
	GPIO_Init(GPIOB,2,1,1,0);
}

void KeyPad_MANAGE(void)
{
	//loop on cols
	for(int j=0;j<no_cols;j++){
		//set pin j
		GPIO_WritePin (GPIOB,j,1);
		//loop on row
		for(int i=0;i<no_raws;i++){

			if(GPIO_ReadPin(GPIOB,i+4)){
				current=1;
			}
			else{
				current=0;
			}

			if(current==1&&past==0){//valid press
				while(GPIO_ReadPin(GPIOB,i+4)){}
				currentvalue=lookupTable[i][j];
				KeypadCallouts_KeyPressNotificaton();
			}
		}

		past=current;
		//clear pin again
		GPIO_WritePin (GPIOB,j,0);
	}
}

char KeyPad_GET_VALUE(void)
{
	return currentvalue;
}

void KeypadCallouts_KeyPressNotificaton(void)
{
	char value=KeyPad_GET_VALUE();
	switch (value){
		case 0:
			GPIO_WritePin (GPIOA,1,0);
			GPIO_WritePin (GPIOA,2,0);
			GPIO_WritePin (GPIOA,3,0);
			GPIO_WritePin (GPIOA,4,0);
			break;
		case 1:
			GPIO_WritePin (GPIOA,1,1);
			GPIO_WritePin (GPIOA,2,0);
			GPIO_WritePin (GPIOA,3,0);
			GPIO_WritePin (GPIOA,4,0);
			break;
		case 2:
			GPIO_WritePin (GPIOA,1,0);
			GPIO_WritePin (GPIOA,2,1);
			GPIO_WritePin (GPIOA,3,0);
			GPIO_WritePin (GPIOA,4,0);
			break;
		case 3:
			GPIO_WritePin (GPIOA,1,1);
			GPIO_WritePin (GPIOA,2,1);
			GPIO_WritePin (GPIOA,3,0);
			GPIO_WritePin (GPIOA,4,0);
			break;
		case 4:
			GPIO_WritePin (GPIOA,1,0);
			GPIO_WritePin (GPIOA,2,0);
			GPIO_WritePin (GPIOA,3,1);
			GPIO_WritePin (GPIOA,4,0);
			break;
		case 5:
			GPIO_WritePin (GPIOA,1,1);
			GPIO_WritePin (GPIOA,2,0);
			GPIO_WritePin (GPIOA,3,1);
			GPIO_WritePin (GPIOA,4,0);
			break;
		case 6:
			GPIO_WritePin (GPIOA,1,0);
			GPIO_WritePin (GPIOA,2,1);
			GPIO_WritePin (GPIOA,3,1);
			GPIO_WritePin (GPIOA,4,0);
			break;
		case 7:
			GPIO_WritePin (GPIOA,1,1);
			GPIO_WritePin (GPIOA,2,1);
			GPIO_WritePin (GPIOA,3,1);
			GPIO_WritePin (GPIOA,4,0);
			break;
		case 8:
			GPIO_WritePin (GPIOA,1,0);
			GPIO_WritePin (GPIOA,2,0);
			GPIO_WritePin (GPIOA,3,0);
			GPIO_WritePin (GPIOA,4,1);
			break;
		case 9:
			GPIO_WritePin (GPIOA,1,1);
			GPIO_WritePin (GPIOA,2,0);
			GPIO_WritePin (GPIOA,3,0);
			GPIO_WritePin (GPIOA,4,1);
			break;
		case '*':
			GPIO_WritePin (GPIOA,1,1);
			GPIO_WritePin (GPIOA,2,1);
			GPIO_WritePin (GPIOA,3,1);
			GPIO_WritePin (GPIOA,4,1);
			break;
		case '#':
			GPIO_WritePin (GPIOA,1,1);
			GPIO_WritePin (GPIOA,2,1);
			GPIO_WritePin (GPIOA,3,1);
			GPIO_WritePin (GPIOA,4,1);
			break;
	}
}

