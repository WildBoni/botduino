int redLed = 2;
int greenLed = 7;
int inputpin = 4;
int outputpin = 5;

void setup(){
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(inputpin, INPUT);
  pinMode(outputpin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop(){
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  int distance, distance1 = 3;
  digitalWrite(outputpin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(inputpin, LOW);

  // Calculating obstacle distance using ultrasound sensor: speed of sound
  // is 29 microseconds per centimeter; the signal hits the obstacle and
  // bounces back, so we divide the distance by two
  distance = pulseIn(inputpin, HIGH);
  distance1 = distance/29/2;
  delay(200);

  if(distance1 >= 30){
   // Moving forward
   digitalWrite(8, LOW);
   digitalWrite(13, LOW);
   digitalWrite(9, LOW);
   digitalWrite(12, LOW);
   delay(2);
   analogWrite(11, 140);
   analogWrite(3, 140);
 }

// Robot is getting closer to obstacle
if(distance1 < 30 && distance1 >0){
// Change led light from green to red
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
// Brake
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(20);
// Backwards
  digitalWrite(8, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(12, HIGH);
  delay(2);
  analogWrite(11, 190);
  analogWrite(3, 190);
  delay(1000);
// Turn
  digitalWrite(8, LOW);
  digitalWrite(13, LOW);
  digitalWrite(9, LOW);
  digitalWrite(12, HIGH);
  delay(2);
  analogWrite(11, 190);
  analogWrite(3, 190);
  delay(700);
// Brake
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(200);
// Forward
  digitalWrite(8, LOW);
  digitalWrite(13, LOW);
  digitalWrite(9, LOW);
  digitalWrite(12, LOW);
  delay(2);
  analogWrite(11, 140);
  analogWrite(3, 140);
// Switch led light from red to green
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  }
delay(200);
}
