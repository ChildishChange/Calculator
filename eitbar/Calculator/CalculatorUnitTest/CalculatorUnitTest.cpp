#include "pch.h"
#include "CppUnitTest.h"
#include "..//Calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
	TEST_CLASS(CalculatorUnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");

			ret = calc->Solve("1+2+3+4");
			Assert::AreEqual(ret, (string)"1+2+3+4=10");
			ret = calc->Solve("1+2+3-4");
			Assert::AreEqual(ret, (string)"1+2+3-4=2");
			ret = calc->Solve("1+2+3*4");
			Assert::AreEqual(ret, (string)"1+2+3*4=15");
			ret = calc->Solve("1+2-3+4");
			Assert::AreEqual(ret, (string)"1+2-3+4=4");
			ret = calc->Solve("1+2-3-4");
			Assert::AreEqual(ret, (string)"1+2-3-4=-4");
			ret = calc->Solve("1+2-3*4");
			Assert::AreEqual(ret, (string)"1+2-3*4=-9");
			ret = calc->Solve("1+2*3+4");
			Assert::AreEqual(ret, (string)"1+2*3+4=11");
			ret = calc->Solve("1+2*3-4");
			Assert::AreEqual(ret, (string)"1+2*3-4=3");
			ret = calc->Solve("1+2*3*4");
			Assert::AreEqual(ret, (string)"1+2*3*4=25");

			ret = calc->Solve("1-2+3+4");
			Assert::AreEqual(ret, (string)"1-2+3+4=6");
			ret = calc->Solve("1-2+3-4");
			Assert::AreEqual(ret, (string)"1-2+3-4=-2");
			ret = calc->Solve("1-2+3*4");
			Assert::AreEqual(ret, (string)"1-2+3*4=11");
			ret = calc->Solve("1-2-3+4");
			Assert::AreEqual(ret, (string)"1-2-3+4=0");
			ret = calc->Solve("1-2-3-4");
			Assert::AreEqual(ret, (string)"1-2-3-4=-8");
			ret = calc->Solve("1-2-3*4");
			Assert::AreEqual(ret, (string)"1-2-3*4=-13");
			ret = calc->Solve("1-2*3+4");
			Assert::AreEqual(ret, (string)"1-2*3+4=-1");
			ret = calc->Solve("1-2*3-4");
			Assert::AreEqual(ret, (string)"1-2*3-4=-9");
			ret = calc->Solve("1-2*3*4");
			Assert::AreEqual(ret, (string)"1-2*3*4=-23");

			ret = calc->Solve("1*2+3+4");
			Assert::AreEqual(ret, (string)"1*2+3+4=9");
			ret = calc->Solve("1*2+3-4");
			Assert::AreEqual(ret, (string)"1*2+3-4=1");
			ret = calc->Solve("1*2+3*4");
			Assert::AreEqual(ret, (string)"1*2+3*4=14");
			ret = calc->Solve("1*2-3+4");
			Assert::AreEqual(ret, (string)"1*2-3+4=3");
			ret = calc->Solve("1*2-3-4");
			Assert::AreEqual(ret, (string)"1*2-3-4=-5");
			ret = calc->Solve("1*2-3*4");
			Assert::AreEqual(ret, (string)"1*2-3*4=-10");
			ret = calc->Solve("1*2*3+4");
			Assert::AreEqual(ret, (string)"1*2*3+4=10");
			ret = calc->Solve("1*2*3-4");
			Assert::AreEqual(ret, (string)"1*2*3-4=2");
			ret = calc->Solve("1*2*3*4");
			Assert::AreEqual(ret, (string)"1*2*3*4=24");

			ret = calc->Solve("11-22");
			Assert::AreEqual(ret, (string)"11-22=-11");
			ret = calc->Solve("11*22");
			Assert::AreEqual(ret, (string)"11*22=242");
			ret = calc->Solve("22/11");
			Assert::AreEqual(ret, (string)"22/11=2");
			ret = calc->Solve("11-22+22");
			Assert::AreEqual(ret, (string)"11-22+22=11");
			ret = calc->Solve("11*22+11");
			Assert::AreEqual(ret, (string)"11*22+11=253");
			ret = calc->Solve("22/11+11");
			Assert::AreEqual(ret, (string)"22/11+11=13");
			ret = calc->Solve("22/1+11");
			Assert::AreEqual(ret, (string)"22/1+11=33");
			ret = calc->Solve("22*1+11");
			Assert::AreEqual(ret, (string)"22*1+11=33");
			ret = calc->Solve("22+1+11");
			Assert::AreEqual(ret, (string)"22+1+11=34");
			ret = calc->Solve("22-1+11");
			Assert::AreEqual(ret, (string)"22-1+11=32");
			ret = calc->Solve("22+1+3*11");
			Assert::AreEqual(ret, (string)"22+1+3*11=56");
			ret = calc->Solve("5-6*7+2");
			Assert::AreEqual(ret, (string)"5-6*7+2=-35");
		}
	};
}
