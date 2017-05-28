namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.Lift = new System.Windows.Forms.PictureBox();
            this.Floor3 = new System.Windows.Forms.PictureBox();
            this.Floor2 = new System.Windows.Forms.PictureBox();
            this.Floor1 = new System.Windows.Forms.PictureBox();
            this.Floor0 = new System.Windows.Forms.PictureBox();
            this.toFloor3 = new System.Windows.Forms.Button();
            this.timer = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.Lift)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Floor3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Floor2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Floor1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Floor0)).BeginInit();
            this.SuspendLayout();
            // 
            // Lift
            // 
            this.Lift.Image = global::WindowsFormsApplication1.Properties.Resources._18816722_1385631041506344_1466916477_n;
            this.Lift.Location = new System.Drawing.Point(396, 405);
            this.Lift.Name = "Lift";
            this.Lift.Size = new System.Drawing.Size(139, 140);
            this.Lift.TabIndex = 0;
            this.Lift.TabStop = false;
            // 
            // Floor3
            // 
            this.Floor3.BackColor = System.Drawing.Color.Black;
            this.Floor3.Location = new System.Drawing.Point(0, 143);
            this.Floor3.Name = "Floor3";
            this.Floor3.Size = new System.Drawing.Size(400, 7);
            this.Floor3.TabIndex = 3;
            this.Floor3.TabStop = false;
            // 
            // Floor2
            // 
            this.Floor2.BackColor = System.Drawing.Color.Black;
            this.Floor2.Location = new System.Drawing.Point(0, 274);
            this.Floor2.Name = "Floor2";
            this.Floor2.Size = new System.Drawing.Size(400, 7);
            this.Floor2.TabIndex = 4;
            this.Floor2.TabStop = false;
            // 
            // Floor1
            // 
            this.Floor1.BackColor = System.Drawing.Color.Black;
            this.Floor1.Location = new System.Drawing.Point(0, 405);
            this.Floor1.Name = "Floor1";
            this.Floor1.Size = new System.Drawing.Size(400, 7);
            this.Floor1.TabIndex = 5;
            this.Floor1.TabStop = false;
            // 
            // Floor0
            // 
            this.Floor0.BackColor = System.Drawing.Color.Black;
            this.Floor0.Location = new System.Drawing.Point(0, 536);
            this.Floor0.Name = "Floor0";
            this.Floor0.Size = new System.Drawing.Size(400, 7);
            this.Floor0.TabIndex = 6;
            this.Floor0.TabStop = false;
            // 
            // toFloor3
            // 
            this.toFloor3.Location = new System.Drawing.Point(12, 418);
            this.toFloor3.Name = "toFloor3";
            this.toFloor3.Size = new System.Drawing.Size(27, 23);
            this.toFloor3.TabIndex = 7;
            this.toFloor3.Text = "3";
            this.toFloor3.UseVisualStyleBackColor = true;
            this.toFloor3.Click += new System.EventHandler(this.toFloor3_Click);
            // 
            // timer
            // 
            this.timer.Enabled = true;
            this.timer.Interval = 5;
            this.timer.Tick += new System.EventHandler(this.timer_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(743, 575);
            this.Controls.Add(this.toFloor3);
            this.Controls.Add(this.Floor0);
            this.Controls.Add(this.Floor1);
            this.Controls.Add(this.Floor2);
            this.Controls.Add(this.Lift);
            this.Controls.Add(this.Floor3);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.Lift)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Floor3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Floor2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Floor1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Floor0)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox Lift;
        private System.Windows.Forms.PictureBox Floor3;
        private System.Windows.Forms.PictureBox Floor2;
        private System.Windows.Forms.PictureBox Floor1;
        private System.Windows.Forms.PictureBox Floor0;
        private System.Windows.Forms.Button toFloor3;
        private System.Windows.Forms.Timer timer;
    }
}

