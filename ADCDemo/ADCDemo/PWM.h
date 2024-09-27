/*
 * PWM.h
 *
 * Created: 26.09.2024 08:08:49
 *  Author: JoachimWagner
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
/*
	Was macht die Methode
*/
void PWM_init();
void PWM_set_value(uint8_t value);

/*
 so reinschreiben, dass es jeder versteht
 fachliche Beschreibung
*/
void PWM_set_duty(double duty);



#endif /* PWM_H_ */