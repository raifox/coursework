#include "StudentDiploma.h"
#include <sstream>

StudentDiploma::StudentDiploma() : Student(), theme(""), progress(0) {}

StudentDiploma::StudentDiploma(string lName, string fName, string mName, int c, string i, int r, string t, int p) 
    : Student(lName, fName, mName, c, i, r) {
    theme = t;
    progress = (p >= 0 && p <= 100) ? p : 0;
}

StudentDiploma::StudentDiploma(const StudentDiploma& other) 
    : Student(other), theme(other.theme), progress(other.progress) {}

int StudentDiploma::GetProgress() const {
    return progress;
}

string StudentDiploma::GetTheme() const {
    return theme;
}

string StudentDiploma::GetStringData() const {
    return theme;
}

ostream& operator<<(ostream& os, const StudentDiploma& sd) {
    os << static_cast<const Student&>(sd) << "," << sd.theme << "," << sd.progress;
    return os;
}

istream& operator>>(istream& is, StudentDiploma& sd) {
    string line;
    if (getline(is, line)) {
        stringstream ss(line);
        string temp;
        getline(ss, sd.lastName, ',');
        getline(ss, sd.firstName, ',');
        getline(ss, sd.middleName, ',');
        getline(ss, temp, ',');
        sd.course = temp.empty() ? 1 : stoi(temp);
        getline(ss, sd.id, ',');
        getline(ss, temp, ',');
        sd.rating = temp.empty() ? 0 : stoi(temp);
        getline(ss, sd.theme, ',');
        getline(ss, temp, '\n');
        sd.progress = temp.empty() ? 0 : stoi(temp);
    }
    return is;
}