#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\ConsoleApplication1\Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			Calculator* calc = new Calculator();
			string ret = calc->Solve("50/10-2");
			Assert::AreEqual(ret, (string)"50/10-2=3");
		}

	};
}