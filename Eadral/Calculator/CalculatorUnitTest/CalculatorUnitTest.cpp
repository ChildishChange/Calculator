#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
	TEST_CLASS(CalculatorUnitTest)
	{
	public:
		TEST_METHOD(Test1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");
		}
		TEST_METHOD(Test2)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("87/1*2/1");
			Assert::AreEqual(ret, (string)"87/1*2/1=174");
		}
		TEST_METHOD(Test3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("36-20/2+28");
			Assert::AreEqual(ret, (string)"36-20/2+28=54");
		}
	};
}
