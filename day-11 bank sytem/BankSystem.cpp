#include <iostream>
#include <fstream>
#include <string>

#define MAX_CUSTOMERS 100

using namespace std;

struct Customer
{
    int accountNumber;
    string name;
    double balance;
};

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void createAccount()
{
    if (customerCount >= MAX_CUSTOMERS)
    {
        cout << "Maximum number of customers reached." << endl;
        return;
    }

    Customer newCustomer;
    int i;

    cout << "Enter account number: ";
    cin >> newCustomer.accountNumber;

    for (i = 0; i < customerCount; i++)
    {
        if (customers[i].accountNumber == newCustomer.accountNumber)
        {
            cout << "Account number already exists. Please enter a different account number." << endl;
            return;
        }
    }

    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, newCustomer.name);

    cout << "Enter opening balance: ";
    cin >> newCustomer.balance;

    customers[customerCount] = newCustomer;
    customerCount++;
    cout << "Account created successfully." << endl;
}

void displayAccountDetails()
{
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;

    int i;
    for (i = 0; i < customerCount; i++)
    {
        if (customers[i].accountNumber == accountNumber)
        {
            cout << "Account Number: " << customers[i].accountNumber << endl;
            cout << "Customer Name: " << customers[i].name << endl;
            cout << "Balance: " << customers[i].balance << endl;
            return;
        }
    }

    cout << "Account not found." << endl;
}

void deposit()
{
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;

    int i;
    for (i = 0; i < customerCount; i++)
    {
        if (customers[i].accountNumber == accountNumber)
        {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            customers[i].balance += amount;
            cout << "Deposit successful. New balance: " << customers[i].balance << endl;
            return;
        }
    }

    cout << "Account not found." << endl;
}

void withdraw()
{
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;

    int i;
    for (i = 0; i < customerCount; i++)
    {
        if (customers[i].accountNumber == accountNumber)
        {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (customers[i].balance >= amount)
            {
                customers[i].balance -= amount;
                cout << "Withdrawal successful. New balance: " << customers[i].balance << endl;
            }
            else
            {
                cout << "Insufficient balance." << endl;
            }
            return;
        }
    }

    cout << "Account not found." << endl;
}

void saveDataToFile()
{
    ofstream file("customer_data.txt");
    if (!file.is_open())
    {
        cout << "Error opening file for writing." << endl;
        return;
    }

    file << customerCount << endl;
    int i;
    for (i = 0; i < customerCount; i++)
    {
        file << customers[i].accountNumber << "," << customers[i].name << "," << customers[i].balance << endl;
    }

    file.close();
    cout << "Data saved to file." << endl;
}

void transfer()
{
    int firstnumber, secondnumber;
    double amount;
    ;
    cout << "Enter account from: ";
    cin >> firstnumber;
    cout << "\nEnter account to: ";
    cin >> secondnumber;
    cout << "Enter transfer amount: ";
    cin >> amount;
    int i;
    for (i = 0; i < customerCount; i++)
    {
        if (customers[i].accountNumber == firstnumber)
        {
            customers[i].balance -= amount;
            cout << "Deposit successful. New balance: " << customers[i].balance << endl;
            return;
        }
        else if (customers[i].accountNumber == secondnumber)
        {
            customers[i].balance += amount;
        }
    }

    cout << "Account not found." << endl;
}

void loadDataFromFile()
{
    ifstream file("customer_data.txt");
    if (!file.is_open())
    {
        cout << "Error opening file for reading." << endl;
        return;
    }

    file >> customerCount;
    file.ignore();
    int i;
    for (i = 0; i < customerCount; i++)
    {
        getline(file, customers[i].name, ',');
        file >> customers[i].accountNumber;
        file.ignore();
        file >> customers[i].balance;
        file.ignore();
    }

    file.close();
    cout << "Data loaded from file." << endl;
}

int main()
{
    int choice;

    loadDataFromFile();

    do
    {
        cout << "1. Create Account" << endl;
        cout << "2. Display Account Details" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. transfer" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            displayAccountDetails();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transfer();
            break;
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        saveDataToFile();
        cout << endl;
    } while (choice != 0);

    saveDataToFile();

    return 0;
}
