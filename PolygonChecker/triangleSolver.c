#include <stdio.h>
#include <stdbool.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "triangleSolver.h"

#define ANGLE_ARRAY_SIZE		3

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	bool triangleCheck = validateTriangle(side1, side2, side3);
	if (!triangleCheck) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

bool validateTriangle(int a, int b, int c) {
	bool validTriangle = false;
	bool aCheck = false;
	bool bCheck = false;
	bool cCheck = false;

	if (b + c > a) {
		aCheck = true;
	}
	
	if (a + c > b) {
		bCheck = true;
	}
	
	if (a + b > c) {
		cCheck = true;
	}

	if (aCheck && bCheck && cCheck) {
		validTriangle = true;
	}

	return validTriangle;
}

int* getTriangleSides(int* triangleSides) {
	int firstPass = 0;
	int check = true;
	int result = 0;
	do {
		check = true;
		if (firstPass != 0) {
			printf_s("invalid value entered, please try again\n");
		}
		else {
			printf_s("Enter the three sides of the triangle: \n");
		}
		
		for (int i = 0; i < 3; i++)
		{
			result = scanf_s("%d", &triangleSides[i]);
			if (result != 1 || triangleSides[i] <= 0) {
				check = false;
			}
			clearInputBuffer();
		}
		firstPass++;
	} while (!check);

	return triangleSides;
}

int* getTriangleAngles(int* triangleSides) {
	int a = triangleSides[0];
	int b = triangleSides[1];
	int c = triangleSides[2];

	static int angles[ANGLE_ARRAY_SIZE];

	angles[0] = (int)round(acos(((double)(b * b) + (c * c) - (a * a)) / (2.0 * b * c)) * 180.0 / M_PI);
	angles[1] = (int)round(acos(((double)(a * a) + (c * c) - (b * b)) / (2.0 * a * c)) * 180.0 / M_PI);
	angles[2] = (int)round(acos(((double)(a * a) + (b * b) - (c * c)) / (2.0 * a * b)) * 180.0 / M_PI);

	return angles;
}