#include "pch.h"
#include "../Calculator/calculator.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11+22");
            Assert::AreEqual(ret, (string)"11+22=33");
        }
        TEST_METHOD(TestMethod2)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11*6");
            Assert::AreEqual(ret, (string)"11*6=66");
        }
        TEST_METHOD(TestMethod3)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11+22+1");
            Assert::AreEqual(ret, (string)"11+22+1=34");
        }
    };

    TEST_CLASS(UnitTest2)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11-22+6/3");
            Assert::AreEqual(ret, (string)"11-22+6/3=-9");
        }
        TEST_METHOD(TestMethod2)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("11*2/2*9");
            Assert::AreEqual(ret, (string)"11*2/2*9=99");
        }
        TEST_METHOD(TestMethod3)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("32*3-12*8");
            Assert::AreEqual(ret, (string)"32*3-12*8=0");
        }
    };

    TEST_CLASS(UnitTest3)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("6/3*4");
            Assert::AreEqual(ret, (string)"6/3*4=8");
        }
        TEST_METHOD(TestMethod2)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("1-2*8");
            Assert::AreEqual(ret, (string)"1-2*8=-15");
        }
        TEST_METHOD(TestMethod3)
        {
            Calculator* calc = new Calculator();
            string ret = calc->Solve("32-15*15");
            Assert::AreEqual(ret, (string)"32-15*15=-193");
        }
    };
}
