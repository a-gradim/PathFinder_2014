#include "rmi-mr32.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "controlLib.h"

void rotateRel_naive(double deltaAngle);

/*int calcNextState( int sensor ){
	
	
	
	if( !sen0 && !sen1 && sen2 && !sen3 && !sen4 ){
		return 0; //Forward
	}
	
	
	
	
	 * Return codes:0
	 * 
	 * 0 - Forward
	 * 1 - Adjustment turn to right
	 * 2 - Adjustment turn to left
	 * 3 - Normal turn to right
	 * 4 - Normal turn to left
	 * 5 - Hard turn to right
	 * 6 - Hard turn to left
	 
	
}*/

int main(void)
{
	int sensor;

	initPIC32();
	closedLoopControl( false );
	setVel2(0, 0);

	printf("RMI-example, robot %d\n\n\n", ROBOT);

	while(1)
	{
		printf("Press start to continue\n");
		while(!startButton());
		do
		{
			//  try adding tick;
			waitTick20ms();
			sensor = readLineSensors(0);
			
			printf("Ground Sendor= ");
			printInt(sensor, 2 | 5 << 16);
			printf("\n");
			//Only the middle sensor is active
			followLine(sensor);
		} while(!stopButton());
		setVel2(0, 0);
		//disableObstSens();

	}
	return 0;



}



