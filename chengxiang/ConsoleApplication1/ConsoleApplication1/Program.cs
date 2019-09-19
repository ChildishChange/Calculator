using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            calculator op = new calculator();
            string Z = "";
            do
            {
                Console.WriteLine("-------------------------------四则运算-------------------------");
                Console.WriteLine("");
                Console.WriteLine("请选择一种运算方法:1.加法 2.减法 3.乘法 4.除法 5.退出！");
                Z = Console.ReadLine();
                switch (Z)
                {
                    case "1":
                        op.mathadd();
                        continue;
                    case "2":
                        op.mathminus();
                        continue;
                    case "3":
                        op.mathmultiply();
                        continue;
                    case "4":
                        op.mathdivide();
                        continue;
                    case "5":
                        op.result();
                        break;
                    default:
                        Console.WriteLine("输入无效！");
                        continue;
                }
                break;
            }
            while (true);
        }
    }
}
