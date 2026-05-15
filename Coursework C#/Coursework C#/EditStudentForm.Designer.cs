namespace Coursework_C_
{
    partial class EditStudentForm
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
            btnCancel = new Button();
            btnSave = new Button();
            txtPercentage = new TextBox();
            txtTopic = new TextBox();
            txtRating = new TextBox();
            txtId = new TextBox();
            txtCourse = new TextBox();
            txtPatronymic = new TextBox();
            txtFirstName = new TextBox();
            txtLastName = new TextBox();
            label8 = new Label();
            label7 = new Label();
            label6 = new Label();
            label5 = new Label();
            label4 = new Label();
            label3 = new Label();
            label2 = new Label();
            label1 = new Label();
            SuspendLayout();
            // 
            // btnCancel
            // 
            btnCancel.Location = new Point(134, 276);
            btnCancel.Name = "btnCancel";
            btnCancel.Size = new Size(75, 23);
            btnCancel.TabIndex = 35;
            btnCancel.Text = "Cancel";
            btnCancel.UseVisualStyleBackColor = true;
            btnCancel.Click += btnCancel_Click_1;
            // 
            // btnSave
            // 
            btnSave.Location = new Point(12, 276);
            btnSave.Name = "btnSave";
            btnSave.Size = new Size(75, 23);
            btnSave.TabIndex = 34;
            btnSave.Text = "Save";
            btnSave.UseVisualStyleBackColor = true;
            btnSave.Click += btnSave_Click_1;
            // 
            // txtPercentage
            // 
            txtPercentage.Location = new Point(109, 226);
            txtPercentage.Name = "txtPercentage";
            txtPercentage.Size = new Size(100, 23);
            txtPercentage.TabIndex = 33;
            // 
            // txtTopic
            // 
            txtTopic.Location = new Point(109, 196);
            txtTopic.Name = "txtTopic";
            txtTopic.Size = new Size(100, 23);
            txtTopic.TabIndex = 32;
            // 
            // txtRating
            // 
            txtRating.Location = new Point(109, 166);
            txtRating.Name = "txtRating";
            txtRating.Size = new Size(100, 23);
            txtRating.TabIndex = 31;
            // 
            // txtId
            // 
            txtId.Location = new Point(109, 136);
            txtId.Name = "txtId";
            txtId.Size = new Size(100, 23);
            txtId.TabIndex = 30;
            // 
            // txtCourse
            // 
            txtCourse.Location = new Point(109, 106);
            txtCourse.Name = "txtCourse";
            txtCourse.Size = new Size(100, 23);
            txtCourse.TabIndex = 29;
            // 
            // txtPatronymic
            // 
            txtPatronymic.Location = new Point(109, 76);
            txtPatronymic.Name = "txtPatronymic";
            txtPatronymic.Size = new Size(100, 23);
            txtPatronymic.TabIndex = 28;
            // 
            // txtFirstName
            // 
            txtFirstName.Location = new Point(109, 46);
            txtFirstName.Name = "txtFirstName";
            txtFirstName.Size = new Size(100, 23);
            txtFirstName.TabIndex = 27;
            // 
            // txtLastName
            // 
            txtLastName.Location = new Point(109, 16);
            txtLastName.Name = "txtLastName";
            txtLastName.Size = new Size(100, 23);
            txtLastName.TabIndex = 26;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(12, 229);
            label8.Name = "label8";
            label8.Size = new Size(66, 15);
            label8.TabIndex = 25;
            label8.Text = "Percentage";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(12, 199);
            label7.Name = "label7";
            label7.Size = new Size(36, 15);
            label7.TabIndex = 24;
            label7.Text = "Topic";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(12, 169);
            label6.Name = "label6";
            label6.Size = new Size(41, 15);
            label6.TabIndex = 23;
            label6.Text = "Rating";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(12, 139);
            label5.Name = "label5";
            label5.Size = new Size(17, 15);
            label5.TabIndex = 22;
            label5.Text = "Id";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(12, 109);
            label4.Name = "label4";
            label4.Size = new Size(44, 15);
            label4.TabIndex = 21;
            label4.Text = "Course";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(12, 79);
            label3.Name = "label3";
            label3.Size = new Size(68, 15);
            label3.TabIndex = 20;
            label3.Text = "Patronymic";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(12, 49);
            label2.Name = "label2";
            label2.Size = new Size(61, 15);
            label2.TabIndex = 19;
            label2.Text = "FirstName";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(12, 19);
            label1.Name = "label1";
            label1.Size = new Size(60, 15);
            label1.TabIndex = 18;
            label1.Text = "LastName";
            // 
            // EditStudentForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(230, 310);
            Controls.Add(btnCancel);
            Controls.Add(btnSave);
            Controls.Add(txtPercentage);
            Controls.Add(txtTopic);
            Controls.Add(txtRating);
            Controls.Add(txtId);
            Controls.Add(txtCourse);
            Controls.Add(txtPatronymic);
            Controls.Add(txtFirstName);
            Controls.Add(txtLastName);
            Controls.Add(label8);
            Controls.Add(label7);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "EditStudentForm";
            Text = "Editing Student...";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button btnCancel;
        private Button btnSave;
        private TextBox txtPercentage;
        private TextBox txtTopic;
        private TextBox txtRating;
        private TextBox txtId;
        private TextBox txtCourse;
        private TextBox txtPatronymic;
        private TextBox txtFirstName;
        private TextBox txtLastName;
        private Label label8;
        private Label label7;
        private Label label6;
        private Label label5;
        private Label label4;
        private Label label3;
        private Label label2;
        private Label label1;
    }
}