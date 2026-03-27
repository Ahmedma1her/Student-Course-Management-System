#include "student.h"

int main()
{
    vector<Student> studentList;

    loadFromFile(studentList);

    int userChoice;

    do
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Enroll Course\n";
        cout << "6. Show Student Courses\n";
        cout << "7. Sort Students by GPA\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> userChoice))
        {
            clearInput();
            cout << "Invalid choice ID, Must be a number!\n";
            continue;
        }

        switch (userChoice)
        {
        case 1:
            addStudent(studentList);
            break;
        case 2:
            removeStudent(studentList);
            break;
        case 3:
            searchStudent(studentList);
            break;
        case 4:
            displayAll(studentList);
            break;
        case 5:
            enrollCourse(studentList);
            break;
        case 6:
            showCourses(studentList);
            break;
        case 7:
            sortStudents(studentList);
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (userChoice != 8);

    saveToFile(studentList);

    return 0;
}