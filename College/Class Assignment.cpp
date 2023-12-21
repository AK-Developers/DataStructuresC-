//WAP of structure to store the name, account number and balance of customer (5 users) in c++ and store there information 
//Write the function to print the name of all the customer less than $200
//Write a function to add $100 in the balance of all the customer having more than or equal to $1000 and print the increment value of balance

#include <iostream>
#include <string>

using namespace std;

// Define the customer structure
struct Customer {
    string name;
    int accountNumber;
    double balance;
};

// Function to print the names of customers with a balance less than $200
void printCustomersLessThan200(Customer customers[], int numCustomers) {
    cout << "Customers with a balance less than $200:" << endl;
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].balance < 200.0) {
            cout << customers[i].name << endl;
        }
    }
}

// Function to add $100 to the balance of customers with a balance of $1000 or more
void add100ToHighBalanceCustomers(Customer customers[], int numCustomers) {
    cout << "Increment in balance for customers with a balance of $1000 or more:" << endl;
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].balance >= 1000.0) {
            customers[i].balance += 100.0;
            cout << customers[i].name << ": +$100.0" << endl;
        }
    }
}

int main() {
    const int numCustomers = 5;
    Customer customers[numCustomers];

    // Input customer information
    for (int i = 0; i < numCustomers; i++) {
        cout << "Enter customer " << i + 1 << " information:" << endl;
        cout << "Name: ";
        cin >> customers[i].name;
        cout << "Account Number: ";
        cin >> customers[i].accountNumber;
        cout << "Balance: $";
        cin >> customers[i].balance;
    }

    // Print names of customers with a balance less than $200
    printCustomersLessThan200(customers, numCustomers);

    // Add $100 to the balance of customers with a balance of $1000 or more
    add100ToHighBalanceCustomers(customers, numCustomers);

    return 0;
}
