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

int SmileWave(String message) {
  digitalWrite(LED, HIGH) ;
  Wave(message) ;
  digitalWrite(LED, LOW) ;
}

// LED FUNCTION
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
    moveArmForward();
    moveArmBackward();
  }
}
void moveArmForward() {
  int pos;
  for(pos = 0; pos <= 120; pos += 5) {
    catArm.write(pos);
    delay(20);
  }
}
void moveArmBackward() {
  int pos;
  for(pos = 120; pos >= 0; pos -= 5) {
    catArm.write(pos);
    delay(20);
  }
}
