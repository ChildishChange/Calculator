#include "pch.h"
#include "CppUnitTest.h"
#include "../../src/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace calculatorTest
{
	TEST_CLASS(calculatorTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");
		}
	};
}
