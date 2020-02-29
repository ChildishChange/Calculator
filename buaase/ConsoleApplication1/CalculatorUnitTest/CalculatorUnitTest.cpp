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
			Assert::AreEqual(ret, (string)"11+22=33");
		}
	};
}
