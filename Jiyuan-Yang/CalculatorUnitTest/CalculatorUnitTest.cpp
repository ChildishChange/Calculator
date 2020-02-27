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
		TEST_METHOD(TestMethod2) {
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+33/3");
			Assert::AreEqual(ret, (string)"11+33/3=22");
		}
		TEST_METHOD(TestMethod3) {
			Calculator* calc = new Calculator();
			string ret = calc->Solve("99-33*3");
			Assert::AreEqual(ret, (string)"99-33*3=0");
		}
		TEST_METHOD(TestMethod4) {
			Calculator* calc = new Calculator();
			string ret = calc->Solve("3*6/2");
			Assert::AreEqual(ret, (string)"3*6/2=9");
		}
	};
}
