using System;
using System.Data;
using System.IO;



namespace Calculator
{
    public class Program
    {
        public static string[] Operation = { "+", "-", "*", "/" };

        public static string Make_Formula()
        {
            string formula = null;
            var seed = Guid.NewGuid().GetHashCode();
            Random random = new Random(seed);
            int number_1 = random.Next(0, 101);
            int number_2 = random.Next(2, 4);
            formula = number_1.ToString();
            for (int i = 1; i <= number_2; i++)
            {
                number_1 = random.Next(0, 101);//生成随机运算数字，且取值范围为[0,100]
                int operation = random.Next(0, 4);//随机产生运算符
                formula = formula + Operation[operation] + number_1.ToString();
            }
            return formula;
        }

        public static string Calculate(string formula)
        {

            DataTable dt = new DataTable();
            string result = dt.Compute(formula, "").ToString();//利用DataTable提供方法对随机产生的字符串式子进行运算
            while (formula.Contains("/0") || result.Contains(".") || Convert.ToInt32(result) < 0)//检查运算过程中是否有除0操作、运算结果是否有小数或负数。
            {
                formula = Make_Formula();
                result = dt.Compute(formula, "").ToString();
            }
            return result;
        }

        static void Main(string[] args)
        {
            Console.Write("请输入您需要的算数个数（输入后按Enter键继续）；");
            int n = Convert.ToInt32(Console.ReadLine());
            StreamWriter sw = new StreamWriter(@"C:\niuerduo\Calculator\subject.txt");
            for (int i = 0; i < n; i++)
            {

                string formula = Make_Formula();//需送算式子的左辺部分
                string result = Calculate(formula);//i汁算式子的結果
                string final_MathFormula = formula + "=" + result;
                Console.WriteLine(final_MathFormula);//
                sw.WriteLine(final_MathFormula);
            }
            sw.Close();
        }

    }
}
