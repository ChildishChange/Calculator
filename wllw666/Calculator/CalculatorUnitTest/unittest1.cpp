#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1_1)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11+22");
            Assert::AreEqual(ret, (string)"11+22=33");
        }

        TEST_METHOD(TestMethod1_2)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11-22");
            Assert::AreEqual(ret, (string)"11-22=-11");
        }

        TEST_METHOD(TestMethod1_3)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11*22");
            Assert::AreEqual(ret, (string)"11*22=242");
        }

        TEST_METHOD(TestMethod1_4)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("22/11");
            Assert::AreEqual(ret, (string)"22/11=2");
        }

        TEST_METHOD(TestMethod2_1)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11+22-33");
            Assert::AreEqual(ret, (string)"11+22-33=0");
        }

        TEST_METHOD(TestMethod2_2)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("22/11*33");
            Assert::AreEqual(ret, (string)"22/11*33=66");
        }

        TEST_METHOD(TestMethod2_3)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11-22*0");
            Assert::AreEqual(ret, (string)"11-22*0=11");
        }

        TEST_METHOD(TestMethod2_4)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("22/11+100");
            Assert::AreEqual(ret, (string)"22/11+100=102");
        }

        TEST_METHOD(TestMethod3_1)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11+22-33+44");
            Assert::AreEqual(ret, (string)"11+22-33+44=44");
        }

        TEST_METHOD(TestMethod3_2)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("22*33/6-122");
            Assert::AreEqual(ret, (string)"22*33/6-122=-1");
        }

        TEST_METHOD(TestMethod3_3)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("22/11*33-77");
            Assert::AreEqual(ret, (string)"22/11*33-77=-11");
        }

        TEST_METHOD(TestMethod3_4)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("22/11+100*5");
            Assert::AreEqual(ret, (string)"22/11+100*5=502");
        }

        TEST_METHOD(TestMethod3_5)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11-22*0+100");
            cout << ret;
            Assert::AreEqual(ret, (string)"11-22*0+100=111");
        }

    };
}