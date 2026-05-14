#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>

using namespace std;

class Student {
protected:
    string lastName;
    string firstName;
    string patronymic;
    int course;
    string idNumber;
    int rating;

    void validate() {
        if (course < 1 || course > 6) throw invalid_argument("Invalid course");
        if (rating < 0 || rating > 100) throw invalid_argument("Invalid rating");
        if (lastName.empty() || firstName.empty() || idNumber.empty()) throw invalid_argument("Empty fields");
    }

public:
    Student() : course(1), rating(0) {}

    Student(string ln, string fn, string p, int c, string id, int r)
        : lastName(move(ln)), firstName(move(fn)), patronymic(move(p)), course(c), idNumber(move(id)), rating(r) {
        validate();
    }

    Student(const Student& other) = default;
    Student(Student&& other) noexcept = default;
    Student& operator=(const Student& other) = default;
    Student& operator=(Student&& other) noexcept = default;
    virtual ~Student() = default;

    friend Student& operator++(Student& s) {
        if (s.course < 6) s.course++;
        return s;
    }

    Student& operator^(int newRating) {
        if (newRating >= 0 && newRating <= 100) rating = newRating;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Student& s) {
        s.print(os);
        return os;
    }

    friend istream& operator>>(istream& is, Student& s) {
        s.read(is);
        return is;
    }

    virtual void print(ostream& os) const {
        os << lastName << "|" << firstName << "|" << patronymic << "|" << course << "|" << idNumber << "|" << rating;
    }

    virtual void read(istream& is) {
        string line;
        if (getline(is, line)) {
            stringstream ss(line);
            string c_str, r_str;
            getline(ss, lastName, '|');
            getline(ss, firstName, '|');
            getline(ss, patronymic, '|');
            getline(ss, c_str, '|');
            getline(ss, idNumber, '|');
            getline(ss, r_str, '|');
            try {
                course = stoi(c_str);
                rating = stoi(r_str);
                validate();
            } catch (...) {
                is.setstate(ios::failbit);
            }
        }
    }

    virtual string GetStringData() const {
        return lastName + " " + firstName;
    }

    string getId() const { return idNumber; }
    string getLastName() const { return lastName; }

    void updateBasicInfo(const string& ln, const string& fn, const string& p, int c, int r) {
        int old_c = course;
        int old_r = rating;
        string old_ln = lastName;
        string old_fn = firstName;
        string old_p = patronymic;
        
        course = c;
        rating = r;
        lastName = ln;
        firstName = fn;
        patronymic = p;
        
        try {
            validate();
        } catch(...) {
            course = old_c;
            rating = old_r;
            lastName = old_ln;
            firstName = old_fn;
            patronymic = old_p;
            throw;
        }
    }
};

class StudentDiploma : public Student {
private:
    string diplomaTopic;
    int completionPercentage;

    void validateDiploma() {
        if (completionPercentage < 0 || completionPercentage > 100) throw invalid_argument("Invalid percentage");
        if (diplomaTopic.empty()) throw invalid_argument("Empty topic");
    }

public:
    StudentDiploma() : Student(), completionPercentage(0) {}

    StudentDiploma(string ln, string fn, string p, int c, string id, int r, string topic, int perc)
        : Student(move(ln), move(fn), move(p), c, move(id), r), diplomaTopic(move(topic)), completionPercentage(perc) {
        validateDiploma();
    }

    ~StudentDiploma() override = default;

    void updateDiplomaInfo(const string& topic, int perc) {
        int old_perc = completionPercentage;
        string old_topic = diplomaTopic;
        
        completionPercentage = perc;
        diplomaTopic = topic;
        
        try {
            validateDiploma();
        } catch(...) {
            completionPercentage = old_perc;
            diplomaTopic = old_topic;
            throw;
        }
    }

    int getCompletionPercentage() const { return completionPercentage; }
    string GetStringData() const override { return diplomaTopic; }

    void print(ostream& os) const override {
        Student::print(os);
        os << "|" << diplomaTopic << "|" << completionPercentage;
    }

    void read(istream& is) override {
        string line;
        if (getline(is, line)) {
            stringstream ss(line);
            string c_str, r_str, p_str;
            getline(ss, lastName, '|');
            getline(ss, firstName, '|');
            getline(ss, patronymic, '|');
            getline(ss, c_str, '|');
            getline(ss, idNumber, '|');
            getline(ss, r_str, '|');
            getline(ss, diplomaTopic, '|');
            getline(ss, p_str, '|');
            try {
                course = stoi(c_str);
                rating = stoi(r_str);
                completionPercentage = stoi(p_str);
                validate();
                validateDiploma();
            } catch (...) {
                is.setstate(ios::failbit);
            }
        }
    }
};

class GroupIterator {
private:
    vector<StudentDiploma*>& collection;
    size_t index;
public:
    GroupIterator(vector<StudentDiploma*>& coll) : collection(coll), index(0) {}
    bool hasNext() const { return index < collection.size(); }
    StudentDiploma* next() {
        if (!hasNext()) throw out_of_range("Out of elements");
        return collection[index++];
    }
    void reset() { index = 0; }
};

class Group {
private:
    vector<StudentDiploma*> students;

public:
    ~Group() { clear(); }

    void clear() {
        for (auto s : students) delete s;
        students.clear();
    }

    void addStudent(StudentDiploma* s) {
        if (s) {
            for (auto ex : students) {
                if (ex->getId() == s->getId()) {
                    delete s;
                    throw invalid_argument("ID already exists");
                }
            }
            students.push_back(s);
        }
    }

