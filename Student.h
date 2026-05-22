#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

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
    Student(Student&& other);
    virtual ~Student();

    string GetLastName() const;
    void SetLastName(string lName);

    string GetFirstName() const;
    void SetFirstName(string fName);

    string GetMiddleName() const;
    void SetMiddleName(string mName);

    int GetCourse() const;
    void SetCourse(int c);

    string GetId() const;
    void SetId(string i);

    int GetRating() const;
    void SetRating(int r);

    friend Student& operator++(Student& s);
    Student operator^(int newRating);
    Student& operator=(const Student& other);
    Student& operator=(Student&& other);

    friend istream& operator>>(istream& is, Student& s);
    friend ostream& operator<<(ostream& os, const Student& s);

    virtual string GetStringData() const;
};