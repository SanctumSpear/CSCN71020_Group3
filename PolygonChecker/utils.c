#include <stdio.h>
#include "utils.h"

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Shape Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("0. Exit\n");
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");

	int shapeChoice = 0;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}