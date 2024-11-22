#include <stdbool.h>
#include <stdio.h>
#include "utils.h"

bool checkIfRectangle(int* xPoints, int* yPoints) {
	int xConections[] = { 0, 0, 0 };

	//1st point checks
	int check = 0;
	if (xPoints[0] == xPoints[1]) {
		check++;
		xConections[0] = 2;
	}
	if (xPoints[0] == xPoints[2]) {
		check++;
		xConections[0] = 3;
	}
	if (xPoints[0] == xPoints[3]) {
		check++;
		xConections[0] = 4;
	}
	if (check != 1){
		return false;
	}

	check = 0;
	if (yPoints[0] == yPoints[1]) {
		check++;
	}
	if (yPoints[0] == yPoints[2]) {
		check++;
	}
	if (yPoints[0] == yPoints[3]) {
		check++;
	}
	if (check != 1) {
		return false;
	}

	//2nd point checks
	check = 0;
	if (xPoints[1] == xPoints[0]) {
		check++;
		xConections[1] = 1;
	}
	if (xPoints[1] == xPoints[2]) {
		check++;
		xConections[1] = 3;
	}
	if (xPoints[1] == xPoints[3]) {
		check++;
		xConections[1] = 4;
	}
	if (check != 1) {
		return false;
	}

	check = 0;
	if (yPoints[1] == yPoints[0]) {
		check++;
	}
	if (yPoints[1] == yPoints[2]) {
		check++;
	}
	if (yPoints[1] == yPoints[3]) {
		check++;
	}
	if (check != 1) {
		return false;
	}

	//3rd point checks
	check = 0;
	if (xPoints[2] == xPoints[0]) {
		check++;
		xConections[2] = 1;
	}
	if (xPoints[2] == xPoints[1]) {
		check++;
		xConections[2] = 2;
	}
	if (xPoints[2] == xPoints[3]) {
		check++;
		xConections[2] = 4;
	}
	if (check != 1) {
		return false;
	}

	check = 0;
	if (yPoints[2] == yPoints[0]) {
		check++;
	}
	if (yPoints[2] == yPoints[1]) {
		check++;
	}
	if (yPoints[2] == yPoints[3]) {
		check++;
	}
	if (check != 1) {
		return false;
	}

	//same point
	//1st point
	switch (xConections[0]) {
	case 2:
		if (yPoints[0] == yPoints[1]) {
			return false;
		}
		break;
	case 3:
		if (yPoints[0] == yPoints[2]) {
			return false;
		}
		break;
	case 4:
		if (yPoints[0] == yPoints[3]) {
			return false;
		}
		break;
	default:
		break;
	}

	//2st point
	switch (xConections[1]) {
	case 1:
		if (yPoints[1] == yPoints[0]) {
			return false;
		}
		break;
	case 3:
		if (yPoints[1] == yPoints[2]) {
			return false;
		}
		break;
	case 4:
		if (yPoints[1] == yPoints[3]) {
			return false;
		}
		break;
	default:
		break;
	}

	//3rd point
	switch (xConections[2]) {
	case 1:
		if (yPoints[2] == yPoints[0]) {
			return false;
		}
		break;
	case 2:
		if (yPoints[2] == yPoints[1]) {
			return false;
		}
		break;
	case 4:
		if (yPoints[2] == yPoints[3]) {
			return false;
		}
		break;
	default:
		break;
	}
}

void inputRectangle(int* rectangleX, int* rectangleY) {
	
	int result = 0;
	int firstPass = 0;
	while (!result) {
		
		if (firstPass) {
			printf("Invalid point entered, try again\n");
		}
		else {
			printf("Input rectangle values \n");
		}

		for (int i = 0; i < 4; i++) {
			printf("Enter X,Y: ");
			result = scanf_s("%d,%d", &rectangleX[i], &rectangleY[i]);
			clearInputBuffer();
		}

		firstPass++;
	}
	firstPass = 0;
}