#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/calculator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret1 = calc->Solve("3+11*22");
			Assert::AreEqual(ret1, (string)"3+11*22=245");
			string ret2 = calc->Solve("3-5+2+3");
			Assert::AreEqual(ret2, (string)"3-5+2+3=3");
			string ret3 = calc->Solve("3-4*2+6");
			Assert::AreEqual(ret3, (string)"3-4*2+6=1");
			//string ret = calc->Solve("3+11*22");
			//Assert::AreEqual(ret, (string)"11*22=245");
		}
	};
}
