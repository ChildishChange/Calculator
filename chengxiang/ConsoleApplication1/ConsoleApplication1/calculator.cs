using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class calculator
    {
        public static int right = 0;                        
        public static int wrong = 0;                          

        public void mathadd()                                 
        {
            int a, b;
            int result;
            Random rd = new Random();
            a = rd.Next(0, 11);
            b = rd.Next(0, 11);
            Console.WriteLine("请计算：{0}+{1}=？", a, b);
            result = Convert.ToInt32(Console.ReadLine());
            if (result == a + b)
            {
                Console.WriteLine("回答正确！");
                right++;
            }
            else
            {
                Console.WriteLine("错误，继续努力！");
                wrong++;
            }

        }
        public void mathminus()                                
        {
            int a, b;
            int result;
            Random rd = new Random();
            a = rd.Next(0, 11);
            b = rd.Next(0, 11);
            Console.WriteLine("请计算：{0}-{1}=？", a, b);
            result = Convert.ToInt32(Console.ReadLine());
            if (result == a - b)
            {
                Console.WriteLine("回答正确！");
                right++;
            }
            else
            {
                Console.WriteLine("错误，继续努力！");
                wrong++;
            }
        }
        public void mathmultiply()                               
        {
            int a, b;
            int result;
            Random rd = new Random();
            a = rd.Next(0, 11);
            b = rd.Next(0, 11);
            Console.WriteLine("请计算：{0}*{1}=？", a, b);
            result = Convert.ToInt32(Console.ReadLine());
            if (result == a * b)
            {
                Console.WriteLine("回答正确！");
                right++;
            }
            else
            {
                Console.WriteLine("错误，继续努力！");
                wrong++;
            }


        }
        public void mathdivide()                                 
        {
            int a, b;
            int result;
            Random rd = new Random();
            a = rd.Next(0, 11);
            b = rd.Next(0, 11);
            if (b != 0)
            {
                Console.WriteLine("请计算：{0}/{1}=？", a, b);
                result = Convert.ToInt32(Console.ReadLine());
                if (result == a / b)
                {
                    Console.WriteLine("回答正确！");
                    right++;
                }
                else
                {
                    Console.WriteLine("错误，继续努力！");
                    wrong++;
                }

            }
            else
            {
                if (a != 0)
                {
                    Console.WriteLine("请计算：{0}/{1}=？", b, a);
                    result = Convert.ToInt32(Console.ReadLine());
                    if (result == b / a)
                    {
                        Console.WriteLine("回答正确！");
                        right++;
                    }
                    else
                    {
                        Console.WriteLine("错误，继续努力！");
                        wrong++;
                    }
                }
            }
        }
        public void result()                                 
        {
            Console.WriteLine("总共做了{0}道题：你做对了{1}道题，做错了{2}道题。", right + wrong, right, wrong);
        }
    }
}
