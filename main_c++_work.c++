#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>

class Student {
protected:
    std::string lastName;
    std::string firstName;
    std::string patronymic;
    int course;
    std::string idNumber;
    int rating;

    void validate() {
        if (course < 1 || course > 6) throw std::invalid_argument("Invalid course");
        if (rating < 0 || rating > 100) throw std::invalid_argument("Invalid rating");
        if (lastName.empty() || firstName.empty() || idNumber.empty()) throw std::invalid_argument("Empty fields");
    }

public:
    Student() : course(1), rating(0) {}

    Student(std::string ln, std::string fn, std::string p, int c, std::string id, int r)
        : lastName(std::move(ln)), firstName(std::move(fn)), patronymic(std::move(p)), course(c), idNumber(std::move(id)), rating(r) {
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

    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        s.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Student& s) {
        s.read(is);
        return is;
    }

    virtual void print(std::ostream& os) const {
        os << lastName << "|" << firstName << "|" << patronymic << "|" << course << "|" << idNumber << "|" << rating;
    }

    virtual void read(std::istream& is) {
        std::string line;
        if (std::getline(is, line)) {
            std::stringstream ss(line);
            std::string c_str, r_str;
            std::getline(ss, lastName, '|');
            std::getline(ss, firstName, '|');
            std::getline(ss, patronymic, '|');
            std::getline(ss, c_str, '|');
            std::getline(ss, idNumber, '|');
            std::getline(ss, r_str, '|');
            try {
                course = std::stoi(c_str);
                rating = std::stoi(r_str);
                validate();
            } catch (...) {
                is.setstate(std::ios::failbit);
            }
        }
    }

    virtual std::string GetStringData() const {
        return lastName + " " + firstName;
    }

    std::string getLastName() const { return lastName; }
};

class StudentDiploma : public Student {
private:
    std::string diplomaTopic;
    int completionPercentage;

    void validateDiploma() {
        if (completionPercentage < 0 || completionPercentage > 100) throw std::invalid_argument("Invalid percentage");
        if (diplomaTopic.empty()) throw std::invalid_argument("Empty topic");
    }

public:
    StudentDiploma() : Student(), completionPercentage(0) {}

    StudentDiploma(std::string ln, std::string fn, std::string p, int c, std::string id, int r, std::string topic, int perc)
        : Student(std::move(ln), std::move(fn), std::move(p), c, std::move(id), r), diplomaTopic(std::move(topic)), completionPercentage(perc) {
        validateDiploma();
    }

    ~StudentDiploma() override = default;

    void setDiplomaTopic(const std::string& newTopic) {
        if (!newTopic.empty()) diplomaTopic = newTopic;
    }

    int getCompletionPercentage() const {
        return completionPercentage;
    }

    std::string GetStringData() const override {
        return diplomaTopic;
    }

    void print(std::ostream& os) const override {
        Student::print(os);
        os << "|" << diplomaTopic << "|" << completionPercentage;
    }

    void read(std::istream& is) override {
        std::string line;
        if (std::getline(is, line)) {
            std::stringstream ss(line);
            std::string c_str, r_str, p_str;
            std::getline(ss, lastName, '|');
            std::getline(ss, firstName, '|');
            std::getline(ss, patronymic, '|');
            std::getline(ss, c_str, '|');
            std::getline(ss, idNumber, '|');
            std::getline(ss, r_str, '|');
            std::getline(ss, diplomaTopic, '|');
            std::getline(ss, p_str, '|');
            try {
                course = std::stoi(c_str);
                rating = std::stoi(r_str);
                completionPercentage = std::stoi(p_str);
                validate();
                validateDiploma();
            } catch (...) {
                is.setstate(std::ios::failbit);
            }
        }
    }
};

class GroupIterator {
private:
    std::vector<StudentDiploma*>& collection;
    size_t index;
public:
    GroupIterator(std::vector<StudentDiploma*>& coll) : collection(coll), index(0) {}
    bool hasNext() const { return index < collection.size(); }
    StudentDiploma* next() {
        if (!hasNext()) throw std::out_of_range("No more elements");
        return collection[index++];
    }
    void reset() { index = 0; }
};

class Group {
private:
    std::vector<StudentDiploma*> students;

public:
    ~Group() {
        clear();
    }

    void clear() {
        for (auto s : students) delete s;
        students.clear();
    }

    void addStudent(StudentDiploma* s) {
        if (s) students.push_back(s);
    }

    GroupIterator createIterator() {
        return GroupIterator(students);
    }

    std::vector<std::string> getHighAchievers() {
        std::vector<std::string> result;
        GroupIterator it = createIterator();
        while (it.hasNext()) {
            StudentDiploma* s = it.next();
            if (s->getCompletionPercentage() > 80) {
                result.push_back(s->getLastName());
            }
        }
        return result;
    }

    void saveToFile(const std::string& filename) {
        std::ofstream out(filename);
        if (!out) throw std::runtime_error("Cannot open file");
        for (auto s : students) {
            out << *s << "\n";
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream in(filename);
        if (!in) throw std::runtime_error("Cannot open file");
        clear();
        std::string line;
        while (std::getline(in, line)) {
            if(line.empty()) continue;
            std::stringstream ss(line);
            StudentDiploma* s = new StudentDiploma();
            ss >> *s;
            if (!ss.fail()) {
                addStudent(s);
            } else {
                delete s;
            }
        }
    }
    
    void demonstrateLateBinding() {
        if(students.empty()) return;
        Student* basePtr = students[0];
        std::cout << "Late Binding Test: " << basePtr->GetStringData() << "\n";
    }
};

int main() {
    try {
        Group group;
        group.addStudent(new StudentDiploma("Ivanov", "Ivan", "Ivanovich", 2, "111", 90, "AI Research", 85));
        group.addStudent(new StudentDiploma("Petrov", "Petro", "Petrovich", 2, "222", 70, "Web Dev", 50));

        group.saveToFile("data.txt");

        Group group2;
        group2.loadFromFile("data.txt");

        std::vector<std::string> top = group2.getHighAchievers();
        for (const auto& name : top) {
            std::cout << "High Achiever: " << name << "\n";
        }

        group2.demonstrateLateBinding();
    } catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << "\n";
    }
    return 0;
}