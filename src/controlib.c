#include "rmi-mr32.h"
#include <math.h>
#include <stdlib.h>

int i = 0;
int lastState = 0;
short mov[100];

void firstRun(int sensor)
{
	//pode ser preciso usar as combinacoes:00110,01100);
	switch(sensor){
		case 0b00100:
			setVel2(50,50);
			break;
		case 0b11100:
			lastState = sensor;
			setVel2(50,50);
			mov[i] = 's';
			break;
		case 0b00000: //cai em duas situacoes
			if(lastState == 0b11100){
				setVel2(50,70);
			}
			else{
				setVel2(-50,50);
			}
			setVel2(50,70)
			mov[i] = 'l';
			break;	
		case 0b00111:
			lastState = sensor;
			setVel2(70,50);
			mov[i] = 'r';
			break;
		case 0b11111:
		case 0b01110:
			lastState = sensor;
			setVel2(70,50);
			mov[i] = 'r';
			break;
	}
	i++;
}