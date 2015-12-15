#include "MPXV6115V.h"
#include "DRV8833.h"
#include "Arduino.h"
#include "EEPROM.h"
#include "MAX7219.h"

const int vacuum=A0;
const int temp=A1;
const int batt=A2;
const int up=2;
const int down=4;

float vakum; 
int setting=250;
int tolerance=25;




void setup()
{	
		  pinMode(up,INPUT);
		  pinMode(down,INPUT);
		  
			Serial.begin(9600);
		    while(!Serial);
		  driver.attachMotorA(inputA1,inputA2);
		  Serial.println("hazir");
		  Serial.println("\n");
		  

}

void loop()
{
			
	// BUTON İLE ARTTIRMA AZALTMA  
	// digitalRead(up);
	// digitalRead(down);

 
	while((vakum<setting-tolerance) || !(vakum>(setting+tolerance)) )
	{
		
		driver.motorAForward();
		vakum=analogRead(A0);
			
				
		
	}
	driver.motorAStop();
	
	
	
	
}
