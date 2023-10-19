/*
 * main.c
 *
 *  Created on: Oct 18, 2023
 *      Author: HP
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum state
{
	OFF, ON
};
//struct to store state of vehicle
typedef struct {
	int enginestate;
	int ACstate;
	int vehiclespeed;
	int room_temp;
	int engine_temp_cont_state;
	int engine_temp;
} VehicleState;

//initialzing vehicle
VehicleState vehicle = { OFF, OFF, 25, 25, OFF, 120 };

/*
 *
 Function used to display vehicle state and checks if vehicle speed is 30
 *
 */
void display() {
	if (vehicle.vehiclespeed == 30) {
		vehicle.ACstate = ON;
		vehicle.engine_temp_cont_state = ON;
		vehicle.room_temp = (vehicle.room_temp * ((float) 5 / 4)) + 1;
	}
	//ENGINE STATE
	if (vehicle.enginestate == ON)
		printf("\nEngine is ON \n");
	else
		printf("\nEngine is OFF \n");
	//AC STATE
	if (vehicle.ACstate == ON)
		printf("AC is ON \n");
	else
		printf("AC is OFF \n");
//VEHICLE SPEED
	printf("Vehicle Speed: %d km/hr\n", vehicle.vehiclespeed);
//ROOM TEMP
	printf("Room Temperature: %d C\n", vehicle.room_temp);
//Engine temp controller state
	if (vehicle.engine_temp_cont_state == ON)
		printf("Engine Temperature Controller is ON \n");
	else
		printf("Engine Temperature Controller is OFF \n");
//Engine temp
	printf("Engine Temperature: %d C \n", vehicle.engine_temp);
}
/*
 *
 Function to set engine temp controller state and engine temperature according to the user input
 *
 */
void setEngine() {
	int temp;
	printf("Enter the engine temperature :\n");
	scanf(" %d", &temp);
	if ((temp < 100) || (temp > 150)) {
		vehicle.engine_temp_cont_state = ON;
		vehicle.engine_temp = 125;
	} else {
		vehicle.engine_temp_cont_state = OFF;
	}
}
/*
 *
 Function to set AC state and room temperature according to the user input
 *
 */
void setAC() {
	int temp;
	printf("Enter the room temperature :\n");
	scanf(" %d", &temp);
	if ((temp < 10) || (temp > 30)) {
		vehicle.ACstate = ON;
		vehicle.room_temp = 20;
	} else {
		vehicle.ACstate = OFF;
	}
}
/*
 *
 Function to set speed of vehicle according to the user input
 *
 */
void setSpeed() {
	char color;
	printf("Enter the required color (G/O/R):\n");
	scanf(" %c", &color);
	switch (color) {
	case 'g':
	case 'G':

		vehicle.vehiclespeed = 100;
		break;
	case 'o':
	case 'O':

		vehicle.vehiclespeed = 30;
		break;
	case 'r':
	case 'R':

		vehicle.vehiclespeed = 0;
		break;
	}
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	while (1) {
		char input, choice;
		printf("\na. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n\n");
		scanf(" %c", &input);
		switch (input) //for main menu
		{
		case 'a': {
			printf(" Turn on the vehicle engine\n");
			while (1) {
				printf("\na. Turn off the engine\n");
				printf("b. Set the traffic light color\n");
				printf("c. Set the room temperature (Temperature Sensor)\n");
				printf(
						"d. Set the engine temperature (Engine Temperature Sensor)\n");
				scanf(" %c", &choice);
				int turnoffflag = 0;
				switch (choice) // for sensor set menu
				{
				case 'a':
					printf(" Turn off the vehicle engine\n");
					turnoffflag = 1;
					break;
				case 'b':
					setSpeed();
					display();
					break;
				case 'c':
					setAC();
					display();
					break;
				case 'd':
					setEngine();
					display();
					break;
				} //switch choice
				if (turnoffflag == 1) //to get the user to the main menu
					break;
			} //while 1

		} //case a
			break;
		case 'b':
			printf(" Turn off the vehicle engine\n");
			break;
		case 'c':
			printf(" Quit the system\n\n");
			return 0;
			break;
		} //switch input

	} //while 1

} //main();
