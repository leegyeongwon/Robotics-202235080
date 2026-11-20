const int potPin = A2;
const int ledPin = 9;

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  float value = analogRead(potPin);
  
  //same with "value = map(value, 0, 1023, 0, 255);"
  value = int((value / 1023) * 255);
  
  Serial.println(value)
  
  delay(50);
}