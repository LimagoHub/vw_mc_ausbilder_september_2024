/*
 * PWMMitModul.c
 *
 * Created: 26.09.2024 07:47:06
 * Author : JoachimWagner
 */ 

#include <avr/io.h>

#include "PWM.h"



int main(void)
{
	PWM_init();
    
   
	
	PWM_set_value(64);
	
	
    while (1) 
    {
    }
}

