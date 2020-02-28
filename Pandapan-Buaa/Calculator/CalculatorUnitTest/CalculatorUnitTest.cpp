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
			string ret = calc->Solve("12-2");
			Assert::AreEqual(ret, (string)"12-2=10");
		}
		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("12*2");
			Assert::AreEqual(ret, (string)"12*2=24");
		}

		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("12+12+12+12");
			Assert::AreEqual(ret, (string)"12+12+12+12=48");
		}

		TEST_METHOD(TestMethod5)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("5+5+5");
			Assert::AreEqual(ret, (string)"5+5+5=15");
		}

		TEST_METHOD(TestMethod6)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("5+5+50");
			Assert::AreEqual(ret, (string)"5+5+50=60");
		}

		TEST_METHOD(TestMethod7)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("5*10/50+5");
			Assert::AreEqual(ret, (string)"5*10/50+5=6");
		}
	};
}
