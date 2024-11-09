#include <stdbool.h>

bool checkIfRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int xConections[] = { 0, 0, 0 };
	int xPoints[] = { x1, x2, x3, x4 };
	int yPoints[] = { y1, y2, y3, y4 };

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