#include "ldr.h"
#include "Arduino.h"
#include "main.h"
#define LDR_SENSOR      A1
#define GARDEN_LIGHT    3

void init_ldr(void)
{
   pinMode(GARDEN_LIGHT, OUTPUT);
   pinMode(LDR_SENSOR , INPUT);
   
}
void brightness_control(void)
{
  unsigned int adc_val;

  // put your main code here, to run repeatedly:
  adc_val = analogRead(LDR_SENSOR);/*to read values from LDR sensor*/

  /*scale it down to 0 to 255 and reverse it 255 to 0*/
  adc_val = 255 -(adc_val/4);

  //map(0 ,1023,255,0)
  analogWrite(GARDEN_LIGHT, adc_val);
  delay(100);

}
