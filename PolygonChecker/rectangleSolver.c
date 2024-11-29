#include <stdbool.h>
#include <stdio.h>
#include "utils.h"

bool checkIfRectangle(int* xPoints, int* yPoints) {
	int xConections[] = { 0, 0, 0 };
	int v1[] = { 0,0 };
	int v2[] = { 0,0 };
	int v3[] = { 0,0 };
	int check = 0;

	//1st point checks
	v1[0] = xPoints[1] - xPoints[0];
	v1[1] = yPoints[1] - yPoints[0];
	v2[0] = xPoints[2] - xPoints[0];
	v2[1] = yPoints[2] - yPoints[0];
	v3[0] = xPoints[3] - xPoints[0];
	v3[1] = yPoints[3] - yPoints[0];
	if (dotProduct(v1, v2) == 0 || dotProduct(v2, v3) == 0 || dotProduct(v3, v1) == 0) {
		//2nd point checks
		v1[0] = xPoints[0] - xPoints[1];
		v1[1] = yPoints[0] - yPoints[1];
		v2[0] = xPoints[2] - xPoints[1];
		v2[1] = yPoints[2] - yPoints[1];
		v3[0] = xPoints[3] - xPoints[1];
		v3[1] = yPoints[3] - yPoints[1];
		if (dotProduct(v1, v2) == 0 || dotProduct(v2, v3) == 0 || dotProduct(v3, v1) == 0) {
			//3rd point checks
			v1[0] = xPoints[0] - xPoints[2];
			v1[1] = yPoints[0] - yPoints[2];
			v2[0] = xPoints[1] - xPoints[2];
			v2[1] = yPoints[1] - yPoints[2];
			v3[0] = xPoints[3] - xPoints[2];
			v3[1] = yPoints[3] - yPoints[2];
			if (dotProduct(v1, v2) == 0 || dotProduct(v2, v3) == 0 || dotProduct(v3, v1) == 0) {
				//4th point checks
				v1[0] = xPoints[0] - xPoints[3];
				v1[1] = yPoints[0] - yPoints[3];
				v2[0] = xPoints[1] - xPoints[3];
				v2[1] = yPoints[1] - yPoints[3];
				v3[0] = xPoints[2] - xPoints[3];
				v3[1] = yPoints[2] - yPoints[3];
				if (dotProduct(v1, v2) == 0 || dotProduct(v2, v3) == 0 || dotProduct(v3, v1) == 0) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void inputRectangle(int* rectangleX, int* rectangleY) {
	
	int result = 0;
	int firstPass = 0;
	int check = 2;
	do {
		
		if (firstPass != 0) {
			printf("Invalid point entered, try again\n");
		}
		else {
			printf("Input rectangle values \n");
		}

		for (int i = 0; i < 4; i++) {
			printf("Enter X,Y: ");
			result = scanf_s("%d,%d", &rectangleX[i], &rectangleY[i]);
			if (result != 2) {
				check = result;
			}
			clearInputBuffer();
		}

		firstPass++;
	} 
	while (check != 2);
	firstPass = 0;
}