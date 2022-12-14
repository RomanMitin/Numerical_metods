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
        int dx, dy;
        public Form1()
        {
            InitializeComponent();
            comboBox1.SelectedIndex = 0;
            comboBox2.SelectedIndex = 0;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            table = new DataTable();
            DataTable_table.DataSource = table;
        }
        private void тестоваяToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //setFunction();
        }
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBox1.SelectedIndex) {
                case 2:
                    textBox_du.Enabled = true;
                    break;
                default:
                    textBox_du.Enabled = false;
                    break;
            }
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
            double a, b, u0, h0, eps, du, E, Emin;
            a = b = u0 = h0 = eps = E = Emin = du = 0.0;
            int nmax = 0;
            int m = 7; //method
            double p = 4; //order
            bool flag = false;
            textBox_info.Text = "";
            if (!double.TryParse(textBox_a.Text, out a)) textBox_info.Text += "Некорректное значение a\n";
            else if (!double.TryParse(textBox_b.Text, out b)) textBox_info.Text += "Некорректное значение b\n";
            else if (!double.TryParse(textBox_eps.Text, out eps)) textBox_info.Text += "Некорректное значение Eгр\n";
            else if (!double.TryParse(textBox_du.Text, out du)) textBox_info.Text += "Некорректное значение du/dx\n";
            else if (!double.TryParse(textBox_u0.Text, out u0)) textBox_info.Text += "Некорректное значение u0\n";
            else if (!double.TryParse(textBox_h.Text, out h0)) textBox_info.Text += "Некорректное значение h0\n";
            else if ((!double.TryParse(textBox_E.Text, out E)) & (!checkBox1.Checked)) textBox_info.Text += "Некорректное значение E\n";
            else if (!double.TryParse(textBox_Emin.Text, out Emin))  textBox_info.Text += "Некорректное значение Emin\n";
            else if (!int.TryParse(textBox_Nmax.Text, out nmax)) textBox_info.Text += "Некорректное значение Nmax\n";
            else
            {
                flag = true;
            }
            if (flag) {
                //create path
                DirectoryInfo dir = new DirectoryInfo("./tmp");
                dir.Create();

                if (!File.Exists(@"./tmp/Numerical_metods.exe")) {
                    MessageBox.Show("'./tmp/Numerical_metods.exe' not found");
                    return;
                }

                //create result.txt
                FileInfo path = new FileInfo(@"./tmp/result.txt");
                FileStream output_txt = path.Open(FileMode.Create);
                output_txt.Close();

                //create input.txt
                path = new FileInfo(@"./tmp/input.txt");
                FileStream input_txt = path.Open(FileMode.Create);
                string options = "";

                int func_num = comboBox1.SelectedIndex + 1;
                int c = (comboBox2.SelectedIndex + 1);
                options += m + " ";
                options += a + " ";
                options += b + " ";
                options += u0 + " ";
                if (func_num == 3) {
                    options += du + " ";
                }
                options += h0 + " ";
                options += nmax + " ";
                options += eps + " ";
                options += func_num + " ";
                options += c + " ";
                if (c == 1 || c == 2) {
                    options += E + " ";
                    if (!checkBox1.Checked)
                    {
                        options += Emin;
                    }
                    else
                    {
                        options += (E / Math.Pow(2, p));
                    }
                }

                options = options.Replace(',', '.');
                AddText(input_txt, options);

                input_txt.Close();
                
                //run numerical_metods
                string command = @".\tmp\Numerical_metods.exe .\tmp\input.txt > .\tmp\result.txt";

                Process process = new Process();
                process.StartInfo.FileName = "cmd.exe";
                process.StartInfo.Arguments = "/C" + command;
                process.Start();
                process.WaitForExit();

                //get result
                StreamReader reader = new StreamReader(@".\tmp\result.txt");
                try
                {
                    string refer = "";
                    reader.ReadLine();
                    for (int j = 0; j < 15; ++j)
                    {
                        refer += reader.ReadLine() + '\n';
                    }
                    reader.ReadLine();
                    reader.ReadLine();

                    string[] info = refer.Split(' ', '\n', '\t');
                    info = string_erase(info, "");
                    //textBox_info.Text += info.Length + Environment.NewLine;
                    /*for (int i = 0; i < info.Length; ++i) {
                        textBox_info.Text += (info[i] + Environment.NewLine);
                    }*/
                    //set info
                    textBox_info.Text += "№ варианта задания: 4" + Environment.NewLine;
                    textBox_info.Text += "Тип задачи: " + (comboBox1.SelectedItem.ToString()) + Environment.NewLine;
                    textBox_info.Text += "Метод Рунге Кутта порядка p = " + p + ":" + Environment.NewLine;
                    textBox_info.Text += "x0 = " + info[0] + "\t\tu0 = " + info[1] + Environment.NewLine;
                    textBox_info.Text += "b = " + info[2] + "\t\tEгр = " + info[3] + Environment.NewLine;
                    textBox_info.Text += "h0 = " + info[4] + "\t\tNmax = " + info[5] + Environment.NewLine;
                    textBox_info.Text += "E = " + info[6] + "\t\tEmin = " + info[7] + Environment.NewLine;
                    textBox_info.Text += "Вариант контроля: " + comboBox2.SelectedItem.ToString() + Environment.NewLine;
                    textBox_info.Text += Environment.NewLine;
                    textBox_info.Text += "Результат расчета:" + Environment.NewLine;
                    textBox_info.Text += "N = " + info[8] + Environment.NewLine;
                    textBox_info.Text += "b - xN = " + info[9] + Environment.NewLine;
                    textBox_info.Text += "xN = " + info[10] + "\t\tvNитог = " + info[11] + Environment.NewLine;
                    textBox_info.Text += "max|En| = " + info[12] + "\t\tпри xn = " + info[13] + Environment.NewLine;
                    textBox_info.Text += "max|S| = " + info[14] + "\t\tпри xn = " + info[15] + Environment.NewLine;
                    textBox_info.Text += "min|S| = " + info[16] + "\t\tпри xn = " + info[17] + Environment.NewLine;
                    textBox_info.Text += "Всего ум. шага = " + info[18] + Environment.NewLine;
                    textBox_info.Text += "Всего ув. шага = " + info[19] + Environment.NewLine;
                    textBox_info.Text += "max(hn) = " + info[20] + "\t\tпри xn+1 = " + info[21] + Environment.NewLine;
                    textBox_info.Text += "min(hn) = " + info[22] + "\t\tпри xn+1 = " + info[23] + Environment.NewLine;

                    //get firstLine
                    string firstLine = reader.ReadLine();
                    string[] name_columns = firstLine.Split(' ');
                    name_columns = string_erase(name_columns, "");

                    //clear table
                    table.Columns.Clear();
                    table.Rows.Clear();

                    //set column names
                    for (int i = 0; i < name_columns.Length; ++i)
                    {
                        table.Columns.Add(name_columns[i], typeof(string));
                    }

                    //fill table values
                    while (reader.Peek() > -1)
                    {
                        string line = reader.ReadLine();
                        string[] values = line.Split(' ');
                        values = string_erase(values, "");
                        table.Rows.Add(values);
                    }
                }
                catch (Exception exc){
                    MessageBox.Show("Incorrect result.txt");
                }
                reader.Close();

                //run graph.exe
                if (!File.Exists(@".\Graph_for_method\graph.py")) {
                    MessageBox.Show(@"'.\Graph_for_method\graph.py' not found");
                    return;
                }
                switch (comboBox1.SelectedIndex) {
                    case 0: {
                            command = @".\Graph_for_method\graph.py " + m + " 1";
                            break;
                    }
                    default: {
                            command = @".\Graph_for_method\graph.py " + m + " 0";
                            break;
                    }
                }

                process = new Process();
                //process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
                process.StartInfo.FileName = "python";
                process.StartInfo.Arguments = "" + command;
                process.Start();
            }
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            Control control = (Control)sender;
            DataTable_table.Size = new Size(control.Size.Width - DataTable_table.Location.X - dx, control.Size.Height - DataTable_table.Location.Y - dy);
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            textBox_Emin.Enabled = !checkBox1.Checked;
        }

        private void Form1_ResizeBegin(object sender, EventArgs e)
        {
            Control control = (Control)sender;
            dx = control.Size.Width - (DataTable_table.Location.X + DataTable_table.Size.Width);
            dy = control.Size.Height - (DataTable_table.Location.Y + DataTable_table.Size.Height);
        }
    }
}
