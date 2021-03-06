//Brushless DC Motor Current Control Drive
//Arduino Mega2560 

int PhaseaUpper=2;
int PhaseaLower=3;
int PhasebUpper=4;
int PhasebLower=5;
int PhasecUpper=6;
int PhasecLower=7;

//These pins have attached interrupts 
int Halla=18
int Hallb=19
int Hallc=20

//States of HALL Sensors 
volatile int HALLA = LOW;
volatile int HALLB = LOW;
volatile int HALLC = LOW;

void setup()
{
pinMode(PhaseaUpper, OUTPUT);
pinMode(PhaseaLower, OUTPUT);
pinMode(PhasebUpper, OUTPUT);
pinMode(PhasebLower, OUTPUT);
pinMode(PhasecUpper, OUTPUT);
pinMode(PhasecLower, OUTPUT);  

pinMode(Halla, INPUT);
pinMode(Hallb, INPUT);
pinMode(Hallc, INPUT);

digitalWrite(PhaseaUpper, LOW);
digitalWrite(PhaseaLower, LOW);
digitalWrite(PhasebUpper, LOW);
digitalWrite(PhasebLower, LOW);
digitalWrite(PhasecUpper, LOW);
digitalWrite(PhasecLower, LOW);

HALLA = digitalRead(Halla);
HALLB = digitalRead(Hallb);
HALLC = digitalRead(Hallc);

attachInterrupt(digitalPinToInterrupt(Halla), blinka, CHANGE);
attachInterrupt(digitalPinToInterrupt(Hallb), blinkb, CHANGE);
attachInterrupt(digitalPinToInterrupt(Hallc), blinkc, CHANGE);

}

void loop()
{
/*
digitalWrite(PhaseaUpper, digitalRead(Halla));
digitalWrite(PhaseaLower, !digitalRead(Halla));
digitalWrite(PhasebUpper, digitalRead(Hallb));
digitalWrite(PhasebLower, !digitalRead(Hallb));
digitalWrite(PhasecUpper, digitalRead(Hallc));
digitalWrite(PhasecLower, !digitalRead(Hallc));
*/

digitalWrite(PhaseaUpper, HALLA);
digitalWrite(PhaseaLower, !HALLA);
digitalWrite(PhasebUpper, HALLB);
digitalWrite(PhasebLower, !HALLB);
digitalWrite(PhasecUpper, HALLC);
digitalWrite(PhasecLower, !HALLC);
}

void blinka() {HALLA = !HALLA;}
void blinkb() {HALLB = !HALLB;}
void blinkc() {HALLC = !HALLC;}
