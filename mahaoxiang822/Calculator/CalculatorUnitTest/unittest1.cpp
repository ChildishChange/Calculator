#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"
#include <regex>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Sovle)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret1 = calc->Solve("11+22");
			string ret2 = calc->Solve("0+100");
			string ret3 = calc->Solve("2+3*4");
			Assert::AreEqual((string)"11+22=33",ret1 );
			Assert::AreEqual((string)"0+100=100",ret2);
			Assert::AreEqual((string)"2+3*4=14",ret3);
		}

		TEST_METHOD(MakeFormula)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->MakeFormula();

			std::regex pattern("((0|[1-9][0-9]?|100)(\\+|\\-|\\*|\\/)){2,3}(0|[1-9][0-9]?|100)", std::regex::icase);
			Assert::IsTrue(std::regex_match(ret,pattern) == true);
		}


	};
}