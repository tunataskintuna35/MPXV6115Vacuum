#include "MPXV6115V.h"
#include "Arduino.h"

MPXV6115V :: MPXV6115V(int pin)
{
  _pin=pin;
}
float MPXV6115V:: hesap()
{
  float deger=analogRead(_pin);
  float voltage= deger * (5.0 / 1023.0);
  float kpa=((deger/5)-0.92)/(0.007652);
  float mmhg=kpa * (760/101.325);
  return mmhg;
  boolean MPXV6115V::fault()
  {
	
  }
}
