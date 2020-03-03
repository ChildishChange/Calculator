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
			// TODO: �ڴ�������Դ���
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: �ڴ�������Դ���
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+34");
			Assert::AreEqual(ret, (string)"11+34=45");
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: �ڴ�������Դ���
			Calculator* calc = new Calculator();
			string ret = calc->Solve("13+17-1");
			Assert::AreEqual(ret, (string)"13+17-1=29");
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: �ڴ�������Դ���
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11*15-5");
			Assert::AreEqual(ret, (string)"11*15-5=160");
		}
		TEST_METHOD(TestMethod5)
		{
			// TODO: �ڴ�������Դ���
			Calculator* calc = new Calculator();
			string ret = calc->Solve("3+10+4-16");
			Assert::AreEqual(ret, (string)"3+10+4-16=1");
		}
		TEST_METHOD(TestMethod6)
		{
			// TODO: �ڴ�������Դ���
			Calculator* calc = new Calculator();
			string ret = calc->Solve("15/5+3-2");
			Assert::AreEqual(ret, (string)"15/5+3-2=4");
		}
		TEST_METHOD(TestMethod7)
		{
			// TODO: �ڴ�������Դ���
			Calculator* calc = new Calculator();
			string ret = calc->Solve("24/4/6");
			Assert::AreEqual(ret, (string)"24/4/6=1");
		}
		TEST_METHOD(TestMethod8)
		{
			// TODO: �ڴ�������Դ���
			Calculator* calc = new Calculator();
			string ret = calc->Solve("24+12/6");
			Assert::AreEqual(ret, (string)"24+12/6=26");
		}
		TEST_METHOD(TestMethod9)
		{
			// TODO: �ڴ�������Դ���
			Calculator* calc = new Calculator();
			string ret = calc->Solve("24+12/6-1");
			Assert::AreEqual(ret, (string)"24+12/6-1=25");
		}
	};
}