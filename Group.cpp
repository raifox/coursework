#include "Group.h"
#include <fstream>
#include <iostream>

GroupIterator::GroupIterator(const vector<StudentDiploma*>& s) : students(s), index(0) {}

bool GroupIterator::hasNext() const {
    return index < students.size();
}

StudentDiploma* GroupIterator::next() {
    if (hasNext()) {
        return students[index++];
    }
    throw out_of_range("Out of range");
}

Group::Group() {}

Group::~Group() {
    for (auto student : students) {
        delete student;
    }
    students.clear();
}

void Group::AddStudent(StudentDiploma* student) {
    for (auto s : students) {
        if (s->GetId() == student->GetId()) {
            cout << "Error: ID already exists!" << endl;
            delete student;
            return;
        }
    }
    students.push_back(student);
}

void Group::RemoveStudent(string id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if ((*it)->GetId() == id) {
            delete *it;
            students.erase(it);
            return;
        }
    }
}

void Group::SaveToFile(string filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        for (auto student : students) {
            file << *student << endl;
        }
        file.close();
    }
}

void Group::LoadFromFile(string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        for (auto student : students) {
            delete student;
        }
        students.clear();

        StudentDiploma temp;
        while (file >> temp) {
            students.push_back(new StudentDiploma(temp));
        }
        file.close();
    }
}

string Group::GenerateNextId() const {
    if (students.empty()) {
        return "1001";
    }
    
    int maxId = 0;
    for (auto s : students) {
        try {
            int currentId = stoi(s->GetId());
            if (currentId > maxId) {
                maxId = currentId;
            }
        } catch (...) {
            continue;
        }
    }
    
    if (maxId == 0) {
        return "1001";
    }
    
    return to_string(maxId + 1);
}

GroupIterator Group::CreateIterator() const {
    return GroupIterator(students);
}