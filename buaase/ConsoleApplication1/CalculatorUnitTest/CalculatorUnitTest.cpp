#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/calculator.h"
#include "../ConsoleApplication1/ConsoleApplication1.cpp"


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
			Assert::AreEqual(calc->Solve("11+22"), (string)"11+22=33");
			Assert::AreEqual(calc->Solve("1+2+3"), (string)"1+2+3=6");
			Assert::AreEqual(calc->Solve("12+2-1"), (string)"12+2-1=13");
			Assert::AreEqual(calc->Solve("11+22"), (string)"11+22=33");
			Assert::AreEqual(calc->Solve("11+22"), (string)"11+22=33");
		}
	};
}
