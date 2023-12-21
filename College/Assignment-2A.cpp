//WAP to store and display the name, age and salary of employees using structure

#include <iostream>
#include <string>

using namespace std;

// Define the Employee structure
struct Employee {
    string name;
    int age;
    double salary;
};

int main() {
    const int numEmployees = 5;
    Employee employees[numEmployees];

    // Input employee information
    for (int i = 0; i < numEmployees; i++) {
        cout << "Enter information for Employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Age: ";
        cin >> employees[i].age;
        cout << "Salary: $";
        cin >> employees[i].salary;
    }

    // Display employee information
    cout << "\nEmployee Information:\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < numEmployees; i++) {
        cout << "Employee " << i + 1 << ":\n";
        cout << "Name: " << employees[i].name << endl;
        cout << "Age: " << employees[i].age << " years" << endl;
        cout << "Salary: $" << employees[i].salary << endl;
        cout << "---------------------------------\n";
    }

    return 0;
}
