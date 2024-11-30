#include "point.h"

POINT creatPoint(int x, int y) {
	POINT newPoint;
	newPoint.x = x;
	newPoint.y = y;
	return newPoint;
}

POINT comparePoints(POINT lhs, POINT rhs) {
	if (lhs.x < rhs.x) {
		return rhs;
	}
	else if (lhs.x > rhs.x) {
		return lhs;
	}
	else {
		if (lhs.y < rhs.y) {
			return rhs;
		}
		else {
			return lhs;
		}
	}
}