using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int varible_1, varible_2;//定义变量
            Rand rand1 = new Rand();
            Console.WriteLine("生成题目数量：");
            varible_1 = Convert.ToInt32(Console.ReadLine());
            for (varible_2 = 0; varible_2 < varible_1; varible_2++)
            {
                rand1.Digit();
            }
        }
    }
    class Rand //获取随机
    {
        public static float value;
        public void Digit()//获取这个算式中有多少位数
        {
            int varible_1, varible_2;
            Random random = new Random(Guid.NewGuid().GetHashCode());
            varible_1 = random.Next(2, 4);
            if (varible_1 == 2)
                Count_2();
            else
                Count_3();
        }
        public void Count_2()//两位数计算
        {
            for (int a = 0; ; a++)
            {
                int varible_1, varible_2;
                float varible_11, varible_21, value;
                string symbol;//运算符号
                Random random = new Random(Guid.NewGuid().GetHashCode());
                varible_1 = random.Next(100);
                varible_2 = random.Next(100);
                varible_11 = varible_1;
                varible_21 = varible_2;//将得到的两个值赋值            
                varible_1 = random.Next(4);
                if (varible_1 == 0)
                {
                    value = varible_11 + varible_21;
                    symbol = "+";
                    if (jugement(value) == 1)
                    {
                        Console.WriteLine(varible_11 + symbol + varible_21 + "=" + value);
                        break;
                    }
                    else
                        continue;
                }

                else if (varible_1 == 1)
                {
                    symbol = "-";
                    value = varible_11 - varible_21;
                    if (jugement(value) == 1)
                    {
                        Console.WriteLine(varible_11 + symbol + varible_21 + "=" + value);
                        break;
                    }
                    else
                        continue;
                }
                else if (varible_1 == 2)
                {
                    symbol = "*";
                    value = varible_11 * varible_21;
                    if (jugement(value) == 1)
                    {
                        Console.WriteLine(varible_11 + symbol + varible_21 + "=" + value);
                        break;
                    }
                    else
                        continue;
                }

                else if (varible_1 == 3)
                {
                    symbol = "/";
                    value = varible_11 / varible_21;
                    if (jugement(value) == 1)
                    {
                        Console.WriteLine(varible_11 + symbol + varible_21 + "=" + value);
                        break;
                    }
                    else
                        continue;
                }

            }
        }
        public void Count_3()
        {
            for (int a = 0; ; a++)
            {
                int varible_1, varible_2, varible_3;
                float varible_11, varible_21, varible_31, value;
                string symbol1, symbol2;//记录符号
                Random random = new Random(Guid.NewGuid().GetHashCode());
                varible_1 = random.Next(100);
                varible_2 = random.Next(100);
                varible_3 = random.Next(100);
                varible_11 = varible_1;
                varible_21 = varible_2;
                varible_31 = varible_3;//将得到的三个值赋值            
                varible_1 = random.Next(4);
                if (varible_1 == 0)
                {
                    symbol1 = "+";
                    value = varible_11 + varible_21;
                    if (jugement(value) == 1)
                    {
                        Random random1 = new Random(Guid.NewGuid().GetHashCode());
                        varible_1 = random1.Next(4);
                        if (varible_1 == 0)
                        {
                            symbol2 = "+";
                            value = value + varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 1)
                        {
                            symbol2 = "-";
                            value = value - varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 2)
                        {
                            symbol2 = "*";
                            value = value * varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 3)
                        {
                            symbol2 = "/";
                            value = value / varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                    }
                    else
                        continue;
                }
                else if (varible_1 == 1)
                {
                    symbol1 = "-";
                    value = varible_11 - varible_21;
                    if (jugement(value) == 1)
                    {
                        varible_1 = random.Next(4);
                        if (varible_1 == 0)
                        {
                            symbol2 = "+";
                            value = value + varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 1)
                        {
                            symbol2 = "-";
                            value = value - varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 2)
                        {
                            symbol2 = "*";
                            value = value * varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 3)
                        {
                            symbol2 = "/";
                            value = value / varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                    }
                    else
                        continue;
                }
                else if (varible_1 == 2)
                {
                    symbol1 = "*";
                    value = varible_11 * varible_21;
                    if (jugement(value) == 1)
                    {

                        varible_1 = random.Next(4);
                        if (varible_1 == 0)
                        {
                            symbol2 = "+";
                            value = value + varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 1)
                        {
                            symbol2 = "-";
                            value = value - varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 2)
                        {
                            symbol2 = "*";
                            value = value * varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 3)
                        {
                            symbol2 = "/";
                            value = value / varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }


                    }
                    else
                        continue;
                }
                else if (varible_1 == 3)
                {
                    symbol1 = "/";
                    value = varible_11 / varible_21;
                    if (jugement(value) == 1)
                    {

                        varible_1 = random.Next(4);
                        if (varible_1 == 0)
                        {
                            symbol2 = "+";
                            value = value + varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 1)
                        {
                            symbol2 = "-";
                            value = value - varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 2)
                        {
                            symbol2 = "*";
                            value = value * varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }
                        else if (varible_1 == 3)
                        {
                            symbol2 = "/";
                            value = value / varible_31;
                            if (jugement(value) == 1)
                            {
                                Console.WriteLine(varible_11 + symbol1 + varible_21 + symbol2 + varible_31 + "=" + value);
                                break;
                            }
                            else
                                continue;
                        }

                    }
                    else
                        continue;
                }
            }
        }
        public int jugement(float n)//判断是否为小数
        {
            if (n % 1.0 == 0)
                return 1;
            else
                return 0;
        }
    }
}
