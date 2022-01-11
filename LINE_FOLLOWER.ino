int motR1=9;
int motR2=6;
int motL1=5;
int motL2=3;

int IRleft=13;
int IRright=12;
int IRmid=8;

int b=0b000;
int r1,r2,r3,sh;

void LEFT (void);
void RIGHT (void);
void REV(void);
void FOW (void);


void setup()
{
  pinMode(motR1,OUTPUT);
  pinMode(motR2,OUTPUT);
  pinMode(motL1,OUTPUT);
  pinMode(motL2,OUTPUT);

  pinMode(IRleft,INPUT);
  pinMode(IRmid,INPUT);
  pinMode(IRright,INPUT);

  analogWrite(motR1,255);
  analogWrite(motR2,0);
  analogWrite(motL1,255);
  analogWrite(motL2,0);
  delay(700);
}

void loop(){                      
  r1=digitalRead(IRleft);
  r2=digitalRead(IRmid);
  r3=digitalRead(IRright);
  sh=(r1<<2 | r2<<1 | r1<<0);

  if(sh==000)
  REV();
  else if(sh==001)
  LEFT();
  else if(sh==010)
  FOW();
  else if(sh==011)
  LEFT();
  else if(sh==100)
  RIGHT();
  else if(sh==110)
  RIGHT();
  else if(sh==111)
  FOW();
}

void LEFT (void)
{
  analogWrite(motR1,150);
  analogWrite(motR2,0);
  analogWrite(motL1,60);
  analogWrite(motL2,0);
}

void RIGHT (void)
{
  analogWrite(motR1,60);
  analogWrite(motR2,0);
  analogWrite(motL1,150);
  analogWrite(motL2,0);
}

void FOW (void)
{
  analogWrite(motR1,255);
  analogWrite(motR2,0);
  analogWrite(motL1,255);
  analogWrite(motL2,0);
}

void REV (void)
{
  analogWrite(motR1,0);
  analogWrite(motR2,255);
  analogWrite(motL1,0);
  analogWrite(motL2,255);
}
