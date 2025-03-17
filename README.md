# Student Management System in C++

## Contents
- Overview
- Features
- Class Structure
- Installation & Usage
- Example Execution
- Build System (CMake)
- Input File Format
- Implementation Details
- License

## Overview
This project implements a **Student Management System** in C++ using **Object-Oriented Programming (OOP)** principles. It models students, professors, courses, and exams while ensuring encapsulation, inheritance, inheritance, and exception handling.

## Features
- **Abstract base class** for students.
- **Multiple student types** (First-year and Second-year).
- **Professor management** for assigned courses.
- **Course handling** with students and exams.
- **Exam scheduling** with customizable time and number of questions.
- **Custom exception handling** for robustness.
- **Dynamic memory allocation** following Rule of Five principles.
- **Interactive menu-based system** for managing students and professors.

## Class Structure
### 1. `Ipersoana` (Interface for People)
- Abstract class defining a method for retrieving a full name.

### 2. `AbstractStudent` (Base Student Class)
- Defines common student attributes: `Nume`, `Prenume`, and `nota`.
- Implements virtual functions for displaying details and handling grades.

### 3. `StudentAn1` (First-Year Student)
- Inherits from `AbstractStudent`.
- Overloads operators for grade modifications.

### 4. `StudentAn2` (Second-Year Student)
- Similar to `StudentAn1` but designated for second-year students.

### 5. `Profesor` (Professor)
- Contains `Nume`, `Prenume`, and `email`.
- Implements methods for retrieving professor details.

### 6. `Examen` (Exam)
- Manages exam details such as date, duration, and number of questions.

### 7. `MaterieAn1` (First-Year Course)
- Manages students, assigned professors, and exam details.

### 8. `Exception` (Custom Exception Handling)
- Extends `std::exception` to provide specialized error handling.

## Installation & Usage
### Prerequisites
- C++ Compiler (G++ or Clang recommended)

### Compilation
To compile the project manually, use:
```bash
g++ -o student_management *.cpp
./student_management
```

## Example Execution
### Adding a Student
```cpp
StudentAn1 student("John", "Doe", 8.5);
std::cout << student;
```

### Scheduling an Exam
```cpp
Examen exam(10, 6, 2025, 1200, 90, 5);
std::cout << exam;
```

## Build System (CMake)
This project includes a **CMake build system** for easier compilation.

### Building with CMake
1. Navigate to the project directory:
   ```bash
   cd path/to/project
   ```
2. Create a build directory:
   ```bash
   mkdir build && cd build
   ```
3. Run CMake configuration:
   ```bash
   cmake ..
   ```
4. Compile the project:
   ```bash
   make
   ```
5. Run the compiled executable:
   ```bash
   ./Proiect1
   ```

## Input File Format
The program reads data from `exemplu.txt`. Below is an example of how input data should be structured:

### File Content:
```
1
y
POO
1
2
Paun
Vrabie
paun.vrabie@fmi.unibuc.ro
14 6 2024 800 120 4
29 6 2024 1000 120 8
2
Studentul Intai 4
Studentul Doi 8
1
7
n
```

### Explanation:
- `1` → Menu selection
- `y` → Load existing data (y/n)
- `POO` → Subject name
- `1` → Semester
- `2` → Number of professors
- `Paun`, `Vrabie` → Professor names
- `paun.vrabie@fmi.unibuc.ro` → Email
- `14 6 2024 800 120 4` → Exam details (day, month, year, hour, duration, questions)
- `29 6 2024 1000 120 8` → Retake exam details
- `2` → Number of students
- `Studentul Intai 4`, `Studentul Doi 8` → Students (name, surname, grade)
- `1` → Select student index
- `7` → Menu option
- `n` → Exit

## Implementation Details
- **Encapsulation & Polymorphism**: All attributes are private or protected, with appropriate getters and setters.
- **Dynamic Memory Management**: Utilizes Rule of Five (`constructor`, `copy constructor`, `move constructor`, `destructor`, `operator=`).
- **Exception Handling**: Implements custom exception handling (`Exception.h`).
- **Operator Overloading**: Supports custom output/input operators (`<<`, `>>`).
- **Modular Codebase**: Header and source files are structured for scalability.

## License
This project is free to use and modify for educational purposes.

