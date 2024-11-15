#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

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