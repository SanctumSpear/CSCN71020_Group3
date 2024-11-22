#include <stdio.h>
#include <stdbool.h>
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
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

int* getTriangleAngles(int* triangleSides) {
	int a = triangleSides[0];
	int b = triangleSides[1];
	int c = triangleSides[2];

	int angleA = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c));
	int angleB = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c));
	int angleC = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b));

	int angles[ANGLE_ARRAY_SIZE] = {angleA, angleB, angleC};
	return angles;
}