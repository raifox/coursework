#pragma once
#include "Student.h"

class StudentDiploma : public Student {
private:
    string theme;
    int progress;

public:
    StudentDiploma();
    StudentDiploma(string lName, string fName, string mName, int c, string i, int r, string t, int p);
    StudentDiploma(const StudentDiploma& other);

    int GetProgress() const;
    string GetTheme() const;
    string GetStringData() const override;

    friend ostream& operator<<(ostream& os, const StudentDiploma& sd);
    friend istream& operator>>(istream& is, StudentDiploma& sd);
};