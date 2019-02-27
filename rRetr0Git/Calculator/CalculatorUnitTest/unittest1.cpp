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
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");
			ret = calc->Solve("12-2+67");
			Assert::AreEqual(ret, (string)"12-2+67=77");
			ret = calc->Solve("11*2*2");
			Assert::AreEqual(ret, (string)"11*2*2=44");
			ret = calc->Solve("22/11/1");
			Assert::AreEqual(ret, (string)"22/11/1=2");
		}
	};
}