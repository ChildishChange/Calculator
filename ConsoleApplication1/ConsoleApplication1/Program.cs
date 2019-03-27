using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入需要的计算题数目： ");
            int n, i, j = 0;
            n = Convert.ToInt32(Console.ReadLine());
            Random x = new Random();
            string a="";
            Console.WriteLine("计算题并且与答案如下： ");
            for (i = 1; i <= n; i++)
            {
                string y;
                int mark1 = x.Next(2, 4);
                if (mark1 == 2)
                {
                      int number1 = x.Next(0, 100);
                      int number2 = x.Next(0, 100);
                      int mark2 = x.Next(1, 5);
                      if (mark2 == 1)
                      {
                          a = "+";
                          j = number1 + number2;
                      }
                      if (mark2 == 2)
                      {
                          a = "-";
                          j = number1 - number2;
                      }
                      if (mark2 == 3)
                      {
                          a = "*";
                          j = number1 * number2;
                      }
                      if (mark2 == 4)
                      {
                          a = "/";
                          j = number1 / number2;
                      }
                      Console.WriteLine(y = Convert.ToString(number1) + a + Convert.ToString(number2) + "=" + Convert.ToString(j));
                }
                if (mark1 == 3)
                {
                    int number1 = x.Next(0, 100);
                    int number2 = x.Next(0, 100);
                    int number3 = x.Next(0, 100);
                    int mark2 = x.Next(1, 5);
                    int mark3 = x.Next(1, 5);
                    if (mark2 >= 3 && mark3 <= 2)
                    {
                        if (mark2 == 3 && mark3 == 1)
                        {
                            j = number1 * number2 + number3;
                            Console.WriteLine(y=Convert.ToString(number1)+"*"+Convert.ToString(number2)+"+"+Convert.ToString(number3)+"="+Convert.ToString(j));
                        }
                        if (mark2 == 4 && mark3 == 2)
                        {
                            j = number1 / number2 - number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "/" + Convert.ToString(number2) + "-" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                        if (mark2 == 3 && mark3 == 2)
                        {
                            j = number1 * number2 - number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "*" + Convert.ToString(number2) + "-" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                        if (mark2 == 4 && mark3 == 1)
                        {
                            j = number1 / number2 + number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "/" + Convert.ToString(number2) + "+" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }                    
                    }
                    if (mark3 >= 3 && mark2 <= 2)
                    {
                        if (mark3 == 3 && mark2 == 1)
                        {
                            j = number2 * number3 + number1;
                            Console.WriteLine(y = Convert.ToString(number1) + "+" + Convert.ToString(number2) + "*" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                        if (mark3 == 4 && mark2 == 2)
                        {
                            j = number1-number2/number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "-" + Convert.ToString(number2) + "/" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                        if (mark3 == 3 && mark2 == 2)
                        {
                            j = number1 - number2 * number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "-" + Convert.ToString(number2) + "*" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                        if (mark3 == 4 && mark2 == 1)
                        {
                            j = number1 + number2 / number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "+" + Convert.ToString(number2) + "/" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                    }
                    if (mark3 < 3 && mark2 < 2)
                    {
                        if (mark3 == 1 && mark2 == 1)
                        {
                            j = number2 + number3 + number1;
                            Console.WriteLine(y = Convert.ToString(number1) + "+" + Convert.ToString(number2) + "+" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                        if (mark3 == 1 && mark2 == 2)
                        {
                            j = number1 - number2 + number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "-" + Convert.ToString(number2) + "+" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                        if (mark3 == 2 && mark2 == 1)
                        {
                            j = number1 + number2 - number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "+" + Convert.ToString(number2) + "-" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                        if (mark3 == 2 && mark2 == 2)
                        {
                            j = number1 - number2 - number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "-" + Convert.ToString(number2) + "-" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                    }
                    if (mark2 >= 3 && mark3 >= 2)
                    {
                        if (mark2 == 3 && mark3 == 3)
                        {
                            j = number1 * number2 * number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "*" + Convert.ToString(number2) + "*" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                        if (mark2 == 3 && mark3 == 4)
                        {
                            j = number1 * number2 / number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "*" + Convert.ToString(number2) + "/" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                        if (mark2 == 4 && mark3 == 3)
                        {
                            j = number1 / number2 * number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "/" + Convert.ToString(number2) + "*" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                        if (mark2 == 4 && mark3 == 4)
                        {
                            j = number1 / number2 / number3;
                            Console.WriteLine(y = Convert.ToString(number1) + "/" + Convert.ToString(number2) + "/" + Convert.ToString(number3) + "=" + Convert.ToString(j));
                        }
                    }
                }

            }
        }
    }
}
