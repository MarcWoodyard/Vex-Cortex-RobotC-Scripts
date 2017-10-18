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
 // 3/4 Power - 96
 // 1/2 Power - 63
 //  Full Power - 127
 
//Manual straightening for left motor. SLM (Straight Left Motor).
int SLM
void changeValue()
	{
		SLM = 60;
	}
 
   //Resetting encoder values.
   SensorValue[rightEncoder] = 0;
   SensorValue[leftEncoder] = 0;
    
    //First forward movement.
    while(SensorValue[leftEncoder] < 1850)
    {
        if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
        {
            motor[rightMotor] = 96;
            motor[leftMotor] = 80;
        }
        if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
        {
            motor[rightMotor] = 96;
            motor[leftMotor] = 80;
        }
        else(SensorValue[leftEncoder] == SensorValue[rightEncoder])
        {
            motor[rightMotor] = 96;
            motor[leftMotor] = SLM;
        }
    }
 
 	//Resetting encoder values.
 	SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;
 
    //First left turn.
    while(SensorValue[rightEncoder] <= 230)
    {
        motor[rightMotor] = 96;
        motor[leftMotor] = -96;
    }
 
    //Resetting encoder values.
    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;
 
    //Second forward movement.
    while(SensorValue[leftEncoder] < 1850)
    {
        if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
        {
            motor[rightMotor] = 96;
            motor[leftMotor] = 80;
        }
        if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
        {
            motor[rightMotor] = 80;
            motor[leftMotor] = 96;
        }
        else(SensorValue[leftEncoder] == SensorValue[rightEncoder])
        {
            motor[rightMotor] = 96;
            motor[leftMotor] = SLM;
        }
 
    }
	
	//Resetting encoder values.
    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;
	
	//Second right turn.
    while(SensorValue[rightEncoder] <= 230)
    {
        motor[rightMotor] = -96;
        motor[leftMotor] = 96;
    }

    //Third forward movement.
    while(SensorValue[leftEncoder] < 1850)
    {
        if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
        {
            motor[rightMotor] = 96;
            motor[leftMotor] = 80;
        }
        if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
        {
            motor[rightMotor] = 80;
            motor[leftMotor] = 96;
        }
        else(SensorValue[leftEncoder] == SensorValue[rightEncoder])
        {
            motor[rightMotor] = 96;
            motor[leftMotor] = SLM;
        }
 
    }

	//Resetting encoder values.
    SensorValue[rightEncoder] = 0;
    SensorValue[leftEncoder] = 0;

	//Thrid right turn.
    while(SensorValue[rightEncoder] <= 230)
    {
        motor[rightMotor] = -96;
        motor[leftMotor] = 96;
    }

}

