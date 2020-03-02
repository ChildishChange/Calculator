#include "pch.h"
#include "CppUnitTest.h"
#include "../Caculator/Calculator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
	TEST_CLASS(CalculatorUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22*3");
			Assert::AreEqual(ret, (string)"11+22*3=77");

			Calculator* calc1 = new Calculator();
			string ret1 = calc1->Solve("11*22");
			Assert::AreEqual(ret1, (string)"11*22=242");

			Calculator* calc2 = new Calculator();
			string ret2 = calc2->Solve("11*0");
			Assert::AreEqual(ret2, (string)"11*0=0");

			Calculator* calc3 = new Calculator();
			string ret3 = calc3->Solve("1/1+1*0");
			Assert::AreEqual(ret3, (string)"1/1+1*0=1");
		}
	};
}
