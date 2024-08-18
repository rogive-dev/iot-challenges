#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin 2
DHT dht(dht_dpin, DHTTYPE);

#define LED D1 // LED
int ValueRead=2;
int myflag=0;

const int ANALOGPIN = A0;
int ldr = 0; 

void setup()
{
 Serial.begin(9600);
 pinMode(LED, OUTPUT);
 digitalWrite(LED, LOW); //LED comienza apagado
  pinMode (ANALOGPIN, INPUT);
 dht.begin(); // función begin
}

void loop()
{
 if (Serial.available()){
   ValueRead=Serial.parseInt();
 }
   if (((ValueRead==1 && myflag==0)|| myflag==1)&!(ValueRead==2 && myflag==1)){
     digitalWrite(LED, HIGH);  // Se prende el LED
     Serial.println("Prendido");
     myflag=1;
   }
   else{
     digitalWrite(LED, LOW);   // Se apaga el LED
     Serial.println("Apagado");
     myflag=0;
   }

  // LDR
  ldr = analogRead (ANALOGPIN);  // Read sensor input
  Serial.print ("ldr: ");
  Serial.println (ldr);
  delay (1000);

  // DHT
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 
 Serial.print("Current humidity = ");
 Serial.print(h);
 Serial.print("%  ");
 Serial.print("temperature = ");
 Serial.print(t);
 Serial.println("C  ");
}