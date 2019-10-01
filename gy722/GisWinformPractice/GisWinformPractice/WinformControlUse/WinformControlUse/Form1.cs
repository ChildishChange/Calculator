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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            if
             (textBox1.Text == "王静宜" &&
              textBox2.Text == "123456")
                Console.WriteLine("登录成功！");
            if
            (textBox1.Text == "顾毓" &&
            textBox2.Text == "123456")
                Console.WriteLine("登录成功！");
            FrmStudent h =new FrmStudent();
            h.Show();
        }
    }
}
