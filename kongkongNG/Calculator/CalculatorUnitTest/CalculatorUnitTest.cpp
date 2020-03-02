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
			/*ret = calc->Solve("2*2*2");
			Assert::AreEqual(ret, (string)"2*2*2=8");
			ret = calc->Solve("15+8*20");
			Assert::AreEqual(ret, (string)"15+8*20=175");
			ret = calc->Solve("5-40/8");
			Assert::AreEqual(ret, (string)"5-40/8=0");
			ret = calc->Solve("5-40/7");
			Assert::AreEqual(ret, (string)"wrong");*/
		}
	};
}
