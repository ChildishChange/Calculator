#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// This is local version

namespace CalculatorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+32");
			Assert::AreEqual(ret, (string)"11+32=33");
		}

		TEST_METHOD(TestMethod2)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("56-43");
			Assert::AreEqual(ret, (string)"56-43=13");
		}

		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("13*15");
			Assert::AreEqual(ret, (string)"13*15=195");
		}

		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("49/7");
			Assert::AreEqual(ret, (string)"49/7=7");
		}

		TEST_METHOD(TestMethod5)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("2*3-4");
			Assert::AreEqual(ret, (string)"2*3-4=2");
		}

		TEST_METHOD(TestMethod6)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("2*3");
			Assert::AreEqual(ret, (string)"2*3=6");
		}

	};
}