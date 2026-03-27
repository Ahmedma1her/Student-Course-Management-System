# Student Course Management System (C++)

## 📌 Overview

This is a console-based C++ application that allows users to manage students and their enrolled courses.
The system demonstrates Object-Oriented Programming (OOP), Standard Template Library (STL), and file handling concepts.

---

## 🎯 Features

* Add a new student (ID, Name, GPA)
* Remove a student by ID
* Search for a student
* Display all students
* Enroll a student in a course
* Show all courses of a student
* Sort students by GPA
* Save and load data from file

---

## 🛠️ Technologies Used

* C++
* OOP (Classes, Inheritance, Encapsulation)
* STL Containers:

  * `vector`
  * `set`
* STL Algorithms:

  * `sort()`
  * `find_if()`
* File Handling (`fstream`)

---

## 🧱 Project Structure

```
/project-folder
│── main.cpp
│── student.h
│── student.cpp
│── person.h
│── students.txt (auto-generated)
```

---

## 📚 Class Design

### Person (Base Class)

* Attribute:

  * `name : string`

### Student (Derived Class)

* Attributes:

  * `studentId : int`
  * `gradePointAverage : double`
  * `enrolledCourses : set<string>`
* Methods:

  * `getId()`
  * `getGpa()`
  * `getName()`
  * `display()`
  * `addCourse()`
  * `showCourses()`

---

## ⚙️ How to Run

### using g++

```bash
g++ main.cpp student.cpp -o app
./app
```

### using Code::Blocks / Visual Studio

* Import project files
* Build & Run

---

## 📂 Data Storage

* Data is saved in a file called:

```
students.txt
```

* The file is automatically created after exiting the program.

---

## ⚠️ Constraints

* Each student must have a unique ID
* GPA must be between 0.0 and 4.0
* Courses cannot be duplicated (using `set`)
* Program handles invalid input

---

## ⭐ Bonus Features Implemented

* File Save / Load system
* Use of `set` to prevent duplicate courses
* Sorting using STL
* Searching using STL

---

## 🧠 Concepts Applied

* Object-Oriented Programming
* Inheritance (`Student` inherits from `Person`)
* Encapsulation
* STL Containers & Algorithms
* File Handling

---

## 📌 Example

```
Choice: 1
Enter ID: 1001
Enter Name: Ali
Enter GPA: 3.5
Student added successfully
```

---

## 👨‍💻 Author

Ahmed Maher

---

## ✅ Status

✔ Completed and fully functional
✔ Meets all assignment requirements
✔ Includes bonus features

---
