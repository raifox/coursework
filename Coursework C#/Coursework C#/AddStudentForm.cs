using System;
using System.Windows.Forms;

namespace Coursework_C_
{
    public partial class AddStudentForm : Form
    {
        private Group _group;
        private string _filePath;

        public AddStudentForm(Group group, string filePath)
        {
            InitializeComponent();
            _group = group;
            _filePath = filePath;
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                var student = new StudentDiploma(
                    txtLastName.Text,
                    txtFirstName.Text,
                    txtPatronymic.Text,
                    int.Parse(txtCourse.Text),
                    txtId.Text,
                    int.Parse(txtRating.Text),
                    txtTopic.Text,
                    int.Parse(txtPercentage.Text)
                );

                _group.Add(student);
                _group.SaveToFile(_filePath);
                this.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Validation Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}