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
		//enableObstSens();

		
		do
		{
		//	setVel2(50, 50);
			waitTick20ms();						// Wait for next 40ms tick
			readAnalogSensors();				// Fill in "analogSensors" structure
			groundSensor = readLineSensors(0);	// Read ground sensor
			printf("Obst_left=%03d, Obst_center=%03d, Obst_right=%03d, Bat_voltage=%03d, Ground_sens=", analogSensors.obstSensLeft,
					analogSensors.obstSensFront, analogSensors.obstSensRight, analogSensors.batteryVoltage);

			printInt(groundSensor, 2 | 5 << 16);	// System call
			short sen_0 = (groundSensor  & 0x01);
			short sen_1 = (groundSensor & 0x02)>>1;
			short sen_2 = (groundSensor & 0x04)>>2;
			short sen_3 = (groundSensor & 0x08)>>3;
			short sen_4 = (groundSensor & 0x10)>>4;


			/*if(!(sen_1|sen_2|sen_3)){
				setVel2(-52,-49);
			}else */
			/*if(!(sen_1&sen_3)){
				setVel2(0,0);
			}else */if(!sen_2){

				if(sen_1&sen_3){
					setVel2(52,49);
				}else if(!sen_3){
					setVel2(35,73);
				}else if(!sen_1){
					setVel2(75,33);
				}else{
					setVel2(52,49);
				}
			} else if(!sen_3){
				setVel2(20,97);
			}else if(!sen_1){
				setVel2(100,17);
			}else{
				setVel2(52,49);

			}


			printf("	%d %d %d %d %d ", sen_4, sen_3, sen_2, sen_1, sen_0);


			printf("\n");
		} while(!stopButton());
		setVel2(0, 0);
		//disableObstSens();
		
	}
	return 0;
}



