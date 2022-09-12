void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void dot()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}

void dash()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(3000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}


void loop() 
{
  //P
  dot();
  dash();
  dash();
  dot();

  //A
  dot();
  dash();

  //R
  dot();
  dash();
  dot();

  //I
  dot();
  dot();  
}
