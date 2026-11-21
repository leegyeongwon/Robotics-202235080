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
  
  if(value != 0) {
  	analogWrite(ledPin, value);
    delay(50);
  }
  else {
    digitalWrite(ledPin, LOW);
    delay(50);
  }
  
  delay(50);
}


