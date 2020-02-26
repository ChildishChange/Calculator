#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
	TEST_CLASS(CalculatorUnitTest)
	{
	public:
		
		TEST_METHOD(TestDivByZero)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11/0");
			Assert::AreEqual(ret, (string)"ERROR");
		}
	};
}
