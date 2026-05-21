#pragma once
#include <string>
#include <iostream>

using namespace std;

class Student {
protected:
    string lastName;
    string firstName;
    string middleName;
    int course;
    string id;
    int rating;

public:
    Student();
    Student(string lName, string fName, string mName, int c, string i, int r);
    Student(const Student& other);
    Student(Student&& other) noexcept;
    virtual ~Student();

    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;

    friend Student& operator++(Student& s);
    Student operator^(int newRating);

    friend ostream& operator<<(ostream& os, const Student& s);
    friend istream& operator>>(istream& is, Student& s);

    virtual string GetStringData() const;
    string GetId() const;
};