#include <Arduino.h>

int list[]={12,14,27,32,35};

void setup() {
for(int i = 0; i < 5; i++)
pinMode(list[i],OUTPUT);
}

void loop() 
{
//来回for循环，设置好起止点
  for(int i = 0; i < 5; i++ )
  {
  digitalWrite(list[i] , HIGH);
  delay(500);

  digitalWrite(list[i] , LOW);
  delay(500);
  }

  for(int i = 4;i >=0;i--)
  {
  digitalWrite(list[i] , HIGH);
  delay(500);
  digitalWrite(list[i] , LOW);
  delay(500);
  }
}