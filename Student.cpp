#include "Student.h"

Student::Student() : lastName(""), firstName(""), middleName(""), course(1), id(""), rating(0) {}

Student::Student(string lName, string fName, string mName, int c, string i, int r) {
    lastName = lName;
    firstName = fName;
    middleName = mName;
    course = (c >= 1 && c <= 6) ? c : 1;
    id = i;
    rating = (r >= 0 && r <= 100) ? r : 0;
}

Student::Student(const Student& other) : lastName(other.lastName), firstName(other.firstName), middleName(other.middleName), course(other.course), id(other.id), rating(other.rating) {}

Student::Student(Student&& other) noexcept : lastName(move(other.lastName)), firstName(move(other.firstName)), middleName(move(other.middleName)), course(other.course), id(move(other.id)), rating(other.rating) {
    other.course = 1;
    other.rating = 0;
}

Student::~Student() {}

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

Student& Student::operator=(Student&& other) noexcept {
    if (this != &other) {
        lastName = move(other.lastName);
        firstName = move(other.firstName);
        middleName = move(other.middleName);
        course = other.course;
        id = move(other.id);
        rating = other.rating;
        other.course = 1;
        other.rating = 0;
    }
    return *this;
}

Student& operator++(Student& s) {
    if (s.course < 6) {
        s.course++;
    }
    return s;
}

Student Student::operator^(int newRating) {
    if (newRating >= 0 && newRating <= 100) {
        this->rating = newRating;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Student& s) {
    os << s.lastName << "," << s.firstName << "," << s.middleName << "," << s.course << "," << s.id << "," << s.rating;
    return os;
}

istream& operator>>(istream& is, Student& s) {
    string temp;
    getline(is, s.lastName, ',');
    getline(is, s.firstName, ',');
    getline(is, s.middleName, ',');
    getline(is, temp, ',');
    s.course = temp.empty() ? 1 : stoi(temp);
    getline(is, s.id, ',');
    getline(is, temp, '\n');
    s.rating = temp.empty() ? 0 : stoi(temp);
    return is;
}

string Student::GetStringData() const {
    return lastName + " " + firstName;
}

string Student::GetId() const {
    return id;
}