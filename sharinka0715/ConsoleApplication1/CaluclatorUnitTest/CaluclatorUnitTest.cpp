#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CaluclatorUnitTest
{
	TEST_CLASS(CaluclatorUnitTest)
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
			string ret = calc->Solve("11-22");
			Assert::AreEqual(ret, (string)"11-22=-11");
		}

		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("0-22");
			Assert::AreEqual(ret, (string)"0-22=-22");
		}

		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("-1*0");
			Assert::AreEqual(ret, (string)"-1*0=0");
		}

		TEST_METHOD(TestMethod5)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("5/5+2");
			Assert::AreEqual(ret, (string)"5/5+2=3");
		}
	};
}
