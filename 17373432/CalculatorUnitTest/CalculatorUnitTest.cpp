#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
	TEST_CLASS(CalculatorUnitTest)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret1 = calc->Solve("5-6*7+2");
			Assert::AreEqual(ret1, (string)"5-6*7+2=-35");
			string ret = calc->Solve("11+2-3");
			Assert::AreEqual(ret, (string)"11+2-3=10");
		}

	};
}
