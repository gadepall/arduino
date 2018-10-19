#include <avr/io.h>
#include <util/delay.h>

 
int main (void)
{
	
	
  /* Arduino boards have a LED at PB5 */
  DDRB    |= ((1 << DDB5));
  while (1) {
    PORTB = ((0 <<  PB5));
  }

  /* . */
  return 0;

}
