#include "CppUnitTest.h"
#include <stdbool.h>

extern "C" {
#include "../PolygonChecker/rectangleSolver.h"
#include "../PolygonChecker/utils.h"
#include "../PolygonChecker/triangleSolver.h"
#include "../PolygonChecker/point.h"
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

		TEST_METHOD(analyzeTriangle_NegativeSides_IsInvalid) {
			// Arrange
			int side1 = -100;
			int side2 = -24;
			int side3 = -39;
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

	TEST_METHOD(validateTriangle_NegativeLengthTriangle_False) {
		// Arrange
		int a = -7;
		int b = -100;
		int c = -12;
		bool expected = false;

		// Act
		bool actual = validateTriangle(a, b, c);

		// Assert
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(validateTriangle_EqualLengthTriangle_True) {
		// Arrange
		int a = 1;
		int b = 1;
		int c = 1;
		bool expected = true;

		// Act
		bool actual = validateTriangle(a, b, c);

		// Assert
		Assert::AreEqual(expected, actual);
	}

	};

	TEST_CLASS(CheckIfRectangleTests) {
		TEST_METHOD(checkIfRectangle_NormalRectangle_True) {
			// Arrange
			int xPoints[4] = { 1, 2, 2, 1 };
			int yPoints[4] = { 2, 1, 2, 1 };
			bool expected = true;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_ZeroRectangle_True) {
			// Arrange
			int xPoints[4] = { 0, 2, 2, 0 };
			int yPoints[4] = { 2, 0, 2, 0 };
			bool expected = true;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_NegativeRectangle_True) {
			// Arrange
			int xPoints[4] = { 1, -1, 1, -1 };
			int yPoints[4] = { 1, 1, -1, -1 };
			bool expected = true;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_ZeroNegativeRectangle_True) {
			// Arrange
			int xPoints[4] = { 0, -1, 0, -1 };
			int yPoints[4] = { 0, 0, -1, -1 };
			bool expected = true;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_ZeroNegativeRotatedRectangle_True) {
			// Arrange
			int xPoints[4] = { 1, -1, 0, 0 };
			int yPoints[4] = { 0, 0, 1, -1 };
			bool expected = true;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_ZeroRotatedRectangle_True) {
			// Arrange
			int xPoints[4] = { 2, 0, 1, 1 };
			int yPoints[4] = { 1, 1, 2, 0 };
			bool expected = true;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_RotatedRectangle_True) {
			// Arrange
			int xPoints[4] = { 3, 1, 2, 2 };
			int yPoints[4] = { 2, 2, 3, 1 };
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

		TEST_METHOD(checkIfRectangle_ZeroInvalidRectangle_False) {
			// Arrange
			int xPoints[4] = { 0, 3, 2, 0 };
			int yPoints[4] = { 2, 21, 0, 12 };
			bool expected = false;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_NegativeInvalidRectangle_False) {
			// Arrange
			int xPoints[4] = { -1, -7, -2, 1 };
			int yPoints[4] = { 2, 12134, -2, 1 };
			bool expected = false;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_ZeroNegativeInvalidRectangle_False) {
			// Arrange
			int xPoints[4] = { 0, -30, 2, 0 };
			int yPoints[4] = { 2, 1, 24, -1 };
			bool expected = false;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(checkIfRectangle_EqualPoints_False) {
			// Arrange
			int xPoints[4] = { 1, 1, 1, 2 };
			int yPoints[4] = { 1, 1, 2, 2 };
			bool expected = false;

			// Act
			bool actual = checkIfRectangle(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(CalculateRectangleAreaTests) {
	public:
		TEST_METHOD(calculateRectangleArea_PositiveCoordinates_CorrectArea) {
			// Arrange
			int xPoints[4] = { 1, 2, 2, 1 };
			int yPoints[4] = { 2, 1, 2, 1 };
			double expected = 1.0;

			// Act
			double actual = calculateRectangleArea(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(calculateRectangleArea_ZeroCoordinates_CorrectArea) {
			// Arrange
			int xPoints[4] = { 0, 2, 2, 0 };
			int yPoints[4] = { 2, 0, 2, 0 };
			double expected = 4.0;

			// Act
			double actual = calculateRectangleArea(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(calculateRectangleArea_NegativeCoordinates_CorrectArea) {
			// Arrange
			int xPoints[4] = { -1, 1, 1, -1 };
			int yPoints[4] = { 1, 1, -1, -1 };
			double expected = 4.0;

			// Act
			double actual = calculateRectangleArea(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(calculateRectangleArea_LargeCoordinates_CorrectArea) {
			// Arrange
			int xPoints[4] = { 1000, 5000, 5000, 1000 };
			int yPoints[4] = { 2000, 2000, 5000, 5000 };
			double expected = 12000000.0;

			// Act
			double actual = calculateRectangleArea(xPoints, yPoints);

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};
}