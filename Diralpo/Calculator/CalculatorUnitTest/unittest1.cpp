#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		Calculator* calc = new Calculator();
		
		TEST_METHOD(TestMethod01)
		{
			// TODO: 在此输入测试代码
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");
		}

		TEST_METHOD(TestMethod02)
		{
			string ret = calc->Solve("22-11");
			Assert::AreEqual(ret, (string)"22-11=11");
		}

		TEST_METHOD(TestMethod03)
		{
			string ret = calc->Solve("22/11");
			Assert::AreEqual(ret, (string)"22/11=2");
		}

		TEST_METHOD(TestMethod04)
		{
			string ret = calc->Solve("10*6");
			Assert::AreEqual(ret, (string)"10*6=60");
		}

	};

	TEST_CLASS(UnitTest2)
	{
	public:
		Calculator* calc = new Calculator();

		TEST_METHOD(TestMethod05)
		{
			string ret = calc->Solve("2+3+4");
			Assert::AreEqual(ret, (string)"2+3+4=9");
		}

		TEST_METHOD(TestMethod06)
		{
			string ret = calc->Solve("2+3-4");
			Assert::AreEqual(ret, (string)"2+3-4=1");
		}

		TEST_METHOD(TestMethod07)
		{
			string ret = calc->Solve("2+3*4");
			Assert::AreEqual(ret, (string)"2+3*4=14");
		}

		TEST_METHOD(TestMethod08)
		{
			string ret = calc->Solve("2+6/3");
			Assert::AreEqual(ret, (string)"2+6/3=4");
		}

		TEST_METHOD(TestMethod09)
		{
			string ret = calc->Solve("7-6+2");
			Assert::AreEqual(ret, (string)"7-6+2=3");
		}

		TEST_METHOD(TestMethod10)
		{
			string ret = calc->Solve("7-3-2");
			Assert::AreEqual(ret, (string)"7-3-2=2");
		}

		TEST_METHOD(TestMethod11)
		{
			string ret = calc->Solve("7-3*2");
			Assert::AreEqual(ret, (string)"7-3*2=1");
		}

		TEST_METHOD(TestMethod12)
		{
			string ret = calc->Solve("7-6/2");
			Assert::AreEqual(ret, (string)"7-6/2=4");
		}

	};
}