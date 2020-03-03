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
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("10+21*2");
			Assert::AreEqual(ret, (string)"10+21*2=52");
		}

		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("3*60-2");
			Assert::AreEqual(ret, (string)"3*60-2=178");
		}

		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("23-3*10+22");
			Assert::AreEqual(ret, (string)"23-3*10+22=15");
		}

		TEST_METHOD(TestMethod5)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("10*3-21/7");
			Assert::AreEqual(ret, (string)"10*3-21/7=27");
		}

		TEST_METHOD(TestMethod6)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("10-3+21+7");
			Assert::AreEqual(ret, (string)"10-3+21+7=35");
		}

		TEST_METHOD(TestMethod7)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("10*3*2-7");
			Assert::AreEqual(ret, (string)"10*3*2-7=53");
		}

		TEST_METHOD(TestMethod8)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("30/3*2*7");
			Assert::AreEqual(ret, (string)"30/3*2*7=140");
		}

	};
}