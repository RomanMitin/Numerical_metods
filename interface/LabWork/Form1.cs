using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace LabWork
{
    public partial class Form1 : Form
    {
        DataTable table;
        public Form1()
        {
            InitializeComponent();
            comboBox1.SelectedIndex = 0;
            //System.Threading.Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("en-US");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            table = new DataTable();
            DataTable_table.DataSource = table;
            // Program.table = new DataTable();
            // var table = Program.table;
            // table.Columns.Add("index", typeof(int));
            //  table.Columns.Add("x", typeof(double));
            // table.Columns.Add("v", typeof(double));
            //dataTable.DataSource = table;
            //SetValueParams();
        }
        private void тестоваяToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //setFunction();
        }
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private static void AddText(FileStream fs, string text){
            byte[] bytes = new byte[text.Length];
            for (int i = 0; i < text.Length; ++i) {
                bytes[i] = (byte)text[i];
            }
            fs.Write(bytes, 0, text.Length);
        }

        private static string[] string_erase(string[] strs, string str) {
            int count = 0;
            for (int i = 0; i < strs.Length; i++) {
                if (strs[i] != str) count++;
            }
            string[] ans = new string[count];
            count = 0;
            for (int i = 0; i < strs.Length; i++)
            {
                if (strs[i] != str) {
                    ans[count] = new string(strs[i]);
                    count++;
                }
            }
            return ans;
        }

        private void buttonSolve_Click(object sender, EventArgs e)
        {
            double a, b, u0, h0, eps, klp;
            a = b = u0 = h0 = eps = klp = 0.0;
            int nmax = 0;
            bool flag = false;
            label6.Text = "";
            if (!double.TryParse(textBox_a.Text, out a)) label6.Text += "Некорректное значение a\n";
            else if (!double.TryParse(textBox_b.Text, out b)) label6.Text += "Некорректное значение b\n";
            else if (!double.TryParse(textBox_eps.Text, out eps)) label6.Text += "Некорректное значение Eгр\n";
            else if (!double.TryParse(textBox_u0.Text, out u0)) label6.Text += "Некорректное значение u0\n";
            else if (!double.TryParse(textBox_h.Text, out h0)) label6.Text += "Некорректное значение h0\n";
            else if (!double.TryParse(textBox_klp.Text, out klp)) label6.Text += "Некорректное значение КЛП\n";
            else if (!int.TryParse(textBox_Nmax.Text, out nmax)) label6.Text += "Некорректное значение Nmax\n";
            else {
                flag = true;
            }
            if (flag) {
                //create output.txt
                FileInfo path = new FileInfo(@"output.txt");
                FileStream output_txt = path.Open(FileMode.Create);
                output_txt.Close();

                //create input.txt
                path = new FileInfo(@"input.txt");
                FileStream input_txt = path.Open(FileMode.Create);
                int m = 3; //method
                int c = 3; //local error options
                string options = "";

                options += m + " ";
                options += a + " ";
                options += b + " ";
                options += u0 + " ";
                options += h0 + " ";
                options += nmax + " ";
                options += eps + " ";
                options += c + " ";

                options = options.Replace(',', '.');
               // label6.Text = options;
                AddText(input_txt, options);

                input_txt.Close();
                
                //run numerical_metods
                string command = @"Numerical_metods.exe input.txt > output.txt";

                Process process = new Process();
                process.StartInfo.FileName = "cmd.exe";
                process.StartInfo.Arguments = "/C" + command;
                process.Start();
                process.WaitForExit();

                //get result
                StreamReader reader = new StreamReader("output.txt");

                //get firstLine
                string firstLine = reader.ReadLine();
                string[] name_columns = firstLine.Split(' ');
                name_columns = string_erase(name_columns, "");
                //clear table
                table.Columns.Clear();
                table.Rows.Clear();
                //set column names
                for (int i = 0; i < name_columns.Length; ++i) {
                    //label6.Text += name_columns[i];
                    table.Columns.Add(name_columns[i], typeof(string));
                }

                //fill table values
                while (reader.Peek() > -1) {
                    //label6.Text += "#";
                    string line = reader.ReadLine();
                    string[] values = line.Split(' ');
                    values = string_erase(values, "");
                    table.Rows.Add(values);
                }
                
                reader.Close();
            }
        }
    }
}
