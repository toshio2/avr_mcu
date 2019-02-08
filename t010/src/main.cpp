/*
 *  Version     : v0.1.0
 *  Author      : Toshio
 *  Target      : ATmega328p
 *  Created     : 07 February 2019
 *  Updated     : 08 February 2019
 */

#include <avr/io.h>
#include <util/delay.h>
#include "Arduino.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define LTHRES 500
#define RTHRES 500

void adc_init()
{
    ADMUX |= (1 << REFS0);
    ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t adc_read(uint8_t channel)
{
    channel &= 0x07;
    ADMUX = (ADMUX & 0xf8) | channel;

    ADCSRA |= (1 << ADSC);

    while(ADCSRA & (1 << ADSC));

    return(ADC);
}

int main()
{
    uint16_t adc_result0;
    // char int_buffer[10];
    DDRC |= (1 << DDC0);

    Serial.begin(115200);

    adc_init();

    while(1)
    {
        adc_result0 = adc_read(0);
        Serial.print("AD Conversion: ");
        Serial.println(adc_result0);
    }

}