#include "rmi-mr32.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

void rotateRel_naive(double deltaAngle);

int calcNextState( int sensor ){
	
	
	
	/*if( !sen0 && !sen1 && sen2 && !sen3 && !sen4 ){
		return 0; //Forward
	}*/
	
	
	
	/*
	 * Return codes:0
	 * 
	 * 0 - Forward
	 * 1 - Adjustment turn to right
	 * 2 - Adjustment turn to left
	 * 3 - Normal turn to right
	 * 4 - Normal turn to left
	 * 5 - Hard turn to right
	 * 6 - Hard turn to left
	 */
	
}

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
			sensor = readLineSensors(0);
			//Only the middle sensor is active
			switch( sensor ) {
				case 0b00100:
					setVel2( 70, 70 );
					break;
				case 0b00110:
					setVel2( 70, 50 );
					break;
				case 0b01100:
					setVel2( 50, 70 );
					break;
				case 0b01000:
				case 0b11100:
					setVel2( 0, 70 );
					break;
				case 0b00010:
				case 0b00111:
					setVel2( 70, 0 );
					break;
				default:
					break;
			}


		} while(!stopButton());
		setVel2(0, 0);
		//disableObstSens();

	}
	return 0;



}



