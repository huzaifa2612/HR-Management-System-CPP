#include <iostream>
#include <string>
#include <fstream>
#include <limits>     //used in numeric_limits  
#include <cctype>     //used in is_alpha
using namespace std;
/* ===================== BASE ABSTRACT CLASS ===================== */
class Person
{
    public:
        virtual void showDetails() = 0;             //pure virtual
        virtual double calculateSalary() = 0; 
        virtual void setAttendance(int days) = 0;  
        virtual ~Person() {}                       // Virtual destructor
};
/* ===================== PAYROLL (COMPOSITION) ===================== */
class Payroll
{
    protected:                                     //encapsulated members
        double basic_salary, tax, bonus;
        int attendance_days;
    public:
        Payroll(){
         basic_salary=0;
		 tax=0;
		 bonus=0;	
		}
        void SetAttendance(int day)
        {
            attendance_days = day;
        }
        void SetSalary(double bs, double tx, double bo)
        {
            basic_salary = bs;
            tax = tx;
            bonus = bo;
        }
        double CalculateGross()
        {
            return basic_salary + bonus;
        }
        double CalculateNet()
        {
            double ratio = attendance_days / 30.0;
            return (CalculateGross() * ratio) - tax;
        }
        void ShowSlip()
        {
            cout << "Attendance     : " << attendance_days << " days" << endl;
            cout << "Gross          : $" << CalculateGross() << endl;
            cout << "Tax            : $" << tax << endl;
            cout << "Net Salary     : $" << CalculateNet() << endl;
        }
};
/* ===================== EMPLOYEE ===================== */
class Employee : public Person
{
    protected:
        string name, role;
        int id;
    public:
        Employee(string n, string r, int i) : name(n), role(r), id(i) {}

