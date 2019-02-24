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
			Calculator* calc = new Calculator();
			string ret = calc->Solve("37-72/36+90");
			Assert::AreEqual((string)"37-72/36+90=-55",ret );

		}

		TEST_METHOD(TestMethod2)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("1+2");
			Assert::AreEqual((string)"1+2=3", ret);


		}

		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("15/3");
			Assert::AreEqual((string)"15/3=5", ret);

		}

		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("6/3");
			Assert::AreEqual((string)"6/3=2", ret);

		}

		TEST_METHOD(TestMethod5)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("1+2+3");
			Assert::AreEqual((string)"1+2+3=6", ret);

	
		}

		//TEST_METHOD(TestMethod6)
		//{
		//	Calculator* calc = new Calculator();
		//	string ret = calc->MakeFormula();
		//	Assert::AreEqual((string)"?", ret);
		//
		//
		//}
	};
}