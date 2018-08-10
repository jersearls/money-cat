Servo catArm;  // create servo object to control a servo

#define LED 1

void setup()
{
  catArm.attach(D0);  // attaches the servo on pin 0 to the servo object
  Particle.function("Wave", Wave) ;

  pinMode(LED, OUTPUT);
  Particle.function("ToggleLED", ToggleLED) ;

  Particle.function("SmileWave", SmileWave) ;
}

void loop()
{
}

int SmileWave(String message) {
  digitalWrite(LED, HIGH) ;
  Wave(message) ;
  digitalWrite(LED, LOW) ;
}

// LED FUNCTIONS
int ToggleLED(String message) {
  if (message == "0") {
    digitalWrite(LED, LOW);
  }
  else if (message == "1") {
    digitalWrite(LED, HIGH);
  }
}

//SERVO FUNCTIONS
int Wave(String message) {
  int i;
  int numberOfWaves = message.toInt();
  for (i = 0; i < numberOfWaves; i++) {
    extendArm();
    retractArm();
  }
}

void extendArm() {
  int pos = 0;
  for(pos = 0; pos < 180; pos += 5)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    catArm.write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);                       // waits 15ms for the servo to reach the position
  }
}

void retractArm() {
  int pos = 0;
  for(pos = 180; pos>=1; pos-= 5)     // goes from 180 degrees to 0 degrees
  {
    catArm.write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);                       // waits 15ms for the servo to reach the position
  }
}
