using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace Coursework_C_
{
    public partial class journal : Form
    {
        private Group _group;
        private string _filePath = "data.csv";

        public journal()
        {
            InitializeComponent();
            _group = new Group();
            UpdateGrid();
        }

        private void UpdateGrid()
        {
            _group.LoadFromFile(_filePath);
            dgvStudents.DataSource = null;
            dgvStudents.DataSource = _group.GetStudents();
        }

        private void showAllStudentsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            UpdateGrid();
        }

        private void tsmiHighAchievers_Click(object sender, EventArgs e)
        {
            dgvStudents.DataSource = null;
            dgvStudents.DataSource = _group.GetHighAchieversFull();
        }

        private void dgvStudents_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
        }

        private void tsbAdd_Click_1(object sender, EventArgs e)
        {
            var addForm = new AddStudentForm(_group, _filePath);
            addForm.ShowDialog();
            UpdateGrid();
        }

        private void tsbEdit_Click_1(object sender, EventArgs e)
        {
            if (dgvStudents.CurrentRow != null)
            {
                string id = dgvStudents.CurrentRow.Cells["IdNumber"].Value.ToString();
                var editForm = new EditStudentForm(_group, _filePath, id);
                editForm.ShowDialog();
                UpdateGrid();
            }
            else
            {
                MessageBox.Show("Select a student to edit.");
            }
        }

        private void tsbDelete_Click_1(object sender, EventArgs e)
        {
            if (dgvStudents.CurrentRow != null)
            {
                string id = dgvStudents.CurrentRow.Cells["IdNumber"].Value.ToString();
                var dialogResult = MessageBox.Show("Delete student?", "Confirm", MessageBoxButtons.YesNo);
                if (dialogResult == DialogResult.Yes)
                {
                    try
                    {
                        _group.Remove(id);
                        _group.SaveToFile(_filePath);
                        UpdateGrid();
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message);
                    }
                }
            }
        }

        private void btnPolymorphismTest_Click_1(object sender, EventArgs e)
        {
            if (!_group.GetEnumerator().MoveNext())
            {
                MessageBox.Show("List is empty.");
                return;
            }

            foreach (Student student in _group)
            {
                MessageBox.Show("Late binding test: " + student.GetStringData());
                break;
            }
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            if (!_group.GetEnumerator().MoveNext())
            {
                MessageBox.Show("List is empty.");
                return;
            }

            foreach (Student student in _group)
            {
                MessageBox.Show("Late binding test: " + student.GetStringData());
                break;
            }
        }

        private void toolStripButton1_Click_1(object sender, EventArgs e)
        {
            if (!_group.GetEnumerator().MoveNext())
            {
                MessageBox.Show("List is empty.");
                return;
            }

            foreach (Student student in _group)
            {
                MessageBox.Show("Late binding test: " + student.GetStringData());
                break;
            }
        }
    }

    public class Student
    {
        public string LastName { get; set; } = string.Empty;
        public string FirstName { get; set; } = string.Empty;
        public string Patronymic { get; set; } = string.Empty;
        public int Course { get; set; }
        public string IdNumber { get; set; } = string.Empty;
        public int Rating { get; set; }

        public Student() { }

        public Student(string ln, string fn, string p, int c, string id, int r)
        {
            LastName = ln;
            FirstName = fn;
            Patronymic = p;
            Course = c;
            IdNumber = id;
            Rating = r;
        }

        public virtual string GetStringData() => $"{LastName} {FirstName}";
    }

    public class StudentDiploma : Student
    {
        public string DiplomaTopic { get; set; } = string.Empty;
        public int CompletionPercentage { get; set; }

        public StudentDiploma() : base() { }

        public StudentDiploma(string ln, string fn, string p, int c, string id, int r, string topic, int perc)
            : base(ln, fn, p, c, id, r)
        {
            DiplomaTopic = topic;
            CompletionPercentage = perc;
        }

        public override string GetStringData() => DiplomaTopic;
    }

    public class Group : IEnumerable<StudentDiploma>
    {
        private List<StudentDiploma> _students = new List<StudentDiploma>();

        public void Add(StudentDiploma student)
        {
            if (student != null)
            {
                if (_students.Any(s => s.IdNumber == student.IdNumber))
                {
                    throw new ArgumentException("ID already exists");
                }
                _students.Add(student);
            }
        }

        public void Remove(string id)
        {
            var student = _students.FirstOrDefault(s => s.IdNumber == id);
            if (student != null)
            {
                _students.Remove(student);
            }
            else
            {
                throw new ArgumentException("Student not found");
            }
        }

        public StudentDiploma GetStudent(string id)
        {
            return _students.FirstOrDefault(s => s.IdNumber == id);
        }

        public List<StudentDiploma> GetStudents() => _students;

        public List<StudentDiploma> GetHighAchieversFull()
        {
            return _students.Where(s => s.CompletionPercentage > 80).ToList();
        }

        public void SaveToFile(string path)
        {
            using (StreamWriter sw = new StreamWriter(path))
            {
                foreach (var s in _students)
                {
                    sw.WriteLine($"{s.LastName},{s.FirstName},{s.Patronymic},{s.Course},{s.IdNumber},{s.Rating},{s.DiplomaTopic},{s.CompletionPercentage}");
                }
            }
        }

        public void LoadFromFile(string path)
        {
            if (!File.Exists(path)) return;

            _students.Clear();
            string[] lines = File.ReadAllLines(path);

            foreach (string line in lines)
            {
                if (string.IsNullOrWhiteSpace(line)) continue;

                string[] parts = line.Split(',');
                if (parts.Length == 8)
                {
                    var student = new StudentDiploma(
                        parts[0], parts[1], parts[2],
                        int.Parse(parts[3]), parts[4],
                        int.Parse(parts[5]), parts[6],
                        int.Parse(parts[7])
                    );
                    _students.Add(student);
                }
            }
        }

        public IEnumerator<StudentDiploma> GetEnumerator() => _students.GetEnumerator();
        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
    }
}