        int getID() const
        { 
            return id;
        }
        void showDetails() override
        {
            cout << "Employee Name  : " << name << endl;
            cout << "Employee Role  : " << role << endl;
            cout << "Employee ID    : " << id << endl;
        }
        virtual double calculateSalary() override = 0;
        virtual void setAttendance(int days) override = 0;
};
/* ===================== MANAGER ===================== */
class Manager : public Employee
{
private:
    Payroll P1;                           //(Manager has-a Payroll)
public:
    Manager(string name, int id) : Employee(name, "Manager", id)
    {
        P1.SetSalary(15000, 100, 200);
    }
    void setAttendance(int days) override
    {
        if (days < 0 || days > 30)
            throw string("Invalid attendance entered");
        P1.SetAttendance(days);
    }
    double calculateSalary() override
    {
        return P1.CalculateNet();
    }
    void showDetails() override
    {
        Employee::showDetails();
        P1.ShowSlip();
    }
};
/* ===================== ENGINEER ===================== */
class Engineer : public Employee
{
private:
    Payroll P1;
public:
    Engineer(string name, int id) : Employee(name, "Engineer", id)
    {
        P1.SetSalary(20000, 250, 250);
    }
    void setAttendance(int days) override
    {
        if (days < 0 || days > 30)
            throw string("Invalid attendance entered");
        P1.SetAttendance(days);
    }
    double calculateSalary() override
    {
        return P1.CalculateNet();
    }
    void showDetails() override
    {
        Employee::showDetails();
        P1.ShowSlip();
    }
};
/* ===================== INTERN ===================== */
class Intern : public Employee
{
private:
    Payroll P1;
public:
    Intern(string name, int id) : Employee(name, "Intern", id)
    {
        P1.SetSalary(5000, 500, 50);
    }
    void setAttendance(int days) override
    {
        if (days < 0 || days > 30)
            throw string("Invalid attendance entered");
        P1.SetAttendance(days);
    }
    double calculateSalary() override
    {
        return P1.CalculateNet();
    }
    void showDetails() override
    {
        Employee::showDetails();
        P1.ShowSlip();
    }
};
/* ===================== HR SYSTEM ===================== */
class HRSystem
{
private:
    Employee* E1[100];
    int count;
public:
    HRSystem() : count(0) {}
    void AddEmployee()
    {
        if (count >= 100)
        {
            cout << "Maximum employee limit reached we cannot add more employees !" << endl<< endl;
            return;
        }
        string name;
        int role, attendance, id;
        cout <<endl<< "Select the category of the employee (1-3):"<<endl;
        cout <<endl<< "1. Manager  " <<endl<<endl<<	
		"2. Engineer  "<<endl<<endl<<
		"3. Intern    "<<endl<<endl;
        cin >> role;
        if (role < 1 || role > 3)
        {
            cout << "Invalid role selected" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        if(role == 1)
        {
           cout << "Enter the Manager's Name : ";
		   cin.ignore(numeric_limits<streamsize>::max(), '\n');
		   getline(cin, name);

            if(name.empty())
            {
                cout << "Error : Name cannot be empty ! " << endl;
            }
            else if(!isalpha(name[0]))
            {
                cout << "Error : Name must start with an alphabetic character ! " << endl;
                do
                {
                    cout << "Please enter a valid name: ";
                    cin >> name;
                }while(name.empty() || !isalpha(name[0]));
            }
        }
        else if(role == 2)
        {
            cout << "Enter the Engineer's Name: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);

            if(name.empty())
            {
                cout << "Error : Name cannot be empty ! " << endl;
                return;
            }
            else if(!isalpha(name[0]))
            {
                cout << "Error : Name must start with an alphabetic character ! " << endl;
                do
                {
                    cout << "Please enter a valid name: ";
                    cin >> name;
                }while(name.empty() || !isalpha(name[0]));
            }
        }
        else if(role == 3)
        {
            cout << "Enter the Intern's Name: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);

            if(name.empty())
            {
                cout << "Error : Name cannot be empty ! " << endl;
                return;
            }
            else if(!isalpha(name[0]))
            {
                cout << "Error : Name must start with an alphabetic character ! " << endl;
                do
                {
                    cout << "Please enter a valid name ! Try again here : ";
                    getline(cin, name);

                }while(name.empty() || !isalpha(name[0]));
            } 
        }
        cout << "Enter the employee's ID (6-digit number): ";
        cin >> id;
        if (cin.fail())
        {
            cout << "Error : ID must be in numbers only." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            do
            {
                cout << "Please enter a valid numeric ID ! Try again here : ";
                cin >> id;
            }while(cin.fail());
        }
        if (id <= 0)
        {
            cout << "Error : ID must be a positive integer ! " << endl;
            do
            {
                cout << "Error : Please enter a valid numeric ID ! Try again here : ";
                cin >> id;
            }while(id <= 0);
        }
        if (id < 100000 || id > 999999)
        {
            cout << "Error : ID must be a 6-digit number only ! " << endl;
            do
            {
                cout << "Error : Please enter a valid numeric ID ! Try again here : ";
                cin >> id;
            }while(id < 100000 || id > 999999);
        }
        cout << "Enter employee's Attendance (0-30 days) : ";
        cin >> attendance;
        if (cin.fail())
        {
            cout << "Error : Attendance must be numeric ! " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            do
            {
                cout << "Error : Please enter a valid numeric attendance ! Try again here : ";
                cin >> attendance;
            } while (cin.fail());
        }
        if (attendance < 0 || attendance > 30)
        {
            cout << "Error : Attendance must be between 0 and 30 only ! " << endl;
            do
            {
                cout << "Error : Please enter a valid numeric attendance ! Try again here : ";
                cin >> attendance;
            } while (attendance < 0 || attendance > 30);
            
        }
        // Clear any leftover input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        try
        {
            if (role == 1)
                E1[count] = new Manager(name, id);
            else if (role == 2)
                E1[count] = new Engineer(name, id);
            else if (role == 3) // Added explicit role check here
                E1[count] = new Intern(name, id);

            E1[count]->setAttendance(attendance);

            // Save to CSV file
            ofstream fout("employees.csv", ios::app);
            if (fout.is_open())
            {
                string roleStr = (role == 1) ? "Manager" : (role == 2) ? "Engineer" : "Intern";
                fout << name << "," << id << "," << roleStr << "," << attendance << "\n";
                fout.close();
                cout << "==================================================================="<<endl<<endl;
                cout << "|          Employee Added & Saved in File Successfully !          |"<<endl<<endl;
                cout << "==================================================================="<<endl<<endl;
            }
            else
            {
                cout << "Warning : Could not save to the file ! " << endl;
            }
            
            count++; // Moved count increment inside try block after object is created
        }
        catch (const string& e)
        {
            cout << "Exception : " << e << endl;
            // Clean up if something failed
            if (E1[count]) 
                delete E1[count];
        }
    } 
    void showAllEmployees()
    {
        ifstream fin("employees.csv");
        if (!fin.is_open())
        {
            cout <<endl<< "Error : No employees  added to the system yet ! " << endl<<endl;
            return;
        }
        string line;
        bool hasData = false;
       cout << "==================================================================="<<endl<<endl;
       cout << "|                      CURRENT EMPLOYEES LIST                     |"<<endl<<endl;
       cout << "==================================================================="<<endl<<endl;
       cout << "|               FORMAT : Name | ID | Role | Attendance            |"<<endl<<endl;
       cout << "==================================================================="<<endl<<endl;
       
        while (getline(fin, line))
        {
            if (!line.empty()) // skip empty lines
            {
            	cout << "==================================================================="<<endl<<endl;
                cout << "|  " <<line <<"\t\t\t\t\t  |"<<endl;
                hasData = true;
            }
        }
        fin.close();

        if (!hasData)
        {
            cout <<endl<<"Error : No employees  added to the system yet ! " << endl<<endl;
        }
    }
    void searchEmployee()
{
    ifstream fin("employees.csv");
    if (!fin.is_open())
    {
        cout <<endl<< "Error : Employee file not found ! "<<endl;
        return;
    }
    int search_id;
    cout <<endl<< "Enter the employee ID to search (Pay Roll Slip) : ";
    cin >> search_id;

    string name, roleStr;
    int id, attendance;
    char comma;
    bool found = false;
    while (fin)
    {
        getline(fin, name, ',');
        fin >> id >> comma;
        getline(fin, roleStr, ',');
        fin >> attendance;
        
        fin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (fin.fail())
            break;
        if (id == search_id)
        {
            Employee* emp = NULL;

            if (roleStr == "Manager")
                emp = new Manager(name, id);
            else if (roleStr == "Engineer")
                emp = new Engineer(name, id);
            else if (roleStr == "Intern")
                emp = new Intern(name, id);

            emp->setAttendance(attendance);

            cout << "==================================================================="<<endl<<endl;
            cout << "|                           PAY ROLL SLIP                         |"<<endl<<endl;
            cout << "==================================================================="<<endl<<endl;
            emp->showDetails();
            cout <<endl<<"==================================================================="<<endl;

            delete emp;
            found = true;
            break;
        }
    }
    fin.close();
    if (!found)
        cout <<endl<<"Error : Employee with ID " << search_id << " not found in system ! "<<endl;
}
    void Menu()
    {
        int choice;
        do
        {
    cout << "==================================================================="<<endl<<endl;
    cout << "|                        What are you looking for ?               |"<<endl<<endl;
    cout << "==================================================================="<<endl<<endl;
    cout << "|                  1. Add Employee                                |"<<endl<<endl;
    cout << "|                  2. Show All Employees                          |"<<endl<<endl;
    cout << "|                  3. Search An Employee For Pay Roll Slip        |"<<endl<<endl;
    cout << "|                  4. Exit                                        |"<<endl<<endl;
    cout << "==================================================================="<<endl<<endl;
    cout << "  For any queries contact UAN-033-234-78 "<<endl;
    cout << "  or you may email us at @hr.infodesk.pk "<<endl;
    cout << "  � 2026 HR.Taha&co. All rights reserved "<<endl<<endl;
    cout << "Enter your choice (1-4): ";
            if (!(cin >> choice))
            {
                cout << "Invalid input ! Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            switch (choice)
            {
            case 1:
                AddEmployee();
                break;
            case 2:
                showAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                cout <<endl<< "Exiting the system ..." << endl;
                break;
            default:
                cout << "Invalid choice entered ! Please try again." << endl;
            }
        } while (choice != 4);

        cout <<endl<< "Thank You for using the HR Management System !"<<endl;
    }
    ~HRSystem()
    {
        for (int i = 0; i < count; i++)
            delete E1[i];
    }
};
/* ===================== MAIN ===================== */
int main()
{
    cout << "==================================================================="<<endl<<endl;
    cout << "|                    WELCOME TO HR MANAGMENT SYSTEM               |"<<endl;
    cout << "|                      GREAT PEOPLE TO WORK WITH !                |"<<endl<<endl;
    cout << "==================================================================="<<endl<<endl;
    HRSystem hr;
    hr.Menu();
    return 0;
}
