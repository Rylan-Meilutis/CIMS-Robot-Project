#pragma config(Sensor, port1,  rightsensor,        sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port2,  leftsensor,        sensorVexIQ_ColorGrayscale)
#pragma config(Motor,  motor1,          leftMotor,     tmotorNone, openLoop, driveLeft)
#pragma config(Motor,  motor2,          rightMotor,    tmotorNone, openLoop, driveRight)

task main()
{
	int cValue = 2048;//value for if the colorsensor is on the line or not
	int timer = 0;//timer for timingout the motors spinning
	int modeSelector = 0;//0 for line follow one foe teliop

	while(modeSelector == 0){
			if(SensorValue(rightsensor) > cValue && SensorValue(leftsensor) > cValue){
				motor[leftMotor] = 50;
				motor[rightMotor] = 50;
			}
			else if(SensorValue(rightsensor) > cValue && SensorValue(leftsensor) < cValue){
				motor[leftMotor] = 50;
				motor[rightMotor] = 40;
			}
			else if(SensorValue(rightsensor) < cValue && SensorValue(leftsensor) > cValue){
				motor[leftMotor] = 40;
				motor[rightMotor] = 50;
			}
			else if(SensorValue(rightsensor) < cValue && SensorValue(leftsensor) < cValue && timer <= 200){
				motor[leftMotor] = -50;
				motor[rightMotor] = -50;
				timer++;
			}
		else{
			motor[leftMotor]= 0 ;
			motor[rightMotor] = 0;
		}
	}
	while(modeSelector == 1){
			// set left side motors
			motor[leftMotor] = (vexRT[Ch3] + vexRT[Ch4]);

			// set right side motors
			motor[rightMotor] = (vexRT[Ch3] - vexRT[Ch4]);

		}
}
