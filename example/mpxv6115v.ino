#include "MPXV6115V.h"
#include "DRV8833.h"
#include "Arduino.h"
#include "EEPROM.h"
#include "MAX7219.h"

LedControl lc=LedControl(12,11,10,4);
DRV8833 driver=DRV8833();					//DRV8833 sınıfı bir nesne olarak tanımlandırıldı
MPXV6115V mpxv6115v(A0);



const int vacuum=A0;						//vakum 
const int temp=A1;
const int batt=A2;
const int up=2;
const int down=3;

float vakum; 
int setting=250;
int tolerance=25;


float isivoltage,degreeC,degreeF;			//Isı değişkenlerinin tanımlanması 


const unsigned long delaytime=250;



void setup()
{	
		  pinMode(up,INPUT);
		  pinMode(down,INPUT);
		  Serial.begin(9600);
		  while(!Serial);
		  driver.attachMotorA(inputA1,inputA2);				//DRV8833 için motor bağlı olup olmadığını test etmek amaçlı
		  Serial.println("hazir");
		  Serial.println("\n");
	  //  attachInterrupt(digitalPinToInterrupt(up),upset,CHANGE)

}

void loop()
{
			
	// BUTON İLE ARTTIRMA AZALTMA  
	// digitalRead(up);
	// digitalRead(down);

		measure();
		test();
		set();
		monitor();		





	
	driver.motorAStop();
	
	
	
	
}


void measure()
{
		
	
	
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

void monitor()
{

}

