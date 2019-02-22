#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/calculator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest1
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
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("25/5");
			Assert::AreEqual(ret, (string)"25/5=5");
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("1+2*3");
			Assert::AreEqual(ret, (string)"1+2*3=7");
		}

	};
}