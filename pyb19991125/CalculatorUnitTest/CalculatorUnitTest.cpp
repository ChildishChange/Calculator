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
			string ret = calc->Solve("3+10+4-16");
			Assert::AreEqual(ret, (string)"3+10+4-16=1");
			//ret = calc->Solve("15÷5+3-2");
			//Assert::AreEqual(ret, (string)"15÷5+3-2=4");
		}
	};
}
