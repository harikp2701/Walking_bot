#include <Servo.h> 
Servo rightfoot;
Servo righthigh;
Servo leftfoot;
Servo lefthigh;
#define trigPin 11
#define echoPin 10
long duration;
int distance;
void setup() 
{ 

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  rightfoot.attach(3);
  righthigh.attach(5);
  leftfoot.attach(7);
  lefthigh.attach(9);
  righthigh.write(90);
  lefthigh.write(90);
  rightfoot.write(90);
  leftfoot.write(90);
}                                                                                      
 
//FORWARD
void forward()
{
  rightfoot.write(135);
  leftfoot.write(135);
  delay(100);
  lefthigh.write(125);
  delay(170);
  lefthigh.write(90);
  rightfoot.write(90);
  leftfoot.write(90);
  delay(150);
  rightfoot.write(45);
  leftfoot.write(45);
  delay(150);
  righthigh.write(45);
  delay(200);
  righthigh.write(90);
  rightfoot.write(90);
  leftfoot.write(90);
  delay(100);
}

//BACKWARD
void backward()
{
  rightfoot.write(135);
  leftfoot.write(135);
  delay(150);
  lefthigh.write(45);
  delay(250);
  lefthigh.write(90);
  rightfoot.write(90);
  leftfoot.write(90);
  delay(150);
  rightfoot.write(35);
  leftfoot.write(45);
  delay(150);
  righthigh.write(115);
  delay(200);
  righthigh.write(90);
  rightfoot.write(90);
  leftfoot.write(90);
  delay(150);
}

//TURN LEFT
void turnleft()
{
  rightfoot.write(145);
  leftfoot.write(135);
  delay(250);
  lefthigh.write(135);
  delay(250);
  leftfoot.write(90);
  rightfoot.write(90);
  delay(100);
  lefthigh.write(90);
  delay(250);
}

//TURN RIGHT
void turnright()
{
  rightfoot.write(45);
  leftfoot.write(25);
  delay(250);
  righthigh.write(45);
  delay(250);
  leftfoot.write(90);
  rightfoot.write(90);
  delay(150);
  righthigh.write(90);
  delay(250);
}

//MOVE RIGHT
void moveright()
{
  rightfoot.write(45);
  delay(200);
  leftfoot.write(45);
  delay(200);
  rightfoot.write(135);
  delay(200);
  leftfoot.write(135);
  delay(200);
}

//MOVE LEFT
void moveleft()
{
  rightfoot.write(45);
  delay(200);
  leftfoot.write(135);
  delay(200);
  rightfoot.write(135);
  delay(200);
  leftfoot.write(45);
  delay(200);
}

//DANCING 1
void dancing1()
{
  rightfoot.write(45);
  delay(200);
  leftfoot.write(45);
  delay(200);
  rightfoot.write(135);
  delay(200);
  leftfoot.write(135);
  delay(200);
  rightfoot.write(45);
  delay(200);
  leftfoot.write(135);
  delay(200);
  rightfoot.write(135);
  delay(200);
  leftfoot.write(45);
  delay(200);
}

//DANCING 2
//void dancing2()
//{
//  rightfoot.write(135);
//  leftfoot.write(45);
//  delay(150);
//  rightfoot.write(90);
//  leftfoot.write(90);
//  delay(150);
//  rightfoot.write(135);
//  leftfoot.write(45);
//  delay(300);
//  rightfoot.write(90);
//  leftfoot.write(90);
//  delay(300);
//}
//
////DANCING 3
//void dancing3()
//{
//  rightfoot.write(135);
//  leftfoot.write(45);
//  delay(150);
//  rightfoot.write(90);
//  leftfoot.write(90);
//  delay(150);
//  rightfoot.write(135);
//  leftfoot.write(45);
//  delay(300);
//  rightfoot.write(90);
//  leftfoot.write(90);
//  delay(300);
//  rightfoot.write(135);
//  leftfoot.write(45);
//  delay(450);
//  rightfoot.write(90);
//  leftfoot.write(90);
//  delay(450);
//}

//JUMP
void jump()
{
  for(int pos=90,pos1=90;pos<=170,pos1>=10;pos++,pos1--)
  {
    rightfoot.write(pos);
    leftfoot.write(pos1);
    delay(10);
  }
  for(int pos=170,pos1=10;pos<=90,pos1>=90;pos--,pos1++)
  {
    rightfoot.write(pos);
    leftfoot.write(pos1);
    delay(20);
  }
}

//DISTANCE
int getdistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
}
void loop()
{
  char Do;
  if(Serial.available()>0)
  {
    Do=Serial.read();
    switch(Do)
    {
      case 'F':
      forward();
      break;
      case 'B':
      backward();
      break;
      case 'R':
      turnright();
      break;
      case 'L':
      turnleft();
      break;
      case 'M': 
      moveright();
      break;
      case 'N':
      moveleft();
      break;
      case 'X':
      dancing1();
      break;
//      case 'Y':
//      dancing2();
//      break;
//      case 'Z':
//      dancing3();
//      break;
      case 'J':
      jump();
      break;
      
     
      }
    }
  }
