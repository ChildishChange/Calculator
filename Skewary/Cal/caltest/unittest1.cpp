#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/calculator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace caltest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("2*3+4*5");
			Assert::AreEqual(ret, (string)"2*3+4*5=26");
		}

	};
}