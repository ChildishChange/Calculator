#include "stdafx.h"
#include "CppUnitTest.h"
#include "../buaase_0/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();

			string ret = calc->Solve("11+22*33");
			Assert::AreEqual(ret, (string)"11+22*33=737");
		}

		TEST_METHOD(TestMethod2)
		{
			Calculator* calc = new Calculator();

			string ret = calc->Solve("22*33-11");
			
			Assert::AreEqual(ret, (string)"22*33-11=715");
		}
		
		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();

			string ret = calc->Solve("11-22*33");

			Assert::AreEqual(ret, (string)"11-22*33=-715");
		}

		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();

			string ret = calc->Solve("22-33/11");

			Assert::AreEqual(ret, (string)"22-33/11=19");
		}
		TEST_METHOD(TestMethod5)
		{
			Calculator* calc = new Calculator();

			string ret = calc->Solve("33/11-2");

			Assert::AreEqual(ret, (string)"33/11-2=1");
		}

	};
}