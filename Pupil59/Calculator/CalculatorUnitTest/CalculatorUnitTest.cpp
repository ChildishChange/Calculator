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
			ret = calc->Solve("1+2");
			Assert::AreEqual(ret, (string)"1+2=3");
			ret = calc->Solve("11+22/11");
			Assert::AreEqual(ret, (string)"11+22/11=13");
			ret = calc->Solve("11*22");
			Assert::AreEqual(ret, (string)"11*22=242");
			ret = calc->Solve("22/11*2");
			Assert::AreEqual(ret, (string)"22/11*2=4");
			ret = calc->Solve("11*22-200+3");
			Assert::AreEqual(ret, (string)"11*22-200+3=45");
			ret = calc->Solve("0/22");
			Assert::AreEqual(ret, (string)"0/22=0");
			ret = calc->Solve("100*100");
			Assert::AreEqual(ret, (string)"100*100=10000");
		}
	};
}
