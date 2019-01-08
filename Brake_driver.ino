//Connect brake1 gate to Pin 9 and potentiometer to A0 to have variable control over pin 9.


//Libraries

#include <Settimino.h> //Communication with S7PLC

//Setting brake inputs and outputs
//Brake 1 setup
const int pot1 = A0; //Analog in1
const int brake1 = 3; //PWM out1
int scaledpot1 = 0; //Potentiometer scaled value
int pwm1 = 0; //PWM value

//Brake 2 setup
const int pot2 = A1; //Analog in2
const int brake2 = 5; //PWM out2
int scaledpot2 = 0; //Potentiometer scaled value
int pwm2 = 0; //PWM value

//Brake 3 setup
const int pot3 = A2; //Analog in3
const int brake3 = 6; //PWM out3
int scaledpot3 = 0; //Potentiometer scaled value
int pwm3 = 0; //PWM value

//Brake 4 setup
const int pot4 = A3; //Analog in4
const int brake4 = 9; //PWM out4
int scaledpot4 = 0; //Potentiometer scaled value
int pwm4 = 0; //PWM value

//Brake 5 setup
const int pot5 = A4; //Analog in5
const int brake5 = 10; //PWM out5
int scaledpot5 = 0; //Potentiometer scaled value
int pwm5 = 0; //PWM value

//Brake 6 setup
const int pot6 = A5; //Analog in6
const int brake6 = 11; //PWM out6
int scaledpot6 = 0; //Potentiometer scaled value
int pwm6 = 0; //PWM value

//DIP switch mapping
int dipPins[] = {0, 1, 2, 4, 7, 8, 12, 13}; //DIP Switch Pins
int transAddress;

void setup() {
//Defining the pinmodes
pinMode(brake1, OUTPUT);
pinMode(brake2, OUTPUT);
pinMode(brake3, OUTPUT);
pinMode(brake4, OUTPUT);
pinMode(brake5, OUTPUT);
pinMode(brake6, OUTPUT);

//DIP switch scanning
int i;
 for(i = 0; i<=7; i++)
 {
 pinMode(dipPins[i], INPUT);      // sets the digital pin 2-5 as input
 digitalWrite(dipPins[i], HIGH); //Set pullup resistor on
 }
 transAddress = address();
 delay(100);
 
Serial.begin(9600); //Baud rate for serial debugging
}

void loop() {
  
//Reading analog value
scaledpot1 = analogRead(pot1); //Read and store potentiometer values every loops
pwm1 = map(scaledpot1, 0, 1023, 0 , 255); // Scaling the scaledpot1 between 0 to 255
//Writing PWM to brake1 gate
analogWrite(brake1,pwm1); // Write pot value to the brake1 gate

//Reading analog value
scaledpot2 = analogRead(pot2); //Read and store potentiometer values every loops
pwm2 = map(scaledpot1, 0, 1023, 0 , 255); // Scaling the scaledpot1 between 0 to 255
//Writing PWM to brake2 gate
analogWrite(brake2,pwm2); // Write pot value to the brake1 gate

//Reading analog value
scaledpot3 = analogRead(pot3); //Read and store potentiometer values every loops
pwm3 = map(scaledpot3, 0, 1023, 0 , 255); // Scaling the scaledpot1 between 0 to 255
//Writing PWM to brake3 gate
analogWrite(brake3,pwm3); // Write pot value to the brake1 gate

//Reading analog value
scaledpot4 = analogRead(pot4); //Read and store potentiometer values every loops
pwm4 = map(scaledpot4, 0, 1023, 0 , 255); // Scaling the scaledpot1 between 0 to 255
//Writing PWM to brake4 gate
analogWrite(brake4,pwm4); // Write pot value to the brake1 gate

//Reading analog value
scaledpot5 = analogRead(pot5); //Read and store potentiometer values every loops
pwm5 = map(scaledpot5, 0, 1023, 0 , 255); // Scaling the scaledpot1 between 0 to 255
//Writing PWM to brake5 gate
analogWrite(brake5,pwm5); // Write pot value to the brake1 gate

//Reading analog value
scaledpot6 = analogRead(pot6); //Read and store potentiometer values every loops
pwm6 = map(scaledpot6, 0, 1023, 0 , 255); // Scaling the scaledpot1 between 0 to 255
//Writing PWM to brake6 gate
analogWrite(brake6,pwm6); // Write pot value to the brake1 gate


//Diagnostics
Serial.print("pot =");
Serial.print(scaledpot1);
Serial.print("brake1 =");
Serial.print(pwm1);

//General delay
delay(10); //Small delay to smooth things out, remove noise etc
}

////////////Common feature////////////////
//Create Address from DIP Switch (8 positions used)
byte address(){
 int i,j=0;
 
 //Get the switches state
 for(i=0; i<=7; i++){
 j = (j << 1) | digitalRead(dipPins[i]);   // read the input pin
 }
 return j; //return address
}
