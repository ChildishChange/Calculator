#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest_1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret1 = calc->Solve("11+22");
			Assert::AreEqual(ret1, (string)"11+22=33");
		}
		TEST_METHOD(TestMethod2) {
			Calculator* calc = new Calculator();
			string ret2 = calc->Solve("10/10+1");
			cout << ret2 << endl;
			Assert::AreEqual(ret2, (string)"10/10+1=2");
		}
		TEST_METHOD(TestMethod3) {
			Calculator* calc = new Calculator();
			string ret3 = calc->Solve("99*99-2");
			cout << ret3 << endl;
			Assert::AreEqual(ret3, (string)"99*99-2=9799");
		}
		TEST_METHOD(TestMethod4) {
			Calculator* calc = new Calculator();
			string ret4 = calc->Solve("0*0-0");
			cout << ret4 << endl;
			Assert::AreEqual(ret4, (string)"0*0-0=0");
		}
		TEST_METHOD(TestMethod5) {
			Calculator* calc = new Calculator();
			string ret5 = calc->Solve("99*99");
			cout << ret5 << endl;
			Assert::AreEqual(ret5, (string)"99*99=9801");
		}
		TEST_METHOD(TestMethod6)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret6 = calc->Solve("11+22+1");
			Assert::AreEqual(ret6, (string)"11+22+1=34");
		}
		TEST_METHOD(TestMethod7) {
			Calculator* calc = new Calculator();
			string ret7 = calc->Solve("99/11");
			cout << ret7 << endl;
			Assert::AreEqual(ret7, (string)"99/11=9");
		}
		TEST_METHOD(TestMethod8) {
			Calculator* calc = new Calculator();
			string ret8 = calc->Solve("1+64/16-5");
			cout << ret8 << endl;
			Assert::AreEqual(ret8, (string)"1+64/16-5=0");
		}
		TEST_METHOD(TestMethod9) {
			Calculator* calc = new Calculator();
			string ret9 = calc->Solve("11*11+95/5");
			cout << ret9 << endl;
			Assert::AreEqual(ret9, (string)"11*11+95/5=140");
		}
	};
}