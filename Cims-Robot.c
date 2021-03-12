#pragma config(Sensor, in1,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, dgtl1,  touch,          sensorTouch)
#pragma config(Motor,  port1,           light,         tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void control();
void followLine(int threshold, int timer);
task main()
{
	int threshold = 2680;//value for if the colorsensor is on the line or not
	int modeSelector = 0;
	int timer = 0;
	while(true){
	if(SensorValue[touch] == 1 && modeSelector == 0){
	 modeSelector=1;
	 wait(0.2);
	}
	else if(SensorValue[touch] == 1 && modeSelector == 1){
	 modeSelector=0;
	 wait(0.2);
	 }

	if(modeSelector == 0){
		followLine(threshold, timer);
		}
	else{
		control();
		}
	}
}

void followLine(int threshold, int timer){
	if(timer >= 200 && SensorValue(lineFollowerLEFT) > threshold && SensorValue(lineFollowerCENTER) > threshold && SensorValue(lineFollowerRIGHT) > threshold)
    {
    	timer++;
      motor[leftMotor]  = 0;
      motor[rightMotor] = 0;
    }
   else{
	   // Counter-steer left
			if(SensorValue(lineFollowerCENTER) > threshold)
	    {
	      // go straight
	      motor[leftMotor]  = 63;
	      motor[rightMotor] = 63;
	    }
	    else if(SensorValue(lineFollowerRIGHT) > threshold)
	    {
	    	timer = 0;
	      // counter-steer right:
	      motor[leftMotor]  = 63;
	      motor[rightMotor] = -63;
	    }
	    // LEFT sensor sees dark:
	    else if(SensorValue(lineFollowerLEFT) > threshold)
	    {
	      // counter-steer left:
	      motor[leftMotor]  = -63;
	      motor[rightMotor] = 63;
	    }

			else{
				motor[leftMotor]= 10 ;
					motor[rightMotor] = 10;
			}
		}
	}
	void control(){
		if(vexRT[Ch3] > 0.02 || vexRT[Ch4] > 0.02){
		motor[leftMotor] = (vexRT[Ch3] + vexRT[Ch4]);

				// set right side motors
			motor[rightMotor] = (vexRT[Ch3] - vexRT[Ch4]);
	}
	else{
		motor[leftMotor]= 0 ;
		motor[rightMotor] = 0;
		}
}
