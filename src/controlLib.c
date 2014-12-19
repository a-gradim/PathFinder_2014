#include "controlLib.h"

void followLine(int sensor)
{
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
}