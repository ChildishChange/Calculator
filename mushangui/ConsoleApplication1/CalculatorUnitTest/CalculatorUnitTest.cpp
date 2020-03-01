﻿#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
	TEST_CLASS(CalculatorUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("33+2");
			Assert::AreEqual(ret, (string)"33+2=35");
		}
		TEST_METHOD(TestMethod2)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("2*4");
			Assert::AreEqual(ret, (string)"2*4=8");
		}
		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("4/2");
			Assert::AreEqual(ret, (string)"4/2=2");
		}
		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("10/2");
			Assert::AreEqual(ret, (string)"10/2=5");
		}
	};
}
