using Microsoft.VisualStudio.TestTools.UnitTesting;
using Calculator;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator.Tests
{
     [TestClass()]
     public class CalculatorTests
     {
          [TestMethod()]
          public void CalculatorTest()
          {
               StringBuilder s = new StringBuilder();
               string tmp = Calculator.createExpression();
               while (true)
               {
                    if (Calculator.Calculate(tmp) >= 0)
                    {
                         s.Append(tmp + " = " + Calculator.Calculate(tmp) + "\r\n");
                         break;
                    }
               }
               
               System.IO.File.WriteAllText("D://test.txt", s.ToString(), Encoding.Default);
          }

     }
}