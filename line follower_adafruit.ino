#include<AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
void setup() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
}

void loop() {
  int irR = digitalRead(A0);//Right sensor
  int irM = digitalRead(A5);//Middle sensor
  int irL = digitalRead(A2);//Left sensor 

  if(irR==0 && irL==0 && irM==1)      // bot on track
  {   
      motor1.run(FORWARD);
      motor2.run(FORWARD);
  }
  else if(irR==1 && irL==0)         //track at right
  {   
      motor1.run(FORWARD);      
      motor2.run(RELEASE);
  }
  else if(irR==0 && irL==1)         //track at left
  {   
      motor2.run(FORWARD);
      motor1.run(RELEASE);
  }
  else if(irR==1 && irL==1 && irM==1)     //bot at finish
  {   
      motor2.run(FORWARD);
      motor1.run(FORWARD);
      
  }
  else                                    //bot misses path
  {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
  }
}
