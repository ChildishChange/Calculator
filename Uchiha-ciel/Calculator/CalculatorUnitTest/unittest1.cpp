#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		Calculator* calc = new Calculator();
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("11-22");
			Assert::AreEqual(ret, (string)"11-22=-11");
		}

		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("1*2");
			Assert::AreEqual(ret, (string)"1*2=2");
		}

		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("16/8");
			Assert::AreEqual(ret, (string)"16/8=2");
		}

		TEST_METHOD(TestMethod5)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("11-22+33");
			Assert::AreEqual(ret, (string)"11-22+33=22");
		}

		TEST_METHOD(TestMethod6)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("1*2+3");
			Assert::AreEqual(ret, (string)"1*2+3=5");
		}

		TEST_METHOD(TestMethod7)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("1+6/3");
			Assert::AreEqual(ret, (string)"1+6/3=3");
		}

		TEST_METHOD(TestMethod8)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("1*6/2");
			Assert::AreEqual(ret, (string)"1*6/2=3");
		}

		TEST_METHOD(TestMethod9)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("1*2*11");
			Assert::AreEqual(ret, (string)"1*2*11=22");
		}

		TEST_METHOD(TestMethod10)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("18/2/3");
			Assert::AreEqual(ret, (string)"18/2/3=3");
		}

		TEST_METHOD(TestMethod11)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22+22");
			Assert::AreEqual(ret, (string)"11+22+22=55");
		}

		TEST_METHOD(TestMethod12)
		{
			// TODO: 在此输入测试代码
			//Calculator* calc = new Calculator();
			string ret = calc->Solve("11-2-3");
			Assert::AreEqual(ret, (string)"11-2-3=6");
		}

	};
}