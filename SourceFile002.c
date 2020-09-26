#pragma config(Sensor, port1,  rightsensor,        sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port2,  leftsensor,        sensorVexIQ_ColorGrayscale)
#pragma config(Motor,  motor1,          leftMotor,     tmotorNone, openLoop, driveLeft)
#pragma config(Motor,  motor2,          rightMotor,    tmotorNone, openLoop, driveRight)

task main()
{
	int followLine = 1;// 1 if true 0 if false
	int rvalue = 2048;
	int lvalue= 2048;
	while(true){
		if(followLine == 1){
			if(SensorValue(rightsensor) > rvalue && SensorValue(leftsensor) > lvalue){
				motor[leftMotor]=50;
				motor[rightMotor]=50;
			}
			else if(SensorValue(rightsensor) > rvalue && SensorValue(leftsensor) < lvalue){
				motor[leftMotor]=50;
				motor[rightMotor]=40;
			}
			else if(SensorValue(rightsensor) < rvalue && SensorValue(leftsensor) > lvalue){
				motor[leftMotor]=40;
				motor[rightMotor]=50;
			}
			else if(SensorValue(rightsensor) < rvalue && SensorValue(leftsensor) < lvalue){
				motor[leftMotor]=-50;
				motor[rightMotor]=-50;
			}
		}
		else{
			// set left side motors
			motor[leftMotor] = (vexRT[Ch3] + vexRT[Ch4]);

			// set right side motors
			motor[rightMotor] = (vexRT[Ch3] - vexRT[Ch4]);

		}
	}
}
