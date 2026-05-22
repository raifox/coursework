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
    ~StudentDiploma() override;

    string GetTheme() const;
    void SetTheme(string t);

    int GetProgress() const;
    void SetProgress(int p);

    string GetStringData() const override;

    friend istream& operator>>(istream& is, StudentDiploma& sd);
    friend ostream& operator<<(ostream& os, const StudentDiploma& sd);
};