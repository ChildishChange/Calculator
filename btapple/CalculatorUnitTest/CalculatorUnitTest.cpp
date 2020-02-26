#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
    TEST_CLASS(CalculatorUnitTest)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Calculator calc = Calculator();
            std::string ret = calc.Solve("11+22");
            std::string exp = "11+22=33";
            Assert::AreEqual(ret, exp);
        }
    };
}
