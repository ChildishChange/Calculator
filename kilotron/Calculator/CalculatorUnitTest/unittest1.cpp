#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"

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
		}

		TEST_METHOD(TestMethod2)
		{
			Calculator *calc = new Calculator();
			string ret = calc->Solve("3*15");
			Assert::AreEqual(ret, (string)"3*15=45");
		}

		TEST_METHOD(TestMethod3)
		{
			Calculator *calc = new Calculator();
			string ret = calc->Solve("43-10+9");
			Assert::AreEqual(ret, (string)"43-10+9=42");
		}

	};
}