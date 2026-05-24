Project Overview
The Human Resource & Payroll Management System is a comprehensive, console-based C++ application designed to automate employee registration and salary processing. Engineered with a strict adherence to Object-Oriented Programming (OOP) paradigms, the system efficiently manages diverse employee hierarchies, calculates attendance-based net salaries, and generates detailed payroll slips.

Operating entirely through an intuitive Command-Line Interface (CLI), the project bridges the gap between complex business logic and reliable data management. It features persistent local storage, dynamic memory allocation, and robust fault-tolerance mechanisms to ensure seamless execution in a simulated corporate environment.

✨ Core Functionalities & Technical Implementation
1. Advanced Object-Oriented Architecture
Abstraction & Polymorphism: The system is built upon a pure virtual abstract base class (Person), establishing a strict contract for derived classes. Virtual methods like showDetails() and calculateSalary() are polymorphically overridden across different employee tiers (Manager, Engineer, Intern) to execute role-specific logic.

Inheritance (Is-A Relationship): Utilizes a multi-level class hierarchy where the Employee class acts as an intermediary base, inheriting from Person and passing down shared attributes (Name, ID, Role) to specialized subclasses.

2. Component-Based Design (Composition)
Implementation: Instead of inheriting salary characteristics, the system employs Composition (a "Has-A" relationship).

Mechanism: A highly encapsulated Payroll class is integrated into each employee subclass. This modular approach separates identity management from financial calculations, allowing independent calculation of gross salaries, tax deductions, and attendance ratios without polluting the main employee objects.

3. Dynamic Memory Management & Exception Handling
Implementation: Employs pointer arrays (Employee* E1[100]) and heap allocation.

Mechanism: Employee objects are instantiated dynamically at runtime using the new keyword based on user selection. To prevent memory leaks, a custom destructor iteratively deallocates memory. Furthermore, custom try-catch blocks and throw statements are utilized to elegantly intercept and handle domain-specific errors (e.g., invalid attendance days).

4. Persistent Data Storage (File I/O)
Implementation: Integrated with the C++ <fstream> library for reliable data persistence.

Mechanism: Newly onboarded employees are immediately written to an employees.csv file using append mode (ios::app). The system features a custom search algorithm that parses this CSV file line-by-line to retrieve specific employee records via their 6-digit ID and generate their corresponding Payroll Slip.

5. Input Validation & Fault Tolerance
Implementation: Hardened CLI input streams utilizing <limits> and <cctype>.

Mechanism: The application aggressively sanitizes user inputs. It enforces strictly alphabetic names (isalpha), validates 6-digit numeric bounds for IDs, and clears corrupted input buffers (cin.clear(), cin.ignore()) to prevent infinite loops and application crashes from erroneous keystrokes.

🛠️ Technical Stack
Language: C++11 (or higher)

Core Concepts: Abstraction, Inheritance, Polymorphism, Composition, Encapsulation

Libraries: <iostream>, <fstream>, <string>, <limits>, <cctype>

Memory Management: Dynamic Allocation (new / delete), Virtual Destructors

Storage: Flat-file database (.csv)

## 👨‍💻 Developers

**Muhammad Huzaifa** : [LinkedIn](https://www.linkedin.com/in/muhammad-huzaifa-55a666308/)
