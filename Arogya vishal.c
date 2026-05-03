#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
public:
    int empId;
    string name;
    float basicSalary;
    float hra, da, grossSalary;

    void addEmployee() {
        cout << "\nEnter Employee ID: ";
        cin >> empId;

        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;

        calculateSalary();
    }

    void calculateSalary() {
        hra = basicSalary * 0.20; // 20% HRA
        da = basicSalary * 0.10;  // 10% DA
        grossSalary = basicSalary + hra + da;
    }

    void displayEmployee() {
        cout << "\n-----------------------------------";
        cout << "\nEmployee ID      : " << empId;
        cout << "\nEmployee Name    : " << name;
        cout << "\nBasic Salary     : " << basicSalary;
        cout << "\nHRA (20%)        : " << hra;
        cout << "\nDA (10%)         : " << da;
        cout << "\nGross Salary     : " << grossSalary;
        cout << "\n-----------------------------------\n";
    }
};

int main() {
    Employee emp[100];
    int n = 0;
    int choice;

    do {
        cout << "\n===== Employee Salary Management System =====";
        cout << "\n1. Add Employee";
        cout << "\n2. Display Employee Records";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                emp[n].addEmployee();
                n++;
                break;

            case 2:
                if(n == 0) {
                    cout << "\nNo employee records found!\n";
                } else {
                    for(int i = 0; i < n; i++) {
                        emp[i].displayEmployee();
                    }
                }
                break;

            case 3:
                cout << "\nExiting Program...";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while(choice != 3);

    return 0;
}
