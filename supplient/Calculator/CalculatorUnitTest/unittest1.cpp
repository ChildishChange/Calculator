#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator//Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			Assert::AreEqual(calc->Solve("11+22"), (string)"33");
		}

		TEST_METHOD(one_mul_three)
		{
			Calculator* calc = new Calculator();
			Assert::AreEqual(calc->Solve("1*3"), (string)"3");
		}

		TEST_METHOD(three_operand)
		{
			Calculator* calc = new Calculator();
			Assert::AreEqual(calc->Solve("10*10+20"), (string)"120");
		}
	};
}