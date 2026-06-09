namespace Coursework_C_
{
    partial class journal
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(journal));
            toolStrip1 = new ToolStrip();
            tsbAdd = new ToolStripButton();
            tsbEdit = new ToolStripButton();
            tsbDelete = new ToolStripButton();
            toolStripSeparator1 = new ToolStripSeparator();
            tsbFilter = new ToolStripDropDownButton();
            tsmiShowAll = new ToolStripMenuItem();
            tsmiHighAchievers = new ToolStripMenuItem();
            toolStripButton1 = new ToolStripButton();
            dgvStudents = new DataGridView();
            toolStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)dgvStudents).BeginInit();
            SuspendLayout();
            // 
            // toolStrip1
            // 
            toolStrip1.Items.AddRange(new ToolStripItem[] { tsbAdd, tsbEdit, tsbDelete, toolStripSeparator1, tsbFilter, toolStripButton1 });
            toolStrip1.Location = new Point(0, 0);
            toolStrip1.Name = "toolStrip1";
            toolStrip1.Size = new Size(564, 25);
            toolStrip1.TabIndex = 0;
            toolStrip1.Text = "toolStrip1";
            // 
            // tsbAdd
            // 
            tsbAdd.DisplayStyle = ToolStripItemDisplayStyle.Image;
            tsbAdd.Image = Properties.Resources.plus;
            tsbAdd.ImageTransparentColor = Color.Magenta;
            tsbAdd.Name = "tsbAdd";
            tsbAdd.Size = new Size(23, 22);
            tsbAdd.Text = "+";
            tsbAdd.Click += tsbAdd_Click_1;
            // 
            // tsbEdit
            // 
            tsbEdit.DisplayStyle = ToolStripItemDisplayStyle.Image;
            tsbEdit.Image = Properties.Resources.pen_57;
            tsbEdit.ImageTransparentColor = Color.Magenta;
            tsbEdit.Name = "tsbEdit";
            tsbEdit.Size = new Size(23, 22);
            tsbEdit.Text = "toolStripButton3";
            tsbEdit.Click += tsbEdit_Click_1;
            // 
            // tsbDelete
            // 
            tsbDelete.DisplayStyle = ToolStripItemDisplayStyle.Image;
            tsbDelete.Image = Properties.Resources.trashbin;
            tsbDelete.ImageTransparentColor = Color.Magenta;
            tsbDelete.Name = "tsbDelete";
            tsbDelete.Size = new Size(23, 22);
            tsbDelete.Text = "-";
            tsbDelete.ToolTipText = "-";
            tsbDelete.Click += tsbDelete_Click_1;
            // 
            // toolStripSeparator1
            // 
            toolStripSeparator1.Name = "toolStripSeparator1";
            toolStripSeparator1.Size = new Size(6, 25);
            // 
            // tsbFilter
            // 
            tsbFilter.DisplayStyle = ToolStripItemDisplayStyle.Image;
            tsbFilter.DropDownItems.AddRange(new ToolStripItem[] { tsmiShowAll, tsmiHighAchievers });
            tsbFilter.Image = Properties.Resources.filter1;
            tsbFilter.ImageTransparentColor = Color.Magenta;
            tsbFilter.Name = "tsbFilter";
            tsbFilter.Size = new Size(29, 22);
            tsbFilter.Text = "toolStripDropDownButton1";
            // 
            // tsmiShowAll
            // 
            tsmiShowAll.Name = "tsmiShowAll";
            tsmiShowAll.Size = new Size(227, 22);
            tsmiShowAll.Text = "Show All Students";
            tsmiShowAll.Click += showAllStudentsToolStripMenuItem_Click;
            // 
            // tsmiHighAchievers
            // 
            tsmiHighAchievers.Name = "tsmiHighAchievers";
            tsmiHighAchievers.Size = new Size(227, 22);
            tsmiHighAchievers.Text = "Show High Achievers (>80%)";
            tsmiHighAchievers.Click += tsmiHighAchievers_Click;
            // 
            // toolStripButton1
            // 
            toolStripButton1.DisplayStyle = ToolStripItemDisplayStyle.Text;
            toolStripButton1.Image = (Image)resources.GetObject("toolStripButton1.Image");
            toolStripButton1.ImageTransparentColor = Color.Magenta;
            toolStripButton1.Name = "toolStripButton1";
            toolStripButton1.Size = new Size(37, 22);
            toolStripButton1.Text = "TEST";
            toolStripButton1.Click += toolStripButton1_Click_1;
            // 
            // dgvStudents
            // 
            dgvStudents.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvStudents.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvStudents.Dock = DockStyle.Fill;
            dgvStudents.Location = new Point(0, 25);
            dgvStudents.Name = "dgvStudents";
            dgvStudents.Size = new Size(564, 425);
            dgvStudents.TabIndex = 1;
            dgvStudents.CellContentClick += dgvStudents_CellContentClick;
            // 
            // journal
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(564, 450);
            Controls.Add(dgvStudents);
            Controls.Add(toolStrip1);
            Name = "journal";
            Text = "Student Journal";
            toolStrip1.ResumeLayout(false);
            toolStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)dgvStudents).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ToolStrip toolStrip1;
        private ToolStripButton tsbAdd;
        private ToolStripButton tsbDelete;
        private ToolStripButton tsbEdit;
        private DataGridView dgvStudents;
        private ToolStripDropDownButton tsbFilter;
        private ToolStripMenuItem tsmiShowAll;
        private ToolStripMenuItem tsmiHighAchievers;
        private ToolStripButton toolStripButton1;
        private ToolStripSeparator toolStripSeparator1;
    }
}
