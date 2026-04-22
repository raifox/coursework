#include <iostream>
#include <string>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Group myGroup(5);

    myGroup.addStudent(DiplomaStudent("Арендач Олександр", 4, "111", 90, "Веб-додаток", 85));
    myGroup.addStudent(DiplomaStudent("Іваненко Іван", 4, "222", 75, "База даних", 40));
    myGroup.addStudent(DiplomaStudent("Коваленко Анна", 4, "333", 95, "Мобільна гра", 99));
    myGroup.addStudent(DiplomaStudent("Шевченко Тарас", 4, "444", 80, "Нейромережа", 70));

    cout << "Студенти з виконанням понад 80%:\n\n";

    for (GroupIterator it = myGroup.begin(); it != myGroup.end(); ++it) {
        if ((*it).getCompletionPercentage() > 80) {
            std::cout << (*it).getStringData() << " (Виконано: " 
                      << (*it).getCompletionPercentage() << "%)\n";
        }
    }

    return 0;
}