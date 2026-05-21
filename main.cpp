#include "Group.h"
#include <iostream>

void ShowMenu() {
    cout << "\n1. Add student\n"
         << "2. Remove student\n"
         << "3. Show high achievers (>80%)\n"
         << "4. Demonstrate polymorphism\n"
         << "5. Save to file\n"
         << "6. Load from file\n"
         << "0. Exit\n"
         << "Choice: ";
}

int main() {
    Group group;
    int choice;

    do {
        ShowMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string ln, fn, mn, id, theme;
                int c, r, p;
                cout << "Last name: "; cin >> ln;
                cout << "First name: "; cin >> fn;
                cout << "Middle name: "; cin >> mn;
                cout << "Course (1-6): "; cin >> c;
                cout << "ID: "; cin >> id;
                cout << "Rating (0-100): "; cin >> r;
                cout << "Diploma theme: "; cin.ignore(); getline(cin, theme);
                cout << "Progress (0-100): "; cin >> p;
                
                group.AddStudent(new StudentDiploma(ln, fn, mn, c, id, r, theme, p));
                break;
            }
            case 2: {
                string id;
                cout << "Enter ID to remove: "; cin >> id;
                group.RemoveStudent(id);
                break;
            }
            case 3: {
                GroupIterator it = group.CreateIterator();
                while (it.hasNext()) {
                    StudentDiploma* s = it.next();
                    if (s->GetProgress() > 80) {
                        cout << s->GetStringData() << " - Progress: " << s->GetProgress() << "%" << endl;
                    }
                }
                break;
            }
            case 4: {
                GroupIterator it = group.CreateIterator();
                while (it.hasNext()) {
                    StudentDiploma* sd = it.next();
                    Student* basePtr = sd;
                    cout << "Base pointer ID " << basePtr->GetId() << " string data: " << basePtr->GetStringData() << endl;
                }
                break;
            }
            case 5: {
                group.SaveToFile("data.csv");
                cout << "Saved successfully.\n";
                break;
            }
            case 6: {
                group.LoadFromFile("data.csv");
                cout << "Loaded successfully.\n";
                break;
            }
        }
    } while (choice != 0);

    return 0;
}