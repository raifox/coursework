#include "Student.h"

Student::Student() {
    lastName = "";
    firstName = "";
    middleName = "";
    course = 1;
    id = "";
    rating = 0;
}

Student::Student(string lName, string fName, string mName, int c, string i, int r) {
    lastName = lName;
    firstName = fName;
    middleName = mName;
    id = i;
    SetCourse(c);
    SetRating(r);
}

Student::Student(const Student& other) {
    lastName = other.lastName;
    firstName = other.firstName;
    middleName = other.middleName;
    course = other.course;
    id = other.id;
    rating = other.rating;
}

Student::Student(Student&& other) {
    lastName = other.lastName;
    firstName = other.firstName;
    middleName = other.middleName;
    course = other.course;
    id = other.id;
    rating = other.rating;

    other.lastName = "";
    other.firstName = "";
    other.middleName = "";
    other.course = 1;
    other.id = "";
    other.rating = 0;
}

Student::~Student() {}

string Student::GetLastName() const { return lastName; }
void Student::SetLastName(string lName) { lastName = lName; }

string Student::GetFirstName() const { return firstName; }
void Student::SetFirstName(string fName) { firstName = fName; }

string Student::GetMiddleName() const { return middleName; }
void Student::SetMiddleName(string mName) { middleName = mName; }

int Student::GetCourse() const { return course; }
void Student::SetCourse(int c) {
    if (c < 1 || c > 6) {
        throw invalid_argument("Course must be between 1 and 6");
    }
    course = c;
}

string Student::GetId() const { return id; }
void Student::SetId(string i) { id = i; }

int Student::GetRating() const { return rating; }
void Student::SetRating(int r) {
    if (r < 0 || r > 100) {
        throw invalid_argument("Rating must be between 0 and 100");
    }
    rating = r;
}

Student& operator++(Student& s) {
    if (s.course < 6) {
        s.course++;
    }
    return s;
}

Student Student::operator^(int newRating) {
    SetRating(newRating);
    return *this;
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        lastName = other.lastName;
        firstName = other.firstName;
        middleName = other.middleName;
        course = other.course;
        id = other.id;
        rating = other.rating;
    }
    return *this;
}

Student& Student::operator=(Student&& other) {
    if (this != &other) {
        lastName = other.lastName;
        firstName = other.firstName;
        middleName = other.middleName;
        course = other.course;
        id = other.id;
        rating = other.rating;

        other.lastName = "";
        other.firstName = "";
        other.middleName = "";
        other.course = 1;
        other.id = "";
        other.rating = 0;
    }
    return *this;
}

istream& operator>>(istream& is, Student& s) {
    is >> s.lastName >> s.firstName >> s.middleName >> s.course >> s.id >> s.rating;
    return is;
}

ostream& operator<<(ostream& os, const Student& s) {
    os << s.lastName << " " << s.firstName << " " << s.middleName << " "
       << s.course << " " << s.id << " " << s.rating;
    return os;
}

string Student::GetStringData() const {
    return lastName + " " + firstName;
}