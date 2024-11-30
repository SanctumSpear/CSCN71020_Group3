#pragma once

typedef struct point {
	int x;
	int y;
} POINT;

POINT creatPoint(int x, int y );

POINT comparePoints(POINT lhs, POINT rhs);