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
		
		TEST_METHOD(Test_GetArea)
		{
			int length = 10;
			int width = 5;

			int result = getArea(&length, &width);
			Assert::AreEqual(50, result);     //10 * 5 = 50
		}

		TEST_METHOD(Test_GetPerimeter)
		{
			int length = 10;
			int width = 5;
			int result = getPerimeter(&length, &width);
			Assert::AreEqual(30, result);  //2 * (10 + 5) = 30
		}

	};
}
