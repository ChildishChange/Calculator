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
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");

			ret = calc->Solve("10*(2+3)*4");
			Assert::AreEqual(ret, (string)"10*(2+3)*4=200");

			ret = calc->Solve("3/3+10*2+5");
			Assert::AreEqual(ret, (string)"3/3+10*2+5=26");

			ret = calc->Solve("1+2-6/3+2*6");
			Assert::AreEqual(ret, (string)"1+2-6/3+2*6=13");
		}
	};
}
