#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/ConsoleApplication1.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
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
		}
	};
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22*3");
			Assert::AreEqual(ret, (string)"11+22*3=77");
		}
	};
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("1*22+3*22");
			Assert::AreEqual(ret, (string)"1*22+3*22=88");
		}
	};
	
}