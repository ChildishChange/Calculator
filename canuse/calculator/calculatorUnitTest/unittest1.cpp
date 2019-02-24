#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/calculator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace calculatorUnitTest
{		
	TEST_CLASS(UnitTest1)
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
			string ret = calc->Solve("11*22");
			Assert::AreEqual(ret, (string)"11*22=242");
		}
		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22+11");
			Assert::AreEqual(ret, (string)"11+22+11=44");
		}
		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("1+1+1+11");
			Assert::AreEqual(ret, (string)"1+1+1+11=14");
		}

	};
}