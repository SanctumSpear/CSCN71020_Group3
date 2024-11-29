#include "CppUnitTest.h"
#include <stdbool.h>

extern "C" {
	#include "../PolygonChecker/rectangleSolver.h"
	#include "../PolygonChecker/utils.h"
	#include "../PolygonChecker/triangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(analyzeTriangleUnitTests)
	{
	public:
		
		TEST_METHOD(analyzeTriangle_ScaleneTriangle_IsScalene){
			int side1 = 7;
			int side2 = 10;
			int side3 = 12;
			char* expected = "Scalene triangle";
			
			Assert::AreEqual(expected, analyzeTriangle(side1, side2, side3));
		}

		TEST_METHOD(analyzeTriangle_IsoscelesTriangle_IsIsosceles) {
			int side1 = 6;
			int side2 = 6;
			int side3 = 8;
			char* expected = "Isosceles triangle";

			Assert::AreEqual(expected, analyzeTriangle(side1, side2, side3));
		}

		TEST_METHOD(analyzeTriangle_EquilateralTriangle_IsEquilateral) {
			int side1 = 1;
			int side2 = 1;
			int side3 = 1;
			char* expected = "Equilateral triangle";

			Assert::AreEqual(expected, analyzeTriangle(side1, side2, side3));
		}

		TEST_METHOD(analyzeTriangle_Invalid_IsInvalid) {
			int side1 = 100;
			int side2 = 1;
			int side3 = 1;
			char* expected = "Not a triangle";

			Assert::AreEqual(expected, analyzeTriangle(side1, side2, side3));
		}
	};

	TEST_CLASS(validateTriangleUnitTests) {
	public:
		TEST_METHOD(validateTriangle_ValidTriangle_True) {
			int a = 7;
			int b = 10;
			int c = 12;
			bool expected = true;
			Assert::AreEqual(expected, validateTriangle(a, b, c));
		}

		TEST_METHOD(validateTriangle_InvalidTriangle_False) {
			int a = 7;
			int b = 100;
			int c = 12;
			bool expected = false;
			Assert::AreEqual(expected, validateTriangle(a, b, c));
		}

	};

	TEST_CLASS(CheckIfRectangleTests) {
		TEST_METHOD(checkIfRectangle_ValidRectangle_True) {
			int xPoints[4] = {1, 2, 2, 1};
			int yPoints[4] = {2, 1, 2, 1};
			bool expected = true;
			Assert::AreEqual(expected, checkIfRectangle(xPoints, yPoints));
		}
		TEST_METHOD(checkIfRectangle_ValidRectangle_True) {
			int xPoints[4] = { 1, -1, 1, -1 };
			int yPoints[4] = { 1, 1, -1, -1 };
			bool expected = true;
			Assert::AreEqual(expected, checkIfRectangle(xPoints, yPoints));
		}
		TEST_METHOD(checkIfRectangle_ValidRectangle_True) {
			int xPoints[4] = { 1, -1, 0, 0 };
			int yPoints[4] = { 0, 0, 1, -1 };
			bool expected = true;
			Assert::AreEqual(expected, checkIfRectangle(xPoints, yPoints));
		}
		TEST_METHOD(checkIfRectangle_InvalidRectangle_False) {
			int xPoints[4] = { 1, 20, 2, 1 };
			int yPoints[4] = { 2, 1, 2, 1 };
			bool expected = false;
			Assert::AreEqual(expected, checkIfRectangle(xPoints, yPoints));
		}
	};
}
