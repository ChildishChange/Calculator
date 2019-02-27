#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		Calculator* calc = new Calculator();

		/*
		* single operation
		*/
		TEST_METHOD(ADD)
		{
			// TODO: 在此输入测试代码
			string ret = calc->Solve("11+12");
			Assert::AreEqual(ret, (string)"11+12=23");
		}
		TEST_METHOD(SUB)
		{
			// TODO: 在此输入测试代码
			string ret = calc->Solve("13-12");
			Assert::AreEqual(ret, (string)"13-12=1");
		}
		TEST_METHOD(MULT)
		{
			// TODO: 在此输入测试代码
			string ret = calc->Solve("5*4");
			Assert::AreEqual(ret, (string)"5*4=20");
		}
		TEST_METHOD(DIV)
		{
			// TODO: 在此输入测试代码
			string ret = calc->Solve("6/2");
			Assert::AreEqual(ret, (string)"6/2=3");
		}
		

		/*
		* compound operation
		*/
		TEST_METHOD(ADD_SUB)
		{
			string ret = calc->Solve("1+2-2");
			Assert::AreEqual(ret, (string)"1+2-2=1");
		}
		TEST_METHOD(ADD_MULT)
		{
			string ret = calc->Solve("1+2*2");
			Assert::AreEqual(ret, (string)"1+2*2=5");
		}
		TEST_METHOD(ADD_DIV)
		{
			string ret = calc->Solve("1+2/2");
			Assert::AreEqual(ret, (string)"1+2/2=2");
		}
		TEST_METHOD(SUB_MULT)
		{
			string ret = calc->Solve("1*2-2");
			Assert::AreEqual(ret, (string)"1*2-2=0");
		}
		TEST_METHOD(SUB_DIV)
		{
			string ret = calc->Solve("3-2/2");
			Assert::AreEqual(ret, (string)"3-2/2=2");
		}
		TEST_METHOD(MULT_DIV)
		{
			string ret = calc->Solve("1*2/2");
			Assert::AreEqual(ret, (string)"1*2/2=1");
		}

		/*COMPLLICATED operator*/
		TEST_METHOD(complicated)
		{
			string ret = calc->Solve("1+2-2+10/5*8/4+2*3");
			Assert::AreEqual(ret, (string)"1+2-2+10/5*8/4+2*3=11");
		}
	};
}