const int buttonPin = 2;

void setup()
{
	pinMode(buttonPin, INPUT);
  	Serial.begin(115200);
}

void loop()
{
	int buttonState = digitalRead(buttonPin);
 	
  if(buttonState == HIGH) {
    	Serial.println("Pressed");
    	delay(50);
  }
  else {
  		Serial.println("Not Pressed");
        delay(50);
  }
}