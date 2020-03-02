#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator/calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
	TEST_CLASS(CalculatorUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("20-30*2+1");
			Assert::AreEqual(ret, (string)"20-30*2+1=-39");//assert 断言
		}
	};
}
