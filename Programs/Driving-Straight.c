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

 //Motor power level range -127 to 127 (Full Power)
 // 1/4 Power - 31
 // 3/4 Power - 96
 // 1/2 Power - 63
 //  Full Power - 127

         //wait1Msec(2000);

   //Resetting encoder values.
   SensorValue[rightEncoder] = 0;
   SensorValue[leftEncoder] = 0;

    //First forward movement.
    while(SensorValue[leftEncoder] < 5000)
    {
        if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
          {
            motor[rightMotor] = 96;
            motor[leftMotor] = 60;
          }
       if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
          {
            motor[rightMotor] = 60;
            motor[leftMotor] = 96;
          }
          if(SensorValue[leftEncoder] == SensorValue[rightEncoder])
          {
            motor[rightMotor] = 96;
            motor[leftMotor] = 60;
          }
    }

	 	//Resetting encoder values.
	 	SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;

}
