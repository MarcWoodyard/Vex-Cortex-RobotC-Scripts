#pragma config(Sensor, in6,    armEncoder,     sensorPotentiometer)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  frontLimit,     sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           armMotor,      tmotorServoContinuousRotation, openLoop)
//Ports and sensors on the correct sides.
task main()
{
 		// Motor at 1/4 power.
		motor[leftMotor] = 31;
		motor[rightMotor] = 31;

		wait1Msec(1000);

		//Motor at 1/2 power.
		motor[leftMotor] = 63;
		motor[rightMotor] = 63;

		wait1Msec(1000);

		//Motor at 3/4 power.
		motor[leftMotor] = 96;
		motor[rightMotor] = 96;

		wait1Msec(1000);

		//Motor at full power.
		motor[leftMotor] = 127;
		motor[rightMotor] = 127;

		wait1Msec(1000);

}
