# HR & Payroll Management System 🏢💻

A robust, console-based Human Resource and Payroll Management System developed in C++. This was created as a 3rd-semester Object-Oriented Programming (OOP) final project to demonstrate the practical implementation of core OOP concepts alongside file handling and exception management.

## 🚀 Features
* **Add Employees:** Register new Managers, Engineers, or Interns with unique 6-digit IDs.
* **Generate Payroll Slips:** Automatically calculates gross salary, tax deductions, and net salary based on attendance.
* **View All Records:** Displays a formatted list of all current employees.
* **Persistent Storage:** All employee records are securely saved and retrieved from an `employees.csv` file.
* **Input Validation:** Robust error handling for invalid IDs, attendance days, and missing data.

## 🧠 OOP Concepts Implemented
This project heavily relies on the four pillars of OOP and advanced C++ features:
1.  **Abstraction & Interfaces:** Used a pure virtual base class `Person` with abstract methods like `showDetails()` and `calculateSalary()`.
2.  **Inheritance:** `Employee` inherits from `Person`, while `Manager`, `Engineer`, and `Intern` inherit from `Employee`.
3.  **Polymorphism:** Method overriding is used across derived classes to handle specific salary calculations and detail generation.
4.  **Composition:** A `Payroll` class is integrated inside the Employee subclasses (a "Has-A" relationship) to manage salary states.
5.  **Encapsulation:** Protected and private access modifiers safeguard sensitive variables like `basic_salary`, `tax`, and `bonus`.

## 🛠️ How to Run
1. Clone this repository:
   ```bash
   git clone [https://github.com/huzaifa2612/HR-Management-System-CPP.git](https://github.com/huzaifa2612/HR-Management-System-CPP.git)
