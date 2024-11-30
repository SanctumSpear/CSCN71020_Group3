#include <stdio.h>
#include <stdbool.h>

#include "utils.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"


int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int choice = printShapeMenu();

		switch (choice)
		{
		case 0:
			continueProgram = false;
			
			break;
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* triResult = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", triResult);
			break;
		case 2:
			printf("selected rectangle\n");
			int rectangleX[4] = { 0 };
			int rectangleY[4] = { 0 };

			inputRectangle(rectangleX, rectangleY);
			char* rectResult = checkIfRectangle(&rectangleX, &rectangleY);
			if (rectResult) {
				double area = calculateRectangleArea(rectangleX, rectangleY);
				printf("Shape is a rectangle. Area: %.2f\n", area);
			}
			else {
				printf("Shape is NOT a rectangle");
			}
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}