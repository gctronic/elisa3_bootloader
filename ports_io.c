#include <avr\io.h>
#include "ports_io.h"

void initPortsIO(void) {

	DDRA = 0xFF;	// proximity pulses as output
	PORTA = 0x00;	// proximity pulses turned off
	
	DDRB = 0xF7;	// pwm for led r/g/b as output; CE, MOSI, SCK, SS as output (master) 
	PORTB = 0xE0;
	//PORTB |= (1 << 5) | (1 << 6) | (1 << 7); // leds off	
	//PORTB &= ~(1 << 5) & ~(1 << 6) & ~(1 << 7); // leds off
	//PORTB &= ~(1 << 7);

	DDRC = 0xF0;	// selector as input; IR leds as output; sens-enable, sleep as output
	PORTC = 0xB0;	// sleep = 1, IR leds = 1

	DDRD = 0xF0;	// all pins to output; when usart and i2c peripherals are activated they change the pins direction accordingly
	PORTD = 0x0F;	// default for unused pins is 0

	DDRE = 0xFF;	// all pins to output (pwm and dir for motor right as output; when usart is activated it changes the pins direction accordingly)
	PORTE = 0x03;	// default for unused pins is 0; pwm for motors set to 0 when stopped

	DDRF = 0x00;	// adc channel pins as input		

	DDRG = 0xFF;	// unused pins as output
	#ifdef HW_REV_3_0
		PORTG = 0x00;	// default for unused pins is 0
	#endif
	#ifdef HW_REV_3_0_1
		PORTG = 0x00;	// default for unused pins is 0
	#endif
	#ifdef HW_REV_3_1
		PORTG = 0x08;	// default for unused pins is 0, led3 to 1
	#endif	

	DDRH = 0xFF;	// all pins to output; when usart is activated it changes the pins direction accordingly
	PORTH = 0x00;	// default for unused pins is 0; pwm for motors set to 0 when stopped

	DDRJ = 0x0F;	// cliff pulses as output; charge-on, button0, remote, charge status as input
	#ifdef HW_REV_3_0
		PORTJ &= 0x00;	// cliff pulse turned off
		//#warning "Normal logic for ground sensors (hw rev 3.0)"
	#endif
	#ifdef HW_REV_3_0_1
		PORTJ = 0x0F;
		//#warning "Inverse logic for ground sensors (hw rev 3.0.1)"
	#endif
	#ifdef HW_REV_3_1
		PORTJ = 0x0F;
		//#warning "Inverse logic for ground sensors (hw rev 3.1)"
	#endif	

	DDRK = 0x00;	// adc channel pins as input

	DDRL = 0xFF;	// all pins to output
	#ifdef HW_REV_3_0
		PORTL = 0x00;	// pwm (unused) and unused pins to 0
	#endif
	#ifdef HW_REV_3_0_1	
		PORTL = 0x00;	// pwm (unused) and unused pins to 0
	#endif
	#ifdef HW_REV_3_1
		PORTL = 0xF7;	// pwm (unused) to 0, leds to 1
	#endif
		
}
