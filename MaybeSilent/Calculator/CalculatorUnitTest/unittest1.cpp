#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");

			ret = calc->Solve("1+1");
			Assert::AreEqual(ret, (string)"1+1=2");

			ret = calc->Solve("99*1-5");
			Assert::AreEqual(ret , (string)"99*1-5=94");

			ret = calc->Solve("1+1+1");
			Assert::AreEqual(ret, (string)"1+1+1=3");

			ret = calc->Solve("99*99*99*99");
			Assert::AreEqual(ret, (string)"99*99*99*99=96059601");

			ret = calc->Solve("10/5/2");
			Assert::AreEqual(ret, (string)"10/5/2=1");

		}

	};
}