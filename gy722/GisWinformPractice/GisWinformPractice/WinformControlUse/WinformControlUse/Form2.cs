using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using DaoLayer;
using Entity;
using System.Threading;
using System.Collections.ObjectModel;
using System.Collections;


namespace WinformControlUse
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
      
       

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
        private static List<Student> studengList;
        private void button2_Click(object sender, EventArgs e)
        {
             
            studengList = new List<Student>();
            Console.WriteLine("请输入学生的姓名：");
            Student stu85 = new Student();
            Console.Write("姓名：");
            Console.WriteLine("请输入学生的学号：");
            Console.Write("学号：");
            studengList.Add(stu85);
            Console.WriteLine("添加成功！");
        }

        private void listBox3_SelectedIndexChanged(object sender, EventArgs e)
        {
            studengList = new List<Student>();
            Console.WriteLine("请输入学生的姓名：");
            Student stu85 = new Student();
            Console.Write("姓名：");
            studengList.Add(stu85);
        }

        private void listBox4_SelectedIndexChanged(object sender, EventArgs e)
        {
            Console.WriteLine("请输入学生的学号：");
            Student stu85 = new Student();
            Console.Write("学号：");
            studengList.Add(stu85);
        }
    }
    }

