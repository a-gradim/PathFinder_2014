#include "rmi-mr32.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

void rotateRel_naive(double deltaAngle);

int main(void)
{
	int groundSensor;

	initPIC32();
	closedLoopControl( false );
	setVel2(0, 0);

	printf("RMI-example, robot %d\n\n\n", ROBOT);

	while(1)
	{
		printf("Press start to continue\n");
		while(!startButton());
		enableObstSens();

		
		do
		{
			setVel2(50, 50);
			waitTick40ms();						// Wait for next 40ms tick
			readAnalogSensors();				// Fill in "analogSensors" structure
			groundSensor = readLineSensors(0);	// Read ground sensor
			printf("Obst_left=%03d, Obst_center=%03d, Obst_right=%03d, Bat_voltage=%03d, Ground_sens=", analogSensors.obstSensLeft,
							analogSensors.obstSensFront, analogSensors.obstSensRight, analogSensors.batteryVoltage);

			printInt(groundSensor, 2 | 5 << 16);	// System call
			printf("\n");
		} while(!stopButton());
		setVel2(0, 0);
		disableObstSens();
		
	}
	return 0;
}



