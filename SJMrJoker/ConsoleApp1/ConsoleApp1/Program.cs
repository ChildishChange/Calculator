using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AchaoCalculator
{
    class Program
    {
        string path = "E:/My files/SJMrJoker/Calculator/SJMrJoker/subject.txt";
        List<string> formulas = new List<string>();
        Random random = new Random();
        Stack<string> stack_operator = new Stack<string>();
        Stack<string> stack_number = new Stack<string>();
        string str = "";
        string substr = "";
        bool flag = true;

        static void Main(string[] args)
        {
            Program program = new Program();
            int n = 0;
            n = Convert.ToInt32(Console.ReadLine());
            program.FormulaGeneration(n);
            foreach (var str in program.formulas)
            {
                Console.WriteLine(str);
            }
            System.IO.File.WriteAllLines(program.path, program.formulas);
            Console.ReadKey();
        }
        
        #region
        private bool judgenumber(string text)
       {
            try
            {
                int var1 = Convert.ToInt32(text);
                return true;
            }
            catch
            {
                return false;
            }
        }
        private bool judgeoperator(string text)
       {
            if (text == "(" || text == ")" || text == "+" || text == "-" || text == "*" || text == "/")
            {
                return true;
            }
            else
                return false;
        }
        public object addition(object a, object b)
       {
            Decimal d1 = Decimal.Parse(a.ToString());
Decimal d2 = Decimal.Parse(b.ToString());
            return d2 + d1;
        }
        public object subduction(object a, object b)
       {
            Decimal d1 = Decimal.Parse(a.ToString());
Decimal d2 = Decimal.Parse(b.ToString());
            return d2 - d1;
        }
        public object multiplication(object a, object b)
       {
            Decimal d1 = Decimal.Parse(a.ToString());
Decimal d2 = Decimal.Parse(b.ToString());
            return d2* d1;
        }
        public object division(object a, object b)
       {
            Decimal d1 = Decimal.Parse(a.ToString());
Decimal d2 = Decimal.Parse(b.ToString());
            if(d2%d1!=0||d2<d1)
            {
                flag = false;
                return -10000;
            }
            else
            {
                flag = true;
                return d2 / d1;
            }

        }
        int judgelevel(string text)
       {
            if (text.Equals("("))
            {
                return 1;
            }
            else if (text.Equals(")") || text.Equals("（") || text.Equals("）"))
            {
                return 1;
            }
            else if (text.Equals("+") || text.Equals("-"))
            {
                return 2;
            }
            else if (text.Equals("*") || text.Equals("/"))
            {
                return 3;
            }
            else
                return 10;


        }
        int operator_dected(string types, string a, string b)
       {
            if (types == "+")
            {
                return Convert.ToInt32(addition(a, b));
            }
            else if (types == "-")
            {
                return Convert.ToInt32(subduction(a, b));
            }
            else if (types == "*")
            {
                return Convert.ToInt32(multiplication(a, b));
            }
            else if (types == "/")
            {
                return Convert.ToInt32(division(a, b));
            }
            else
                return 999;
        }
        double operate(string Str)
{
    stack_number.Clear();
    stack_operator.Clear();
    str = Str + "!";
    int temp_count = 0;
    try
    {
        for (int i = 0; i < str.Length; i++)
        {
            substr = str.Substring(i, 1);
            if (judgenumber(substr))
            {
                if (temp_count == 0)
                {
                    stack_number.Push(substr);
                }
                else
                    temp_count--;
                if (judgenumber(str.Substring(i + 1, 1)))
                {
                    string link1 = stack_number.Pop();
                    link1 += str.Substring(i + 1, 1);
                    stack_number.Push(link1);
                    temp_count++;
                }
            }
                    else if (judgeoperator(substr))
            {
                if (stack_operator.Count >= 1)
                {
                    int new1 = judgelevel(substr);
                    int old1 = judgelevel(stack_operator.Peek());
                    if (old1 < new1 || substr == "(")
                    {
                        stack_operator.Push(substr); 
                    }
                            else
                            {
                        if (substr == ")")
                        {
                            for (; stack_operator.Count > 0; stack_operator.Pop())
                            {
                                if (stack_operator.Contains("(") && stack_operator.Peek() == "(")
                                {
                                    stack_operator.Pop();
                                    break;
                                }
                                else
                                {
                                    int temp1 = Convert.ToInt32(stack_number.Peek()); stack_number.Pop();
                                    int temp2 = Convert.ToInt32(stack_number.Peek()); stack_number.Pop();
                                    stack_number.Push(operator_dected(stack_operator.Peek(), temp1.ToString(), temp2.ToString()).ToString());
                                }
                            }
                        }
                        else
                        {
                            for (; stack_operator.Count > 0 && stack_number.Count >= 2 && stack_operator.Peek() != "("; stack_operator.Pop())
                            {
                                string temp_a = substr;
                                int new2 = judgelevel(temp_a);
                                int old2 = judgelevel(stack_operator.Peek());
                                if (old2 < new2 || substr == "(")
                                {
                                    break;
                                }
                                        else
                                        {
                                    int temp3 = Convert.ToInt32(stack_number.Peek()); stack_number.Pop();
                                    int temp4 = Convert.ToInt32(stack_number.Peek()); stack_number.Pop();
                                    stack_number.Push(operator_dected(stack_operator.Peek(), temp3.ToString(), temp4.ToString()).ToString());
                                }
                            }
                            stack_operator.Push(substr);
                        }
                    }
                }
                else
                {
                    stack_operator.Push(substr);


                }
            }
            else if (substr == "!")
            {
                for (; stack_operator.Count > 0 && stack_number.Count >= 2 && stack_operator.Peek() != "("; stack_operator.Pop())
                {
                    int temp3 = Convert.ToInt32(stack_number.Peek()); stack_number.Pop();
                    int temp4 = Convert.ToInt32(stack_number.Peek()); stack_number.Pop();
                    stack_number.Push(operator_dected(stack_operator.Peek(), temp3.ToString(), temp4.ToString()).ToString());
                }
                return Convert.ToDouble(stack_number.Peek());
            }
            else
            {

                break;
            }
        }
    }
    catch
    {


    }
    return 0;
}
#endregion

void FormulaGeneration(int num)
{
    string formula = "";
    int n = 0;
    string str = "";
    double ans = 0;
    for (int i = 0; i < num; i++)
    {
        n = random.Next(2, 4);

        switch (n)
        {
            case 2:
                do
                {
                    str = FormulaGeneration_01();
                    formula = str + "!";
                    ans = operate(formula);
                    if (ans % 1 == 0 && ans > 0 && flag == true)
                    {
                        break;
                    }
                } while (true);
                formula = str + "=" + operate(formula); ;
                formulas.Add(formula);
                break;
            case 3:

                do
                {
                    str = FormulaGeneration_03();
                    formula = str + "!";
                    ans = operate(formula);
                    if (ans % 1 == 0 && ans > 0 && flag == true)
                    {
                        break;
                    }
                } while (true);
                formula = str + "=" + operate(formula); ;
                formulas.Add(formula);
                break;
        }
    }
}

string FormulaGeneration_01()
{
    string formula = "";
    int a = 0;
    int b = 0;
    int c = 0;
    int x = 0;
    int y = 0;
    a = random.Next(0, 101);
    b = random.Next(0, 101);
    c = random.Next(0, 101);
    x = random.Next(0, 4);
    y = random.Next(0, 4);
    switch (x)
    {
        case 0:
            formula = a + "+" + b;
            formula = FormulaGeneration_0101(formula, y, c);
            break;
        case 1:
            formula = a + "-" + b;
            formula = FormulaGeneration_0101(formula, y, c);
            break;
        case 2:
            formula = a + "*" + b;
            formula = FormulaGeneration_0101(formula, y, c);
            break;
        case 3:
            formula = a + "/" + b;
            formula = FormulaGeneration_0101(formula, y, c);
            break;
    }
    return formula;
}


string FormulaGeneration_0101(string form, int y, int c)
{
    switch (y)
    {
        case 0:
            form = form + "+" + c;
            break;
        case 1:
            form = form + "-" + c;
            break;
        case 2:
            form = form + "*" + c;
            break;
        case 3:
            form = form + "/" + c;
            break;
    }
    return form;
}

string FormulaGeneration_03()
{
    string formula = "";
    int a = 0;
    int x = 0;
    a = random.Next(0, 101);
    x = random.Next(0, 4);
    switch (x)
    {
        case 0:
            formula = a + "+" + FormulaGeneration_01();
            break;
        case 1:
            formula = a + "-" + FormulaGeneration_01();
            break;
        case 2:
            formula = a + "*" + FormulaGeneration_01();
            break;
        case 3:
            formula = a + "/" + FormulaGeneration_01();
            break;
    }
    return formula;
}
    }
}
