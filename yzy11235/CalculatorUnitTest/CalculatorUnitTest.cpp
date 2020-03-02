#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
	TEST_CLASS(CalculatorUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethodSolve)
		{
			Calculator* calc = new Calculator();
			// +
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string) "11+22=33");
			ret = calc->Solve("99+2");
			Assert::AreEqual(ret, (string) "99+2=101");
			// /
			ret = calc->Solve("22/2");
			Assert::AreEqual(ret, (string) "22/2=11");
			ret = calc->Solve("3/5");
			// -- Assert::AreEqual(ret, (string) "3/5=0.6");
			// -- ret = calc->Solve("99/0");
			// -
			ret = calc->Solve("8-4");
			// -- Assert::AreEqual(ret, (string) "8-4=4");
			ret = calc->Solve("4-8");
			// -- Assert::AreEqual(ret, (string) "4-8=-4"); 
			// * 
			ret = calc->Solve("1*1");
			// -- Assert::AreEqual(ret, (string) "1*1=1");
			ret = calc->Solve("5*25");
			// -- Assert::AreEqual(ret, (string) "5*25=125");

		}
	};
}
