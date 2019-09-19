using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace ConsoleApp1
{
    public class mathvoid
    {
        public void mathjia()                                 //加法运算！
        {

            int a, b;
            int result;
            Random rd = new Random();
            a = rd.Next(0, 100);
            b = rd.Next(0, 100);
            Console.WriteLine("{0}+{1}=", a, b);
            result = Convert.ToInt32(Console.ReadLine());

        }
        public void mathjian()                                //减法运算！
        {
            int a, b;
            int result;
            Random rd = new Random();
            a = rd.Next(0, 100);
            b = rd.Next(0, 100);
            Console.WriteLine("{0}-{1}= ", a, b);
            result = Convert.ToInt32(Console.ReadLine());
            if (result == a - b)
            {
                Console.WriteLine("回答正确！");

            }
        }
        public void mathcheng()                               //乘法运算！
        {
            int a, b;
            int result;
            Random rd = new Random();
            a = rd.Next(0, 100);
            b = rd.Next(0, 100);
            Console.WriteLine("{0}*{1}=", a, b);
            result = Convert.ToInt32(Console.ReadLine());
            if (result == a * b)
            {
                Console.WriteLine("回答正确！");

            }
        }

        public void mathchu()                                 //除法运算！
        {
            int a, b;
            int result;
            Random rd = new Random();
            a = rd.Next(0, 100);
            b = rd.Next(0, 100);
            if (b != 0)
            {
                Console.WriteLine("{0}/{1}=", a, b);
                result = Convert.ToInt32(Console.ReadLine());
                if (result == a / b)
                {
                    Console.WriteLine("回答正确！");

                }

            }
            else
            {
                if (a != 0)
                {
                    Console.WriteLine("{0}/{1}= ", b, a);
                    result = Convert.ToInt32(Console.ReadLine());
                    if (result == a / b)
                    {
                        Console.WriteLine("回答正确！");

                    }

                }

            }
        }
    }
}