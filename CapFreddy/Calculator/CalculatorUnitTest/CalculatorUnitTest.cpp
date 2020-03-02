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

			// 2 op
			Assert::AreEqual(calc->Solve("8+8-7"), (string)"8+8-7=9");
			Assert::AreEqual(calc->Solve("8+8/8"), (string)"8+8/8=9");
			Assert::AreEqual(calc->Solve("8+8*8"), (string)"8+8*8=72");
			Assert::AreEqual(calc->Solve("13+17-1"), (string)"13+17-1=29");
			Assert::AreEqual(calc->Solve("11*15-5"), (string)"11*15-5=160");

			// 3 op
			Assert::AreEqual(calc->Solve("3+10+4-16"), (string)"3+10+4-16=1");
			Assert::AreEqual(calc->Solve("15/5+3-2"), (string)"15/5+3-2=4");
			Assert::AreEqual(calc->Solve("15/3-2*3"), (string)"15/3-2*3=-1");
		}
	};
}
