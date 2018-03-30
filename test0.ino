int enableA = 10;//2;
int pinA1 = 9;//1;
int pinA2 = 8;//0;
int enableB = 13;//7;
int pinB1 = 12;//6;
int pinB2 = 11;//5;

//Define Run variable
boolean run;
void setup() {
pinMode(enableA, OUTPUT);
pinMode(pinA1, OUTPUT);
pinMode(pinA2, OUTPUT);
pinMode(enableB, OUTPUT);
pinMode(pinB1, OUTPUT);
pinMode(pinB2, OUTPUT);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
Serial.begin(9600);
run = true;
}

//command sequence
void loop() {
      int r = digitalRead(A0);
      int l = digitalRead(A1);
      Serial.println(l);
      Serial.println(r);
  if(run)
  {
          //delay(2000);
          enableMotors();
          if (l == 0 && r == 0){
          forward(400);
          coast(100);
          }
          else if(l == 0 && r == 1){
            turnRight(200);
            coast(100);
          }
          else if(l == 1 && r == 0){
            turnLeft(200);
            coast(100);
          }
          else{
            backward(150);
            coast(100);
          }
          disableMotors();
  } 
}
void motorAOn()
{
digitalWrite(enableA, HIGH);
}
void motorBOn()
{
digitalWrite(enableB, HIGH);
}
//disable motors
void motorAOff()
{
digitalWrite(enableB, LOW);
}
void motorBOff()
{
digitalWrite(enableA, LOW);
}
//motor A controls
void motorAForward()
{
digitalWrite(pinA1, HIGH);
digitalWrite(pinA2, LOW);
}
void motorABackward()
{
digitalWrite(pinA1, LOW);
digitalWrite(pinA2, HIGH);
}
//motor B contorls
void motorBForward()
{
digitalWrite(pinB1, HIGH);
digitalWrite(pinB2, LOW);
}
void motorBBackward()
{
digitalWrite(pinB1, LOW);
digitalWrite(pinB2, HIGH);
}
//coasting and braking
void motorACoast()
{
digitalWrite(pinA1, LOW);
digitalWrite(pinA2, LOW);
}
void motorABrake()
{
digitalWrite(pinA1, HIGH);
digitalWrite(pinA2, HIGH);
}
void motorBCoast()
{

digitalWrite(pinB1, LOW);
digitalWrite(pinB2, LOW);
}
void motorBBrake()
{
digitalWrite(pinB1, HIGH);
digitalWrite(pinB2, HIGH);
}
//Define High Level Commands
void enableMotors()
{
motorAOn();
motorBOn();
}
void disableMotors()
{
motorAOff();
motorBOff();
}
void forward(int time)
{
motorAForward();
motorBForward();
delay(time);
}
void backward(int time)
{
motorABackward();
motorBBackward();
delay(time);
}
void turnLeft(int time)
{
motorABackward();
motorBForward();
delay(time);
}
void turnRight(int time)
{
motorAForward();
motorBBackward();
delay(time);
}
void coast(int time)
{
motorACoast();
motorBCoast();
delay(time);
}
void brake(int time)
{
motorABrake();
motorBBrake();
delay(time);
}

