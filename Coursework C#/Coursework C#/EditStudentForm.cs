using System;
using System.Windows.Forms;

namespace Coursework_C_
{
    public partial class EditStudentForm : Form
    {
        private Group _group;
        private string _filePath;
        private string _studentId;

        public EditStudentForm(Group group, string filePath, string studentId)
        {
            InitializeComponent();
            _group = group;
            _filePath = filePath;
            _studentId = studentId;
            LoadStudentData();
        }

        private void LoadStudentData()
        {
            var student = _group.GetStudent(_studentId);
            if (student != null)
            {
                txtLastName.Text = student.LastName;
                txtFirstName.Text = student.FirstName;
                txtPatronymic.Text = student.Patronymic;
                txtCourse.Text = student.Course.ToString();
                txtId.Text = student.IdNumber;
                txtRating.Text = student.Rating.ToString();
                txtTopic.Text = student.DiplomaTopic;
                txtPercentage.Text = student.CompletionPercentage.ToString();

                txtId.Enabled = false;
            }
        }
        private void btnCancel_Click_1(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnSave_Click_1(object sender, EventArgs e)
        {
            try
            {
                var student = _group.GetStudent(_studentId);
                if (student != null)
                {
                    student.LastName = txtLastName.Text;
                    student.FirstName = txtFirstName.Text;
                    student.Patronymic = txtPatronymic.Text;
                    student.Course = int.Parse(txtCourse.Text);
                    student.Rating = int.Parse(txtRating.Text);
                    student.DiplomaTopic = txtTopic.Text;
                    student.CompletionPercentage = int.Parse(txtPercentage.Text);

                    _group.SaveToFile(_filePath);
                    this.Close();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Validation Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}