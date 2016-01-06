#ifndef MPXV6115V_h
#define MPXV6115V_h

#include <Arduino.h>
class MPXV6115V
{
    public:
      MPXV6115V(int pin);
      float hesap();
      //boolean fault();
    private:
      int _pin;
};
#endif
