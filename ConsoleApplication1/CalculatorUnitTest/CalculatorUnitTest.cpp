#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
	TEST_CLASS(CalculatorUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("12+22-1");
			Assert::AreEqual(ret, (string)"12+22-1=33");
			
		}
	};
}
