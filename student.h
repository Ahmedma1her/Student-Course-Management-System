#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "person.h"

using namespace std;

// This class represents a student, building on the Person class.
// It includes a unique ID, GPA, and a list of courses they're enrolled in.
class Student : public Person
{
private:
    int studentId;
    double gradePointAverage;
    set<string> enrolledCourses;

public:
    Student(int studentId, string studentName, double gpa);
    int getId() const;
    double getGpa() const;
    string getName() const;
    void display() const;
    void addCourse(const string &course);
    void showCourses() const;
    set<string> getCourses() const;
};

// ================= Helper Function =================
void clearInput();

// ================= Functions =================
void addStudent(vector<Student> &studentList);
void removeStudent(vector<Student> &studentList);
void searchStudent(vector<Student> &studentList);
void displayAll(vector<Student> &studentList);
void enrollCourse(vector<Student> &studentList);
void showCourses(vector<Student> &studentList);
void sortStudents(vector<Student> &studentList);
void saveToFile(vector<Student> &studentList);
void loadFromFile(vector<Student> &studentList);

#endif