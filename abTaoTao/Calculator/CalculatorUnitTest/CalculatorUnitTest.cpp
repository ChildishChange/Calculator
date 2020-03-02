#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/calculator.h"
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
		TEST_METHOD(TestMethod2)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22-11");
			Assert::AreEqual(ret, (string)"22-11=11");
		}
		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22-11-1");
			Assert::AreEqual(ret, (string)"22-11-1=10");
		}
		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22-11*2");
			Assert::AreEqual(ret, (string)"22-11*2=0");
		}
		TEST_METHOD(TestMethod5)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22-11+88");
			Assert::AreEqual(ret, (string)"22-11+88=99");
		}
		TEST_METHOD(TestMethod6)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("12-1+7");
			Assert::AreEqual(ret, (string)"12-1+7=18");
		}
	};
}
