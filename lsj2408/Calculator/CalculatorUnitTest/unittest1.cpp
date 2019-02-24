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
			Calculator *calc = new Calculator();
			string ret1 = calc->Solve("0+0*0-0");
			string ret2 = calc->Solve("99*99*99");
			string ret3 = calc->Solve("0+101*100");
			//string ret4 = calc->Solve("1+2*4+1.1");
			Assert::AreEqual(ret1, (string)"0+0*0-0=0");
			Assert::AreEqual(ret2, (string)"99*99*99=970299");
			Assert::AreEqual(ret3, (string)"0+101*100=10100");
			/*Assert::AreEqual(ret4, (string)"1+2*4+1.1=10.1");*/

		}

	};
}