# 🎓 Student Course Management System (C++)

A console-based C++ application for managing students and their enrolled courses.  
The project demonstrates Object-Oriented Programming (OOP), STL usage, and file handling in a simple and practical way.

---

## 📌 Features

- Add a new student (ID, Name, GPA)
- Remove a student by ID
- Search for a student
- Display all students
- Enroll students in courses
- Show all courses of a student
- Sort students by GPA
- Save and load data from file

---

## 🛠️ Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL Containers:
  - `vector`
  - `set`
- STL Algorithms:
  - `sort`
  - `find_if`
- File Handling (`fstream`)

---

## 📁 Project Structure

> ⚠️ Current simplified version (single file implementation)

│── project.cpp → Main program (all functionality implemented here)
│── students.txt → Auto-generated data file


---

## ⚙️ How to Run

### Compile
```bash
g++ project.cpp -o app
Run (Windows)
.\app
Run (Linux / Mac)
./app
📊 Notes
Each student has a unique ID
GPA must be between 0.0 and 4.0
Courses are stored using set to avoid duplicates
Data is saved automatically to file
🧠 Concepts Used
Classes & Objects
Encapsulation
Inheritance
STL (vector, set, algorithms)
File handling
👨‍💻 Author

Ahmed Maher

📌 Status

✔ Fully functional console application
✔ All core features implemented
✔ Ready for further improvement (GUI / Database version)
