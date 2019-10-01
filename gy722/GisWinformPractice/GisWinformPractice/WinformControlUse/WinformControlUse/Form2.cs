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
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            studengList = new List<Student>();
            Console.WriteLine("请输入学生的姓名：");
            string 姓名 = textBox1.Text;

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            studengList = new List<Student>();
            Console.WriteLine("请输入学生的学号：");
            string 学号 = textBox2.Text;
        }
        private static List<Student> studengList;
        private void button2_Click(object sender, EventArgs e)
        {
           string  StudentDataset="insert  studengList(' " +label3  + " ','" + label4 + " )";
            studengList = new List<Student>();
            Student stu85 = new Student("+ label3 +", " + label4 + ");
            studengList.Add(stu85);
            Console.WriteLine("添加成功！");
        }

      

      
    }
    }

