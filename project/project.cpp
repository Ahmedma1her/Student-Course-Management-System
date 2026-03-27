#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// ================= Person =================
class Person
{
protected:
    string name;
public:
    Person(string n) : name(n) {}
};

// ================= Student =================
class Student : public Person
{
private:
    int studentId;
    double gradePointAverage;
    set<string> enrolledCourses;

public:
    Student(int studentId, string studentName, double gpa)
        : Person(studentName), studentId(studentId), gradePointAverage(gpa) {
    }

    int getId() const { return studentId; }
    double getGpa() const { return gradePointAverage; }
    string getName() const { return name; }

    void display() const
    {
        cout << "ID: " << studentId
            << " | Name: " << name
            << " | GPA: " << gradePointAverage << endl;
    }

    void addCourse(const string& course)
    {
        enrolledCourses.insert(course);
    }

    void showCourses() const
    {
        if (enrolledCourses.empty())
        {
            cout << "No courses enrolled\n";
            return;
        }

        cout << "Courses: ";
        for (const auto& c : enrolledCourses)
            cout << c << " ";
        cout << endl;
    }

    set<string> getCourses() const { return enrolledCourses; }
};

// ================= Helper =================
void clearInput()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

// ================= Functions =================

void addStudent(vector<Student>& studentList)
{
    int id;
    string name;
    double gpa;

    cout << "Enter ID: ";
    if (!(cin >> id)) { clearInput(); return; }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter GPA: ";
    if (!(cin >> gpa)) { clearInput(); return; }

    for (auto& s : studentList)
        if (s.getId() == id)
        {
            cout << "ID exists!\n";
            return;
        }

    if (gpa < 0 || gpa > 4)
    {
        cout << "Invalid GPA\n";
        return;
    }

    studentList.push_back(Student(id, name, gpa));
    cout << "Added\n";
}

void removeStudent(vector<Student>& list)
{
    int id;
    cout << "Enter ID: ";
    if (!(cin >> id)) { clearInput(); return; }

    for (auto it = list.begin(); it != list.end(); it++)
    {
        if (it->getId() == id)
        {
            list.erase(it);
            cout << "Removed\n";
            return;
        }
    }
    cout << "Not found\n";
}

void searchStudent(vector<Student>& list)
{
    int id;
    cout << "Enter ID: ";
    if (!(cin >> id)) { clearInput(); return; }

    for (auto& s : list)
        if (s.getId() == id)
        {
            s.display();
            return;
        }

    cout << "Not found\n";
}

void displayAll(vector<Student>& list)
{
    for (auto& s : list)
        s.display();
}

void enrollCourse(vector<Student>& list)
{
    int id;
    string course;

    cout << "Enter ID: ";
    if (!(cin >> id)) { clearInput(); return; }

    cin.ignore();
    cout << "Enter course: ";
    getline(cin, course);

    for (auto& s : list)
        if (s.getId() == id)
        {
            s.addCourse(course);
            cout << "Done\n";
            return;
        }

    cout << "Not found\n";
}

void showCourses(vector<Student>& list)
{
    int id;
    cout << "Enter ID: ";
    if (!(cin >> id)) { clearInput(); return; }

    for (auto& s : list)
        if (s.getId() == id)
        {
            s.showCourses();
            return;
        }

    cout << "Not found\n";
}

void sortStudents(vector<Student>& list)
{
    sort(list.begin(), list.end(),
        [](const Student& a, const Student& b)
        {
            return a.getGpa() > b.getGpa();
        });

    cout << "Sorted\n";

    displayAll(list);
}

void saveToFile(vector<Student>& list)
{
    ofstream file("students.txt");

    for (auto& s : list)
    {
        file << s.getId() << "," << s.getName() << "," << s.getGpa() << ",";
        auto courses = s.getCourses();

        bool first = true;
        for (auto& c : courses)
        {
            if (!first) file << ";";
            file << c;
            first = false;
        }
        file << endl;
    }
}

void loadFromFile(vector<Student>& list)
{
    ifstream file("students.txt");
    if (!file) return;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        int id = stoi(token);

        getline(ss, token, ',');
        string name = token;

        getline(ss, token, ',');
        double gpa = stod(token);

        getline(ss, token, ',');
        string courses = token;

        Student s(id, name, gpa);

        stringstream cs(courses);
        string c;

        while (getline(cs, c, ';'))
            if (!c.empty())
                s.addCourse(c);

        list.push_back(s);
    }
}

// ================= MAIN =================
int main()
{
    vector<Student> list;
    loadFromFile(list);

    int choice;

    do
    {
        cout << "\n 1.Add 2.Remove 3.Search 4.Display \n";
        cout << " 5.Enroll 6.Show Courses 7.Sort 8.Exit \n";

        cin >> choice;

        switch (choice)
        {
        case 1: addStudent(list); break;
        case 2: removeStudent(list); break;
        case 3: searchStudent(list); break;
        case 4: displayAll(list); break;
        case 5: enrollCourse(list); break;
        case 6: showCourses(list); break;
        case 7: sortStudents(list); break;
        }

    } while (choice != 8);

    saveToFile(list);
}