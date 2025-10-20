#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../BCSRec/main.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
	TEST_CLASS(RectangleTests)
	{
	public:
		
		//Test for getArea
		TEST_METHOD(Test_GetArea)
		{
			int length = 10;
			int width = 5;

			int result = getArea(&length, &width);
			Assert::AreEqual(50, result);     //10 * 5 = 50
		}

		//Test for getPerimeter
		TEST_METHOD(Test_GetPerimeter)
		{
			int length = 10;
			int width = 5;
			int result = getPerimeter(&length, &width);
			Assert::AreEqual(30, result);  //2 * (10 + 5) = 30
		}

		//Tests for setLength
		TEST_METHOD(Test_SetLength_ValidValue)
		{
			int length = 1;
			setLength(10, &length);
			Assert::AreEqual(10, length);
		}

		TEST_METHOD(Test_SetLength_MinValue)
		{
			int length = 5;
			setLength(1, &length);  //edge case: minimum allowed
			Assert::AreEqual(1, length);
		}

		TEST_METHOD(Test_SetLength_InvalidValue)
		{
			int length = 5;
			setLength(150, &length); //invalid, should not change
			Assert::AreEqual(5, length);
		}

		//Tests for setWidth
		TEST_METHOD(Test_SetWidth_ValidValue)
		{
			int width = 1;
			setWidth(20, &width);
			Assert::AreEqual(20, width);
		}

		TEST_METHOD(Test_SetWidth_MinValue)
		{
			int width = 10;
			setWidth(1, &width);
			Assert::AreEqual(1, width);
		}

		TEST_METHOD(Test_SetWidth_InvalidValue)
		{
			int width = 5;
			setWidth(0, &width);
			Assert::AreEqual(5, width);
		}
	};
}
