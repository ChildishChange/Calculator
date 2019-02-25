#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Melina-ZhCal/Melina-ZhCal.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCal
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");

			// TODO: 在此输入测试代码
		}
		TEST_METHOD(TestMethod2)
		{

			Calculator* calc = new Calculator();
			string ret = calc->Solve("12/2+23*1");
			Assert::AreEqual(ret, (string)"12/2+23*1=29");

			// TODO: 在此输入测试代码
		}
	};
}