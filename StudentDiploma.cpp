#include "StudentDiploma.h"

StudentDiploma::StudentDiploma() : Student() {
    theme = "";
    progress = 0;
}

StudentDiploma::StudentDiploma(string lName, string fName, string mName, int c, string i, int r, string t, int p)
    : Student(lName, fName, mName, c, i, r) {
    theme = t;
    SetProgress(p);
}

StudentDiploma::StudentDiploma(const StudentDiploma& other) : Student(other) {
    theme = other.theme;
    progress = other.progress;
}

StudentDiploma::~StudentDiploma() {}

string StudentDiploma::GetTheme() const { return theme; }
void StudentDiploma::SetTheme(string t) { theme = t; }

int StudentDiploma::GetProgress() const { return progress; }
void StudentDiploma::SetProgress(int p) {
    if (p < 0 || p > 100) {
        throw invalid_argument("Percentage must be between 0 and 100");
    }
    progress = p;
}

string StudentDiploma::GetStringData() const {
    return theme;
}

istream& operator>>(istream& is, StudentDiploma& sd) {
    is >> static_cast<Student&>(sd);
    
    string progStr;
    getline(is, sd.theme, ',');
    getline(is, progStr);
    
    try {
        if (!progStr.empty()) sd.progress = stoi(progStr);
    } catch (...) {}
    
    return is;
}

ostream& operator<<(ostream& os, const StudentDiploma& sd) {
    os << static_cast<const Student&>(sd) << "," << sd.theme << "," << sd.progress;
    return os;
}