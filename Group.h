#pragma once
#include "StudentDiploma.h"
#include <vector>
#include <stdexcept>

class GroupIterator {
private:
    const vector<StudentDiploma*>& students;
    size_t index;

public:
    GroupIterator(const vector<StudentDiploma*>& s);
    bool hasNext() const;
    StudentDiploma* next();
};

class Group {
private:
    vector<StudentDiploma*> students;

public:
    Group();
    ~Group();

    void AddStudent(StudentDiploma* student);
    void RemoveStudent(string id);
    StudentDiploma* GetStudent(string id) const;
    void SaveToFile(string filename) const;
    void LoadFromFile(string filename);
    
    string GenerateNextId() const;
    void CloneStudent(string id);
    
    GroupIterator CreateIterator() const;
};