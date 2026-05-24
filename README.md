# 🏢 HR & Payroll Management System

![C++](https://img.shields.io/badge/C++-11%2B-blue.svg)
![Build](https://img.shields.io/badge/Build-Passing-success.svg)
![Contributions](https://img.shields.io/badge/Contributions-Welcome-brightgreen.svg)

> A robust, console-based enterprise solution developed in C++ to automate human resource tracking, attendance management, and payroll calculations.

## 📖 Overview
This project is a fully functional HR Management System that strictly leverages core **Object-Oriented Programming (OOP)** principles. It is designed to seamlessly manage different employee tiers, calculate attendance-based salaries, and maintain data integrity through persistent local file storage. 

## ✨ Key Features
* **Role-Based Onboarding:** Register `Managers`, `Engineers`, and `Interns` with unique, auto-validated 6-digit IDs.
* **Dynamic Payroll Engine:** Automatically computes gross salary, tax deductions, and net pay based on a standard 30-day attendance ratio.
* **Persistent Storage:** Securely reads, writes, and searches all employee records using an `employees.csv` flat-file database.
* **Robust Validation:** Hardened command-line interface that prevents runtime crashes through aggressive input sanitization and exception handling.

## 🧠 System Architecture
The codebase is engineered for maximum modularity and scalability:
* **Abstraction & Polymorphism:** A pure virtual `Person` base class dictates the operational structure (e.g., `calculateSalary()`) for all derived employee types.
* **Component-Based Composition (Has-A):** A standalone `Payroll` module is integrated into employee subclasses, cleanly separating personal identity logic from complex financial mathematics.
* **Dynamic Memory Management:** Utilizes heap allocation via pointer arrays and virtual destructors to ensure optimal performance and prevent memory leaks.

## 🚀 Getting Started

### Prerequisites
* A standard C++ compiler (e.g., GCC, MinGW)

 ## 👨‍💻 Developers

**Muhammad Huzaifa** : [LinkedIn](https://www.linkedin.com/in/muhammad-huzaifa-55a666308/)


### Installation & Execution
```bash
# 1. Clone the repository
git clone [https://github.com/huzaifa2612/HR-Management-System-CPP.git](https://github.com/huzaifa2612/HR-Management-System-CPP.git)

# 2. Navigate to the project directory
cd HR-Management-System-CPP

# 3. Compile the source code
g++ main.cpp -o hr_system

# 4. Run the application
./hr_system
