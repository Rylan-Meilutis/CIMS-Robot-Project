#pragma config(Sensor, in1,    lineFollowerRIGHT,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerLEFT,    sensorLineFollower)
#pragma config(Motor,  motor1,          leftMotor,     tmotorNone, openLoop, driveLeft)
#pragma config(Motor,  motor2,          rightMotor,    tmotorNone, openLoop, driveRight)

task main()
{
	int threshold = 2048;//value for if the colorsensor is on the line or not
	int timer = 0;//timer for timingout the motors spinning
	int modeSelector = 0;//0 for line follow one foe teliop

	while(modeSelector == 0){
			 if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = 63;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 63;
      motor[rightMotor] = 63;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 63;
    }

		else{
			motor[leftMotor]= 0 ;
				motor[rightMotor] = 0;
		}

	while(modeSelector == 1){
			// set left side motors
			motor[leftMotor] = (vexRT[Ch3] + vexRT[Ch4]);

			// set right side motors
			motor[rightMotor] = (vexRT[Ch3] - vexRT[Ch4]);

		}
}
}
