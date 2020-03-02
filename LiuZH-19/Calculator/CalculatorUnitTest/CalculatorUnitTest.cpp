#include "pch.h"
#include "CppUnitTest.h"

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
			string ret2 = calc->Solve("-11-2");
			Assert::AreEqual(ret2, (string)"-11-2=-13");
		}

		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret2 = calc->Solve("11-2*2");
			Assert::AreEqual(ret2, (string)"11-2*2=7");
		}

		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret2 = calc->Solve("3+12/6");
			Assert::AreEqual(ret2, (string)"3+12/6=5");
		}

		TEST_METHOD(TestMethod5)
		{
			Calculator* calc = new Calculator();
			string ret2 = calc->Solve("-11+13");
			Assert::AreEqual(ret2, (string)"-11+13=2");
		}


		
	};
}
