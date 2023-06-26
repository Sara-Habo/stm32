/*
 * adc.h
 *
 *  Created on: May 31, 2022
 *      Author: Dell
 */

#ifndef INCLUDE_ADC_H_
#define INCLUDE_ADC_H_
struct ADCConfigType{
	enum Resolution{bit_12,bit_10,bit_8,bit_6}RES;
	enum ConversionMode{single,continues}ConMode;
	float Vref;
};
void ADC_Init(struct ADCConfigType* ConfigParamPtr);
void ADC_StartConv(unsigned char ChannelNum);


#endif /* INCLUDE_ADC_H_ */
