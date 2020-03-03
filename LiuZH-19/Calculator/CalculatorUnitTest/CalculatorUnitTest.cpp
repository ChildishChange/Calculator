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
			string ret2 = calc->Solve("+-11-2");
			Assert::AreEqual(ret2, (string)"+-11-2=-13");
		}

		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret2 = calc->Solve("11-2*2/4");
			Assert::AreEqual(ret2, (string)"11-2*2/4=10");
		}

		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret2 = calc->Solve("3+1200/6");
			Assert::AreEqual(ret2, (string)"3+1200/6=203");
		}

		TEST_METHOD(TestMethod5)
		{
			Calculator* calc = new Calculator();
			string ret2 = calc->Solve("-11+12*2/8");
			Assert::AreEqual(ret2, (string)"-11+12*2/8=-8");
		}

		TEST_METHOD(TestMethod6)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("15/5*2+3-2");
			Assert::AreEqual(ret, (string)"15/5*2+3-2=7");
		}

		TEST_METHOD(TestMethod7)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("13-58/2-91");
			Assert::AreEqual(ret, (string)"13-58/2-91=-107");
		}

		TEST_METHOD(TestMethod8)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("1-91-11+1");
			Assert::AreEqual(ret, (string)"1-91-11+1=-100");
		}

		


		
	};
}
