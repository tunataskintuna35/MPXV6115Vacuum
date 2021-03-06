#include "MPXV6115V.h"
#include "DRV8833.h"
#include "Arduino.h"
#include "EEPROM.h"
#include "MAX7219.h"
#include "EEPROM.h"


//************************************************NESNE ATAMALARI***********************************************************
LedControl lc=LedControl(12,11,10,4);				//MAX7219 segment pin ve nesne atamaları
DRV8833 driver=DRV8833();					//DRV8833 sınıfı bir nesne olarak tanımlandırıldı
MPXV6115V mpxv6115v(A0);					//MPXV6115V nesne ataması yapıldı

const int inputA1 = 5, inputA2 = 6;

//************************************************PİN ATAMALARI*************************************************************
unsigned int addr=0;
byte value;

const int vacuum=A0;						//vakum analog pin
const int temperature=A1;						//temperature analog pin
const int batt=A2;						//battery analog pin
const int up=2;							//setting değerini yukarı arttırmak için
const int down=3;						//setting değerini aşağı azaltmak için 


//*************************************************DEĞİŞKENLER**************************************************************
float vakum; 
int setting;
int tolerance=25;
const unsigned long delaytime=250;
int temp_temp;

//**************************************************SETUP***********************************************************************

void setup()
{	
		  pinMode(up,INPUT);
		  pinMode(down,INPUT);
		  Serial.begin(9600);
		  while(!Serial);
		  driver.attachMotorA(inputA1,inputA2);		//DRV8833 için motor bağlı olup olmadığını test etmek amaçlı
		  //Serial.println("hazir");
		  //Serial.println("\n")			        //  attachInterrupt(digitalPinToInterrupt(up),upset,CHANGE)
		  lc.shutdown(0,false);
		  lc.setIntensity(0,8);
      	          lc.clearDisplay(0);
}


//**************************************************MAIN LOOP****************************************************************
void loop()
{
		//sicaklik();
		vakum=mpxv6115v.hesap();
		motor();
		
		
		set();
		
		monitor();		
		//temp_measures
}

//***************************************************************FONKSİYONLAR*************************************************
bool sicaklik()
{
	int reading=analogRead(temperature);
	float voltage_=reading*5.0;
	voltage/=1024.0;
	float temperatureC=(voltage-0.5)*100;
	if(temperatureC<0)
		return 0;
	return 1;
}
void set()
{
	while(up || down)
	{
		if(up)
			{
				setting+=5;
				delay(100);
				EEPROM.write(addr,setting);
			}
		if(down)
			{
				setting-=5;
				delay(100);
				EEPROM.write(addr,setting);
			}
	}
}
void measure
{
}
void motor()
{
	unsigned int value_vac=EEPROM.read(addr);
	
	if(vakum<=addr)
		{
			
		}
}
