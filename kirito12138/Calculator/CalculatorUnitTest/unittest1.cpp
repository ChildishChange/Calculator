#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Calculator/calculator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");

			ret = calc->Solve("22-11");
			Assert::AreEqual(ret, (string)"22-11=11");

			ret = calc->Solve("3*5");
			Assert::AreEqual(ret, (string)"3*5=15");

			ret = calc->Solve("15/3");
			Assert::AreEqual(ret, (string)"15/3=5");
		}

	};
}