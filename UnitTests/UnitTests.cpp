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

		TEST_METHOD(analyzeTriangle_ScaleneTriangle_IsScalene) {
			// Arrange
			int side1 = 7;
			int side2 = 10;
			int side3 = 12;
			char* expected = "Scalene triangle";

			// Act
			char* actual = analyzeTriangle(side1, side2, side3);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(analyzeTriangle_IsoscelesTriangle_IsIsosceles) {
			// Arrange
			int side1 = 6;
			int side2 = 6;
			int side3 = 8;
			char* expected = "Isosceles triangle";

			// Act
			char* actual = analyzeTriangle(side1, side2, side3);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(analyzeTriangle_EquilateralTriangle_IsEquilateral) {
			// Arrange
			int side1 = 1;
			int side2 = 1;
			int side3 = 1;
			char* expected = "Equilateral triangle";

			// Act
			char* actual = analyzeTriangle(side1, side2, side3);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(analyzeTriangle_Invalid_IsInvalid) {
			// Arrange
			int side1 = 100;
			int side2 = 1;
			int side3 = 1;
			char* expected = "Not a triangle";

			// Act
			char* actual = analyzeTriangle(side1, side2, side3);

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(validateTriangleUnitTests) {
public:
	TEST_METHOD(validateTriangle_ValidTriangle_True) {
		// Arrange
		int a = 7;
		int b = 10;
		int c = 12;
		bool expected = true;

		// Act
		bool actual = validateTriangle(a, b, c);

		// Assert
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(validateTriangle_InvalidTriangle_False) {
		// Arrange
		int a = 7;
		int b = 100;
		int c = 12;
		bool expected = false;

		// Act
		bool actual = validateTriangle(a, b, c);

		// Assert
		Assert::AreEqual(expected, actual);
	}
	};

	TEST_CLASS(CheckIfRectangleTests) {
		TEST_METHOD(checkIfRectangle_ValidRectangle_True) {
			// Arrange
			int xPoints[4] = { 1, 2, 2, 1 };
			int yPoints[4] = { 2, 1, 2, 1 };
			bool expected = true;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_NegativePointsRectangle_True) {
			// Arrange
			int xPoints[4] = { 1, -1, 1, -1 };
			int yPoints[4] = { 1, 1, -1, -1 };
			bool expected = true;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_NegativeAndZeroPointsRectangle_True) {
			// Arrange
			int xPoints[4] = { 1, -1, 0, 0 };
			int yPoints[4] = { 0, 0, 1, -1 };
			bool expected = true;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_InvalidRectangle_False) {
			// Arrange
			int xPoints[4] = { 1, 20, 2, 1 };
			int yPoints[4] = { 2, 1, 2, 1 };
			bool expected = false;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};
}