    void removeStudent(const string& id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if ((*it)->getId() == id) {
                delete *it;
                students.erase(it);
                return;
            }
        }
        throw invalid_argument("Student not found");
    }

    StudentDiploma* getStudent(const string& id) {
        for (auto s : students) {
            if (s->getId() == id) return s;
        }
        return nullptr;
    }

    GroupIterator createIterator() { return GroupIterator(students); }

    void displayAll() const {
        if (students.empty()) {
            cout << "List is empty.\n";
            return;
        }
        for (auto s : students) {
            s->print(cout);
            cout << "\n";
        }
    }

    void showHighAchievers() {
        GroupIterator it = createIterator();
        bool found = false;
        while (it.hasNext()) {
            StudentDiploma* s = it.next();
            if (s->getCompletionPercentage() > 80) {
                cout << s->getLastName() << " - " << s->getCompletionPercentage() << "%\n";
                found = true;
            }
        }
        if (!found) cout << "No high achievers found.\n";
    }

    void saveToFile(const string& filename) {
        ofstream out(filename);
        if (!out) throw runtime_error("Cannot open file");
        for (auto s : students) out << *s << "\n";
    }

    void loadFromFile(const string& filename) {
        ifstream in(filename);
        if (!in) throw runtime_error("Cannot open file");
        clear();
        string line;
        while (getline(in, line)) {
            if(line.empty()) continue;
            stringstream ss(line);
            StudentDiploma* s = new StudentDiploma();
            ss >> *s;
            if (!ss.fail()) {
                students.push_back(s);
            } else {
                delete s;
            }
        }
    }

    void demonstrateLateBinding() {
        if(students.empty()) {
            cout << "List is empty.\n";
            return;
        }
        Student* basePtr = students[0];
        cout << "Late Binding Test: " << basePtr->GetStringData() << "\n";
    }
};

int getInputInt(const string& prompt) {
    int value;
    string line;
    while (true) {
        cout << prompt;
        getline(cin, line);
        try {
            size_t pos;
            value = stoi(line, &pos);
            if (pos == line.length()) return value;
        } catch (...) {}
        cout << "Invalid input. Please enter an integer.\n";
    }
}

string getInputString(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

int main() {
    Group group;
    int choice;

    do {
        cout << "\n--- Student Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Edit Student Data\n";
        cout << "4. Increment Course (++)\n";
        cout << "5. Change Rating (^)\n";
        cout << "6. Display All Students\n";
        cout << "7. Show High Achievers (>80%)\n";
        cout << "8. Test Late Binding\n";
        cout << "9. Save to File\n";
        cout << "10. Load from File\n";
        cout << "0. Exit\n";
        
        choice = getInputInt("Select option: ");

        try {
            switch (choice) {
                case 1: {
                    string ln = getInputString("Last Name: ");
                    string fn = getInputString("First Name: ");
                    string p = getInputString("Patronymic: ");
                    int c = getInputInt("Course (1-6): ");
                    string id = getInputString("ID Number: ");
                    int r = getInputInt("Rating (0-100): ");
                    string t = getInputString("Diploma Topic: ");
                    int perc = getInputInt("Completion % (0-100): ");
                    group.addStudent(new StudentDiploma(ln, fn, p, c, id, r, t, perc));
                    cout << "Operation successful.\n";
                    break;
                }
                case 2: {
                    string id = getInputString("Enter Student ID to remove: ");
                    group.removeStudent(id);
                    cout << "Operation successful.\n";
                    break;
                }
                case 3: {
                    string id = getInputString("Enter Student ID to edit: ");
                    StudentDiploma* s = group.getStudent(id);
                    if (!s) {
                        cout << "Student not found.\n";
                        break;
                    }
                    cout << "Enter new details:\n";
                    string ln = getInputString("New Last Name: ");
                    string fn = getInputString("New First Name: ");
                    string p = getInputString("New Patronymic: ");
                    int c = getInputInt("New Course (1-6): ");
                    int r = getInputInt("New Rating (0-100): ");
                    string t = getInputString("New Diploma Topic: ");
                    int perc = getInputInt("New Completion % (0-100): ");
                    
                    s->updateBasicInfo(ln, fn, p, c, r);
                    s->updateDiplomaInfo(t, perc);
                    cout << "Operation successful.\n";
                    break;
                }
                case 4: {
                    string id = getInputString("Enter Student ID: ");
                    StudentDiploma* s = group.getStudent(id);
                    if (s) {
                        ++(*s);
                        cout << "Course incremented.\n";
                    } else cout << "Student not found.\n";
                    break;
                }
                case 5: {
                    string id = getInputString("Enter Student ID: ");
                    StudentDiploma* s = group.getStudent(id);
                    if (s) {
                        int r = getInputInt("Enter new rating: ");
                        (*s) ^ r;
                        cout << "Rating updated.\n";
                    } else cout << "Student not found.\n";
                    break;
                }
                case 6:
                    group.displayAll();
                    break;
                case 7:
                    group.showHighAchievers();
                    break;
                case 8:
                    group.demonstrateLateBinding();
                    break;
                case 9:
                    group.saveToFile("data.txt");
                    cout << "Saved to data.txt.\n";
                    break;
                case 10:
                    group.loadFromFile("data.txt");
                    cout << "Loaded from data.txt.\n";
                    break;
                case 0:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid option.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    } while (choice != 0);

    return 0;
}