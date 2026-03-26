#include "student.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

// ================= Student Class Implementation =================
Student::Student(int studentId, string studentName, double gpa)
    : Person(studentName), studentId(studentId), gradePointAverage(gpa) {}

int Student::getId() const { return studentId; }
double Student::getGpa() const { return gradePointAverage; }
string Student::getName() const { return name; }

void Student::display() const
{
    cout << "ID: " << studentId
         << " | Name: " << name
         << " | GPA: " << gradePointAverage << endl;
}

void Student::addCourse(const string &course)
{
    enrolledCourses.insert(course);
}

void Student::showCourses() const
{
    if (enrolledCourses.empty())
    {
        cout << "No courses enrolled\n";
        return;
    }

    cout << "Courses: ";
    for (const auto &c : enrolledCourses)
    {
        cout << c << " ";
    }
    cout << endl;
}

set<string> Student::getCourses() const { return enrolledCourses; }

// ================= Helper Function =================
void clearInput()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

// ================= Functions =================

// Add Student
void addStudent(vector<Student> &studentList)
{
    int studentId;
    string studentName;
    double gpa;

    cout << "Enter ID: ";
    if (!(cin >> studentId))
    {
        clearInput();
        cout << "Invalid ID!\n";
        return;
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, studentName);

    cout << "Enter GPA: ";
    if (!(cin >> gpa))
    {
        clearInput();
        cout << "Invalid GPA!\n";
        return;
    }

    // Check ID uniqueness
    for (const auto &s : studentList)
    {
        if (s.getId() == studentId)
        {
            cout << "ID already exists!\n";
            return;
        }
    }

    // Validate GPA
    if (gpa < 0 || gpa > 4)
    {
        cout << "GPA must be between 0 and 4!\n";
        return;
    }

    studentList.push_back(Student(studentId, studentName, gpa));
    cout << "Student added successfully\n";
}

// Remove Student
void removeStudent(vector<Student> &studentList)
{
    int studentId;
    cout << "Enter ID to remove: ";

    if (!(cin >> studentId))
    {
        clearInput();
        cout << "Invalid input!\n";
        return;
    }

    for (auto it = studentList.begin(); it != studentList.end(); it++)
    {
        if (it->getId() == studentId)
        {
            studentList.erase(it);
            cout << "Removed successfully\n";
            return;
        }
    }

    cout << "Student not found\n";
}

// Search Student
void searchStudent(vector<Student> &studentList)
{
    int studentId;
    cout << "Enter ID to search: ";

    if (!(cin >> studentId))
    {
        clearInput();
        cout << "Invalid input!\n";
        return;
    }

    auto it = find_if(studentList.begin(), studentList.end(),
                      [&](const Student &s)
                      {
                          return s.getId() == studentId;
                      });

    if (it != studentList.end())
    {
        it->display();
    }
    else
    {
        cout << "Student not found\n";
    }
}

// Display All
void displayAll(vector<Student> &studentList)
{
    if (studentList.empty())
    {
        cout << "No students available\n";
        return;
    }

    for (const auto &s : studentList)
    {
        s.display();
    }
}

// Enroll Course
void enrollCourse(vector<Student> &studentList)
{
    int studentId;
    string courseName;

    cout << "Enter Student ID: ";
    if (!(cin >> studentId))
    {
        clearInput();
        cout << "Invalid input!\n";
        return;
    }

    cin.ignore();
    cout << "Enter Course Name: ";
    getline(cin, courseName);

    auto it = find_if(studentList.begin(), studentList.end(),
                      [&](const Student &s)
                      {
                          return s.getId() == studentId;
                      });

    if (it != studentList.end())
    {
        it->addCourse(courseName);
        cout << "Course enrolled successfully\n";
    }
    else
    {
        cout << "Student not found\n";
    }
}

// Show Courses
void showCourses(vector<Student> &studentList)
{
    int studentId;
    cout << "Enter Student ID: ";

    if (!(cin >> studentId))
    {
        clearInput();
        cout << "Invalid input!\n";
        return;
    }

    auto it = find_if(studentList.begin(), studentList.end(),
                      [&](const Student &s)
                      {
                          return s.getId() == studentId;
                      });

    if (it != studentList.end())
    {
        it->showCourses();
    }
    else
    {
        cout << "Student not found\n";
    }
}

// Sort Students
void sortStudents(vector<Student> &studentList)
{
    sort(studentList.begin(), studentList.end(),
         [](const Student &a, const Student &b)
         {
             return a.getGpa() > b.getGpa();
         });

    cout << "Students sorted by GPA\n";
    displayAll(studentList);
}

// Save to File
void saveToFile(vector<Student> &studentList)
{
    ofstream file("students.txt", ios::out);

    if (!file.is_open())
    {
        cout << "Error opening file for saving\n";
        return;
    }

    cout << "Saving " << studentList.size() << " students...\n";

    for (const auto &s : studentList)
    {
        file << s.getId() << "," << s.getName() << "," << s.getGpa() << ",";

        auto courses = s.getCourses();
        bool first = true;

        for (const auto &c : courses)
        {
            if (!first)
                file << ";";
            file << c;
            first = false;
        }
        file << endl;
    }

    file.close();
    cout << "Data saved successfully.\n";
}

// Load from File
void loadFromFile(vector<Student> &studentList)
{
    studentList.clear();

    ifstream file("students.txt");

    if (!file.is_open())
    {
        cout << "No existing data file found.\n";
        return;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        if (token.empty())
            continue;

        try
        {
            int studentId = stoi(token);

            getline(ss, token, ',');
            string studentName = token;

            getline(ss, token, ',');
            double gpa = stod(token);

            getline(ss, token, ',');
            string courses_str = token;

            Student s(studentId, studentName, gpa);

            stringstream css(courses_str);
            string course;

            while (getline(css, course, ';'))
            {
                if (!course.empty())
                    s.addCourse(course);
            }

            studentList.push_back(s);
        }
        catch (...)
        {
            continue;
        }
    }

    file.close();
}