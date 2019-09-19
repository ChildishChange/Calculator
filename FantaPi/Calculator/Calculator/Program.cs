using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Calculator
{
     class Program
     {
          static void Main(string[] args)
          {
               Calculator c = new Calculator();
          }
     }

     public class Calculator
     {
          public Calculator() {
               WriteHomeWork();
          }
          private static Random rd = new Random();
          

          public static void WriteHomeWork()
          {
               StringBuilder resultExp = new StringBuilder();
               Console.WriteLine("请输入生成四则混合运算个数：");
               int num=int.Parse(Console.ReadLine());
               string expExample="";
               int k = 0;
               for(int i = 0;;)
               {
                    expExample=createExpression();
                    if (Calculate(expExample) == -1)
                    {
                         i++;
                         continue;
                    }
                    resultExp.Append(expExample+"="+Calculate(expExample)+"\r\n");
                    k++;
                    if (k == num)
                    {
                         break;
                    }
                    i++;
               }
               System.IO.File.WriteAllText("D://homework.txt", resultExp.ToString(), Encoding.Default);
          }

          public static int Calculate(string s)
          {                  
               int result = 0;  

               string[] addop = s.Split(new string[] { "+" }, StringSplitOptions.RemoveEmptyEntries);
               for (int i = 0; i < addop.Length; i++)
               {
                    string[] subop = addop[i].Split(new string[] { "-" }, StringSplitOptions.RemoveEmptyEntries);
                    int[] subint = new int[subop.Length];
                    for (int j = 0; j < subint.Length; j++)
                    {
                         subint[j] = Operate(subop[j]);
                    }
                    int subval = subint.Aggregate((a, b) => a - b);
                    if (subval < 0)
                    {
                         return -1;
                    }
                    result += subval;
               }

               return result;
          }

          public static string createExpression()
          {
               string s = "";
               int a = rd.Next(3, 5);
               for(int i = 0; i < a; i++)
               {
                    int b = rd.Next(1, 100);
                    s += b.ToString();
                    if (i == a - 1) break;
                    int c = rd.Next(0,4);
                    if (c == 0) s += '+';
                    if (c == 1) s += '-';
                    if (c == 2) s += '*';
                    if (c == 3) s += '/';
               }
               return s;
          }

          private static int Operate(string exp)
          {
               if (exp.Contains("*") == false && exp.Contains("/") == false)
               {
                    return Convert.ToInt32(exp);
               }
               string[] num = new string[2] { "", "" };
               string lastop = "";
               for (int i = 0; i < exp.Length; i++)
               {
                    
                    if (exp[i] == '*')
                    {
                         if (lastop == "")
                              lastop = "*";
                         else
                         {
                              if (lastop == "*")
                              {
                                   num[0] = (Convert.ToInt32(num[0]) * Convert.ToInt32(num[1])).ToString();
                                   num[1] = "";
                                   lastop = "*";
                              }
                              else
                              {
                                   num[0] = (Convert.ToInt32(num[0]) / Convert.ToInt32(num[1])).ToString();
                                   num[1] = "";
                                   lastop = "*";
                              }
                         }
                    }
                    else if (exp[i] == '/')
                    {
                         if (lastop == "")
                              lastop = "/";
                         else
                         {
                              if (lastop == "*")
                              {
                                   num[0] = (Convert.ToInt32(num[0]) * Convert.ToInt32(num[1])).ToString();
                                   num[1] = "";
                                   lastop = "/";
                              }
                              else
                              {
                                   num[0] = (Convert.ToInt32(num[0]) / Convert.ToInt32(num[1])).ToString();
                                   num[1] = "";
                                   lastop = "/";
                              }
                         }
                    }
                    else
                    {
                         if (lastop == "")
                              num[0] += exp[i];
                         else
                              num[1] += exp[i];
                    }
               }

               if (lastop == "*")
               {
                    return (Convert.ToInt32(num[0]) * Convert.ToInt32(num[1]));
               }
               else
               {

                    return (Convert.ToInt32(num[0]) / Convert.ToInt32(num[1]));
               }

          }
     }
          
     

}
