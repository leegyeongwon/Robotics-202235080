const int buttonPin = 2;
const int ledPin = 7;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  Serial.begin(115200);
}

void loop()
{
  int buttonState = digitalRead(buttonPin);
 	
  if(buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Pressed");
    delay(50);
  }
  else {
  	digitalWrite(ledPin, LOW);
    Serial.println("Not Pressed");
    delay(50);
  }
}