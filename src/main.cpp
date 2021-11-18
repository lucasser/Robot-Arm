#include <Arduino.h>
#include "..\.pio\libdeps\uno\Servo\src\Servo.h"
//#include <Servo.h>

Servo servoA;
Servo servoB;
Servo servoC;
Servo servoD;
Servo servoE;
Servo servoF;
String inData;
String serVal;
int valPos;
//down;
  	int a = 10;
  	int b = 10;
	int c = 0;
  	int d = 0;
  	int e = 0;
  	int f = 40;
//up;
	int A = 170;
	int B = 180;
  	int C = 170;
  	int D = 180;
  	int E = 180;
  	int F = 130;
void setup(){
	servoA.attach(2); 
	servoB.attach(3);
	servoC.attach(4);
	servoD.attach(5);
	servoE.attach(6);
	servoF.attach(7);
	servoA.write(90);
	servoB.write(180);
	servoC.write(170);
	servoD.write(90);
	servoE.write(40);
	servoF.write(40);
	Serial.begin(9600);
	Serial.println("ready");
}
void checkVal(char servo, int pos) {
	if (pos < 90) {
		switch (servo) {
			case 'a':
				if (pos < a) {
					Serial.println("Sorry value too small");
				} else {
					servoA.write(pos);
				}
				break;
			case 'b':
				if (pos < b) {
					Serial.println("Sorry value too small");
				} else {
					servoB.write(pos);
				}
				break;
			case 'c':
				if (pos < c) {
					Serial.println("Sorry value too small");
				} else {
					servoC.write(pos);
				}
				break;
			case 'd':
				if (pos < d) {
					Serial.println("Sorry value too small");
				} else {
					servoD.write(pos);
				}
				break;
			case 'e':
				if (pos < e) {
					Serial.println("Sorry value too small");
				} else {
					servoE.write(pos);
				}
				break;
			case 'f':
				if (pos < f) {
					Serial.println("Sorry value too small");
				} else {
					servoF.write(pos);
				}
				break;
			default:
				Serial.println("Enter 'a,b,c,d,e,f'");
				return;
		}
	}
	if (pos >= 90) {
		switch (servo) {
			case 'a':
				if (pos > A) {
					Serial.println("Sorry value too big");
				} else {
					servoA.write(pos);
				}
				break;
			case 'b':
				if (pos > B) {
					Serial.println("Sorry value too big");
				} else {
					servoB.write(pos);
				}
				break;
			case 'c':
				if (pos > C) {
					Serial.println("Sorry value too big");
				} else {
					servoC.write(pos);
				}
				break;
			case 'd':
				if (pos > D) {
					Serial.println("Sorry value too big");
				} else {
					servoD.write(pos);
				}
				break;
			case 'e':
				if (pos > E) {
					Serial.println("Sorry value too big");
				} else {
					servoE.write(pos);
				}
				break;
			case 'f':
				if (pos > F) {
					Serial.println("Sorry value too big");
				} else {
					servoF.write(pos);
				}
				break;
			default:
				Serial.println("Enter 'a,b,c,d,e,f'");
				return;
		}
	}
}
void setServo(String inData) {
	valPos = inData.indexOf('-');
	checkVal(inData.charAt(valPos + 1), inData.substring(valPos + 3, inData.indexOf('\n')).toInt());
}
void loop(){
	if (Serial.available()){
		while (Serial.available() > 0) {
			char recieved = Serial.read();
			inData += recieved;
			if (recieved == '\n') {
				if (inData.substring(0,8) == "setServo") {
					Serial.println("setServo init");
					setServo(inData);
				}
				inData = "";
			}
		}
	}
}