#include <windows.h>
#include <iostream>
#include <string>
#include "Group.h"


using namespace std;

int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

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
        
        // Захист від введення літер замість цифр у меню
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            choice = -1; 
            continue;
        }

        switch (choice) {
            case 1: {
                string ln, fn, mn, theme, id;
                int c, r, p;

                cout << "Enter last name: "; cin >> ln;
                cout << "Enter first name: "; cin >> fn;
                cout << "Enter patronymic: "; cin >> mn;
                
                // Перевірка курсу одразу при введенні
                while (true) {
                    cout << "Enter course (1-6): ";
                    if (cin >> c && c >= 1 && c <= 6) break;
                    cout << "Error: Course must be between 1 and 6. Try again.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                // Перевірка рейтингу одразу при введенні
                while (true) {
                    cout << "Enter rating (0-100): ";
                    if (cin >> r && r >= 0 && r <= 100) break;
                    cout << "Error: Rating must be between 0 and 100. Try again.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                cout << "Enter diploma theme: ";
                cin.ignore(10000, '\n'); // Очищуємо буфер перед читанням рядка з пробілами
                getline(cin, theme);

                // Перевірка відсотків одразу при введенні
                while (true) {
                    cout << "Enter completion percentage (0-100): ";
                    if (cin >> p && p >= 0 && p <= 100) break;
                    cout << "Error: Percentage must be between 0 and 100. Try again.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                id = group.GenerateNextId();

                // Тепер ми на 100% впевнені, що дані правильні
                StudentDiploma* student = new StudentDiploma(ln, fn, mn, c, id, r, theme, p);
                group.AddStudent(student);
                cout << "Success\n";
                
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
                    
                    while (true) {
                        cout << "Enter new course (1-6): ";
                        if (cin >> c && c >= 1 && c <= 6) break;
                        cout << "Error: Course must be between 1 and 6. Try again.\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }

                    while (true) {
                        cout << "Enter new rating (0-100): ";
                        if (cin >> r && r >= 0 && r <= 100) break;
                        cout << "Error: Rating must be between 0 and 100. Try again.\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }

                    cout << "Enter new diploma theme: ";
                    cin.ignore(10000, '\n');
                    getline(cin, theme);

                    while (true) {
                        cout << "Enter new completion percentage (0-100): ";
                        if (cin >> p && p >= 0 && p <= 100) break;
                        cout << "Error: Percentage must be between 0 and 100. Try again.\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }

                    s->SetLastName(ln);
                    s->SetFirstName(fn);
                    s->SetMiddleName(mn);
                    s->SetCourse(c);
                    s->SetRating(r);
                    s->SetTheme(theme);
                    s->SetProgress(p);
                    cout << "Success!\n";
                    
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