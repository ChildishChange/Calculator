using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace c_s_s_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            char[] C = new char[] { '+', '-', '*', '/' };
            string s = "";
            int x = 10;
            Random Max = new Random(10);
            long tick = DateTime.Now.Ticks;
           // Random r = new Random((int)(tick & 0xffffffffL) | (int)(tick >> 32));
            Random Ch = new Random();
            for(int i=0;i<10000;i++)
            {
                int num1 = Max.Next(0, 100);
                int num2 = Max.Next(0, 100);
                int ch1 = Ch.Next(0, 4);
                double result;
                if (C[ch1] == '+')
                    result = num1 + num2;
                else if (C[ch1] == '-')
                    result = num1 - num2;
                else if (C[ch1] == '*')
                    result = num1 * num2;
                else
                {
                    result = (double)num1 / (double)num2;
                }
                Console.WriteLine(num1.ToString() + C[ch1].ToString() + num2.ToString()+"=" + result.ToString());
            }
        }
    }
}
