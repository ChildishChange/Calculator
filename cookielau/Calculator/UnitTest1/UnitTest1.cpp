#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("15/5+3-2");
			Assert::AreEqual(ret, (string)"15/5+3-2=4");
			ret = calc->Solve("13+17-1");
			Assert::AreEqual(ret, (string)"13+17-1=29");
			ret = calc->Solve("11*15-5");
			Assert::AreEqual(ret, (string)"11*15-5=160");
			ret = calc->Solve("3+10+4-16");
			Assert::AreEqual(ret, (string)"3+10+4-16=1");
		}
	};
}
