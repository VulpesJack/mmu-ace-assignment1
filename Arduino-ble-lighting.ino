char command;
String string;
#define led 8

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}



void loop()
{
  if (Serial.available() > 0)
  {
    string = "";
  }

  while (Serial.available() > 0)
  {
    command = ((byte)Serial.read());
    if (command == ':')
    {
      break;
    }
    else
    {
      string += command;
    }
    delay(1);
  }
  if (string == "LO")
  {
    LEDOn();
  }
  if (string == "LF")
  {
    LEDOff();
  }
}

void LEDOn()
{
  digitalWrite(led, HIGH);
}
void LEDOff()
{
  digitalWrite(led, LOW);
  delay(500);
}
