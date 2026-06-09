#include <iostream>
#include "Group.h"

using namespace std;

int main() {
    Group group;
    int choice;

    do {
        cout << "\n1. Add student\n";
        cout << "2. Remove student\n";
        cout << "3. Show all students\n";
        cout << "4. Show high achievers (>80%)\n";
        cout << "5. Demonstrate polymorphism\n";
        cout << "6. Save to file\n";
        cout << "7. Load from file\n";
        cout << "8. Clone student\n";
        cout << "9. Edit student\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string ln, fn, mn, theme, id;
                int c, r, p;

                cout << "Enter last name: "; cin >> ln;
                cout << "Enter first name: "; cin >> fn;
                cout << "Enter patronymic: "; cin >> mn;
                cout << "Enter course: "; cin >> c;
                cout << "Enter rating: "; cin >> r;
                cout << "Enter diploma theme: ";
                cin.ignore();
                getline(cin, theme);
                cout << "Enter completion percentage: "; cin >> p;

                id = group.GenerateNextId();

                try {
                    StudentDiploma* student = new StudentDiploma(ln, fn, mn, c, id, r, theme, p);
                    group.AddStudent(student);
                    cout << "Success\n";
                } catch (const invalid_argument& e) {
                    cout << "Error: " << e.what() << "\n";
                }
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
                cout << "\n--- All Students ---\n";
                while (it.hasNext()) {
                    StudentDiploma* s = it.next();
                    cout << "ID: " << s->GetId() 
                         << " | " << s->GetLastName() << " " << s->GetFirstName() << " " << s->GetMiddleName() 
                         << " | Course: " << s->GetCourse() 
                         << " | Rating: " << s->GetRating() 
                         << " | Theme: " << s->GetTheme() 
                         << " | Progress: " << s->GetProgress() << "%\n";
                }
                cout << "--------------------\n";
                break;
            }
            case 4: {
                GroupIterator it = group.CreateIterator();
                cout << "\n--- High Achievers (>80%) ---\n";
                while (it.hasNext()) {
                    StudentDiploma* s = it.next();
                    if (s->GetProgress() > 80) {
                        cout << "ID: " << s->GetId() 
                             << " | " << s->GetLastName() << " " << s->GetFirstName() 
                             << " | Theme: " << s->GetTheme() 
                             << " | Progress: " << s->GetProgress() << "%\n";
                    }
                }
                cout << "-----------------------------\n";
                break;
            }
            case 5: {
                GroupIterator it = group.CreateIterator();
                while (it.hasNext()) {
                    Student* s = it.next();
                    cout << "Polymorphic string: " << s->GetStringData() << "\n";
                }
                break;
            }
            case 6: {
                group.SaveToFile("data.csv");
                cout << "Saved.\n";
                break;
            }
            case 7: {
                group.LoadFromFile("data.csv");
                cout << "Loaded.\n";
                break;
            }
            case 8: {
                string id;
                cout << "Enter ID of the student to clone: "; cin >> id;
                group.CloneStudent(id);
                break;
            }
            case 9: {
                string id;
                cout << "Enter ID of the student to edit: "; cin >> id;
                
                StudentDiploma* s = group.GetStudent(id);
                
                if (s != nullptr) {
                    string ln, fn, mn, theme;
                    int c, r, p;

                    cout << "Enter new last name: "; cin >> ln;
                    cout << "Enter new first name: "; cin >> fn;
                    cout << "Enter new patronymic: "; cin >> mn;
                    cout << "Enter new course: "; cin >> c;
                    cout << "Enter new rating: "; cin >> r;
                    cout << "Enter new diploma theme: ";
                    cin.ignore();
                    getline(cin, theme);
                    cout << "Enter new completion percentage: "; cin >> p;

                    try {
                        s->SetLastName(ln);
                        s->SetFirstName(fn);
                        s->SetMiddleName(mn);
                        s->SetCourse(c);
                        s->SetRating(r);
                        s->SetTheme(theme);
                        s->SetProgress(p);
                        cout << "Success!\n";
                    } catch (const invalid_argument& e) {
                        cout << "Error: " << e.what() << "\n";
                    }
                } else {
                    cout << "Error: Student not found.\n";
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}