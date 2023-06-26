/*
 * gpio.h
 *
 *  Created on: May 5, 2022
 *      Author: Dell
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_
void GPIO_Init(GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin,char PUPD);
int GPIO_WritePin (GPIO_TypeDef *GPIOx,char pin,char state);
int GPIO_ReadPin(GPIO_TypeDef *GPIOx,char pin);

#endif /* INCLUDE_GPIO_H_ */
