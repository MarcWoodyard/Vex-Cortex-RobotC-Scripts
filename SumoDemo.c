Enter file contents he#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
	//*!Looks ok up here, no need to touch anything. Just carry on.*/


task main()
{

	//Make sure to set up the encoders. Wont work without them.
	
	
	//Motor power level range -127 to 127 (Full Power)
		//	3/4 Power - 96 
		//	1/2 Power - 63

	//wait1Msec(2000);
	
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	//First forward movement (1/2 power)
	while(SensorValue[leftEncoder] < 1260)
	{
		if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
		{
			motor[rightMotor] = 63;
			motor[leftMotor] = 50;
		}
		if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
		{
			motor[rightMotor] = 50;
			motor[leftMotor] = 63;
		}
		if(SensorValue[leftEncoder] == sensorValue[rightEncoder])
		{
			motor[rightMotor] = 63;
			motor[leftMotor] = 63;
		}
	}	
	
	/*
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	
	
	//First forward movement (3/4 power)
	while(SensorValue[leftEncoder] < 1260)
	{
		if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
		{
			motor[rightMotor] = 96;
			motor[leftMotor] = 85;
		}
		if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
		{
			motor[rightMotor] = 85;
			motor[leftMotor] = 96;
		}
		if(SensorValue[leftEncoder] == sensorValue[rightEncoder])
		{
			motor[rightMotor] = 96;
			motor[leftMotor] = 96;
		}
	}	

	//And if neither of the above work, then use this.
		// 3/4 Power.
	
	motor[leftMotor] = 96;
	motor[rightMotor] = 96; 
  	wait1Msec(3000);
	
		// 1/2 Power.
	
	motor[leftMotor] = 63;
	motor[rightMotor] = 63; 
	wait1Msec(3000); 
	
	//*!!That's all! Stop editing.!!*//

}
