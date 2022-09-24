
namespace LabWork
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.DataTable_table = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox_a = new System.Windows.Forms.TextBox();
            this.textBox_b = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox_u0 = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.textBox_h = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.textBox_eps = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.textBox_klp = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.textBox_Nmax = new System.Windows.Forms.TextBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.buttonSolve = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.DataTable_table)).BeginInit();
            this.SuspendLayout();
            // 
            // DataTable_table
            // 
            this.DataTable_table.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataTable_table.Location = new System.Drawing.Point(12, 216);
            this.DataTable_table.Name = "DataTable_table";
            this.DataTable_table.RowHeadersWidth = 51;
            this.DataTable_table.Size = new System.Drawing.Size(776, 222);
            this.DataTable_table.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(36, 83);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 20);
            this.label1.TabIndex = 3;
            this.label1.Text = "u(a) =";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(73, 20);
            this.label2.TabIndex = 4;
            this.label2.Text = "x ∈ [a, b] ";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(91, 44);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(31, 20);
            this.label3.TabIndex = 5;
            this.label3.Text = "a =";
            // 
            // textBox_a
            // 
            this.textBox_a.Location = new System.Drawing.Point(128, 41);
            this.textBox_a.Name = "textBox_a";
            this.textBox_a.Size = new System.Drawing.Size(44, 27);
            this.textBox_a.TabIndex = 6;
            this.textBox_a.Text = "0";
            // 
            // textBox_b
            // 
            this.textBox_b.Location = new System.Drawing.Point(216, 41);
            this.textBox_b.Name = "textBox_b";
            this.textBox_b.Size = new System.Drawing.Size(43, 27);
            this.textBox_b.TabIndex = 7;
            this.textBox_b.Text = "10";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(178, 44);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(32, 20);
            this.label4.TabIndex = 8;
            this.label4.Text = "b =";
            // 
            // textBox_u0
            // 
            this.textBox_u0.Location = new System.Drawing.Point(91, 80);
            this.textBox_u0.Name = "textBox_u0";
            this.textBox_u0.Size = new System.Drawing.Size(125, 27);
            this.textBox_u0.TabIndex = 10;
            this.textBox_u0.Text = "1";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(431, 15);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(50, 20);
            this.label6.TabIndex = 11;
            this.label6.Text = "label6";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(242, 149);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(39, 20);
            this.label7.TabIndex = 14;
            this.label7.Text = "h0 =";
            // 
            // textBox_h
            // 
            this.textBox_h.Location = new System.Drawing.Point(287, 146);
            this.textBox_h.Name = "textBox_h";
            this.textBox_h.Size = new System.Drawing.Size(125, 27);
            this.textBox_h.TabIndex = 13;
            this.textBox_h.Text = "0,01";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(231, 83);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(50, 20);
            this.label8.TabIndex = 16;
            this.label8.Text = "E гр =";
            // 
            // textBox_eps
            // 
            this.textBox_eps.Location = new System.Drawing.Point(287, 80);
            this.textBox_eps.Name = "textBox_eps";
            this.textBox_eps.Size = new System.Drawing.Size(125, 27);
            this.textBox_eps.TabIndex = 15;
            this.textBox_eps.Text = "0,01";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(231, 116);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(53, 20);
            this.label9.TabIndex = 18;
            this.label9.Text = "КЛП =";
            // 
            // textBox_klp
            // 
            this.textBox_klp.Location = new System.Drawing.Point(287, 113);
            this.textBox_klp.Name = "textBox_klp";
            this.textBox_klp.Size = new System.Drawing.Size(125, 27);
            this.textBox_klp.TabIndex = 17;
            this.textBox_klp.Text = "0,001";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(22, 119);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(66, 20);
            this.label10.TabIndex = 20;
            this.label10.Text = "Nmax = ";
            // 
            // textBox_Nmax
            // 
            this.textBox_Nmax.Location = new System.Drawing.Point(91, 116);
            this.textBox_Nmax.Name = "textBox_Nmax";
            this.textBox_Nmax.Size = new System.Drawing.Size(125, 27);
            this.textBox_Nmax.TabIndex = 19;
            this.textBox_Nmax.Text = "1000";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "Тестовая задача",
            "Основная задача 1",
            "Основная задача 2"});
            this.comboBox1.Location = new System.Drawing.Point(5, 7);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(167, 28);
            this.comboBox1.TabIndex = 21;
            this.comboBox1.Tag = "";
            // 
            // buttonSolve
            // 
            this.buttonSolve.Location = new System.Drawing.Point(13, 179);
            this.buttonSolve.Name = "buttonSolve";
            this.buttonSolve.Size = new System.Drawing.Size(159, 29);
            this.buttonSolve.TabIndex = 22;
            this.buttonSolve.Text = "Построить";
            this.buttonSolve.UseVisualStyleBackColor = true;
            this.buttonSolve.Click += new System.EventHandler(this.buttonSolve_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonSolve);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.textBox_Nmax);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.textBox_klp);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.textBox_eps);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.textBox_h);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.textBox_u0);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBox_b);
            this.Controls.Add(this.textBox_a);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.DataTable_table);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.DataTable_table)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView DataTable_table;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox_a;
        private System.Windows.Forms.TextBox textBox_b;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBox_u0;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox textBox_h;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox textBox_eps;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox textBox_klp;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox textBox_Nmax;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button buttonSolve;
    }
}

