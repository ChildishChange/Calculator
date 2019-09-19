using System;
using System.Collections.Generic;

namespace Bottfek
{
    class Guid
    {
        private struct Calcu
        {
            public int x, y, z;
            public int Sym1, Sym2;
        }
        private void Choice(int Sym)
        {
            if (Sym == 1)
                Console.Write("+");
            else if (Sym == 2)
                Console.Write("-");
            else if (Sym == 3)
                Console.Write("*");
            else
                Console.Write("/");
        }
        private int Operation(int x, int Sym, int y)
        {
            if (Sym == 1)
                return x + y;
            else if (Sym == 2)
                return x - y;
            else if (Sym == 3)
                return x * y;
            else if (Sym == 2)
                return x / y;
            else
                return 0;
        }
        private bool Judge(List<Calcu> Calcu, Calcu r)
        {
            for (int i = 0; i < Calcu.Count; i++)
            {
                if (Calcu[i].x == r.x && Calcu[i].y == r.y && Calcu[i].z == r.z && Calcu[i].Sym1 == r.Sym1 && Calcu[i].Sym2 == r.Sym2)
                {
                    return false;
                }


            }
            if (r.Sym1 == 4 && (r.x / r.y * r.y) != r.x)
            {
                return false;
            }
            if (r.Sym2 == 4 && ((r.Sym1 <= 2 && (r.y / r.z * r.z) != r.y) || (r.Sym1 > 2 && (Operation(r.x, r.Sym1, r.y) / r.z * r.z) != Operation(r.x, r.Sym1, r.y))))
            {
                return false;
            }
            return true;
        }
        private int Sum(Calcu r)
        {
            if (r.Sym1 > 2 || r.Sym2 <= 2)
                return Operation(Operation(r.x, r.Sym1, r.y), r.Sym2, r.z);
            else
                return Operation(r.x, r.Sym1, Operation(r.y, r.Sym2, r.z));
        }
        public Guid(int n)
        {
            List<Calcu> Calcu = new List<Calcu>();
            for (int i = 0; i < n;)
            {
                i++;
                Random ran = new Random();
                while (true)
                {
                    Calcu r = new Calcu();
                    r.x = ran.Next(1, 100);
                    r.Sym1 = ran.Next(1, 5);
                    r.y = ran.Next(1, 100);
                    r.Sym2 = ran.Next(1, 5);
                    r.z = ran.Next(1, 100);
                    if (Judge(Calcu, r))
                    {
                        Calcu.Add(r);
                        break;
                    }
                }
            }
            int j = 1;
            for (int i = 0; i < n; i++)
            {
                Console.Write(j + ". ");
                j++;
                Console.Write(Calcu[i].x);
                Choice(Calcu[i].Sym1);
                Console.Write(Calcu[i].y);
                Choice(Calcu[i].Sym2);
                Console.WriteLine(Calcu[i].z + "=");
            }
        }
        static void Main(string[] args)
        {
            Console.Write("请输入题目数目：");
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine("题目如下：");
            Build run = new Build (n);
        }
    }
}


