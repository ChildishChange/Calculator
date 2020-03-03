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
			string ret = calc->Solve("11+22+33");
			Assert::AreEqual(ret, (string)"11+22+33=66");
		}

		TEST_METHOD(TestMethod2)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22-11-11");
			Assert::AreEqual(ret, (string)"22-11-11=0");
		}

		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22*11-22");
			Assert::AreEqual(ret, (string)"22*11-22=220");
		}

		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22/11-1");
			Assert::AreEqual(ret, (string)"22/11-1=1");
		}

		TEST_METHOD(TestMethod5)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22-11*2");
			Assert::AreEqual(ret, (string)"22-11*2=0");
		}

		TEST_METHOD(TestMethod6)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22-22/2");
			Assert::AreEqual(ret, (string)"22-22/2=11");
		}
	};
}
