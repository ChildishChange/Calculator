#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest1
{
	TEST_CLASS(CalculatorUnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("1-2+2*3");
			Assert::AreEqual(ret, (string)"1-2+2*3=5");
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
			string ret = calc->Solve("22/11");
			Assert::AreEqual(ret, (string)"22/11=2");
		}
		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22-11");
			Assert::AreEqual(ret, (string)"22-11=11");
		}
	};
}
