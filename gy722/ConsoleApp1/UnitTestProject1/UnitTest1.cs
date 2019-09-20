using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Threading.Tasks;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Data;


namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            int expect = 3;
            int[] numbers = new int[3] { 1, 2, 3 };
            Random num = new Random();
            int res = Random.Largest(numbers);
            Assert.AreEqual(res, expect);
        }
    }
}
