#include "MPXV6115V.h"
#include "DRV8833.h"
#include "Arduino.h"
#include "EEPROM.h"
#include "MAX7219.h"


//************************************************NESNE ATAMALARI***********************************************************
LedControl lc=LedControl(12,11,10,4);				//MAX7219 segment pin ve nesne atamaları
DRV8833 driver=DRV8833();					//DRV8833 sınıfı bir nesne olarak tanımlandırıldı
MPXV6115V mpxv6115v(A0,A1);					//MPXV6115V nesne ataması yapıldı

const int inputA1 = 5, inputA2 = 6;

//************************************************PİN ATAMALARI*************************************************************

const int vacuum=A0;						//vakum analog pin
const int temp=A1;						//temperature analog pin
const int batt=A2;						//battery analog pin
const int up=2;							//setting değerini yukarı arttırmak için
const int down=3;						//setting değerini aşağı azaltmak için 


//*************************************************DEĞİŞKENLER**************************************************************
float vakum; 
int setting=250;
int tolerance=25;
float temp_voltage,degreeC,degreeF;				//Isı değişkenlerinin tanımlanması 
const unsigned long delaytime=250;
int temp_temp;



void setup()
{	
		  pinMode(up,INPUT);
		  pinMode(down,INPUT);
		  Serial.begin(9600);
		  while(!Serial);
		  driver.attachMotorA(inputA1,inputA2);		//DRV8833 için motor bağlı olup olmadığını test etmek amaçlı
		  Serial.println("hazir");
		  Serial.println("\n")			        //  attachInterrupt(digitalPinToInterrupt(up),upset,CHANGE)


		  lc.shutdown(0,false);
		  lc.setIntensity(0,8);
      	  lc.clearDisplay(0);
}


//**************************************************MAIN LOOP****************************************************************
void loop()
{

		measure();
		test();
		set();
		monitor();		
		//temp_measures
}

//***************************************************************FONKSİYONLAR*************************************************
void measure()
{
	temp_temp=temp_measure();	
	
	
}
void test()
{
	
}

void set()
{
	while((vakum<setting-tolerance) || !(vakum>(setting+tolerance)) )					//Sensör ölçüm değerleri 225-275 arasında ise
	{
		driver.motorAForward();
		vakum=analogRead(A0);
	}
}

