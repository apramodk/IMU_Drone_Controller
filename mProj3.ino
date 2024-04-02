int fleft = 14;
int fright = 12;
int bleft = 34;
int bright = 35;

void setup() {
  Serial.begin(115200);
  Serial.println("Hz");
  pinMode(fleft, OUTPUT);
  pinMode(fright, OUTPUT);
  pinMode(bleft, OUTPUT);
  pinMode(bright, OUTPUT);
}

void loop(){
  // fright
    digitalWrite(fright, HIGH);
    delay(500);
    digitalWrite(fright, LOW);
    delay(500);
}
//   digitalWrite(fleft, LOW);
//   digitalWrite(fright, LOW);
//   digitalWrite(bleft, LOW);
//   digitalWrite(bright, LOW);
//   delay(500);
//   // go Right
//   digitalWrite(fleft, HIGH);
//   digitalWrite(bleft, HIGH);
//   delay(300);
//   digitalWrite(fleft, LOW);
//   digitalWrite(bleft, LOW);
//   Serial.print("I got after Right");
//   delay(300);
//   // go Left
//   digitalWrite(fright, HIGH);
//   digitalWrite(bright, HIGH);
//   delay(300);
//   digitalWrite(fright, LOW);
//   digitalWrite(bright, LOW);
//   delay(300);
//   // go Forward
//   digitalWrite(bleft, HIGH);
//   digitalWrite(bright, HIGH);
//   delay(300);
//   digitalWrite(bleft, LOW);
//   digitalWrite(bright, LOW);
//   delay(300);
//   // go Back
//   digitalWrite(fleft, HIGH);
//   digitalWrite(fright, HIGH);
//   delay(300);
//   digitalWrite(fleft, LOW);
//   digitalWrite(fright, LOW);
//   delay(300);
// }