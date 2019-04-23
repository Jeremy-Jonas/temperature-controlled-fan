#include <Servo.h>
#define relay 2

int val;
int prevState = 0;
int tempPin = 0;
int MINTEMP = 23;
int MAXTEMP = 25;


void setup()
{
Serial.begin(9600);
pinMode(relay, OUTPUT);
}
void loop()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float temp = mv/10;

if (temp > MAXTEMP && prevState == 0) {
  digitalWrite(relay, HIGH);
  prevState = 1;
} else if (temp < MINTEMP && prevState == 1) {
  digitalWrite(relay, LOW);
  prevState = 0;
}

Serial.print("TEMPRATURE = ");
Serial.print(temp);
Serial.print("*C");
Serial.println();
Serial.print("prevState = ");
Serial.print(prevState);
Serial.println();
delay(1000);

}
