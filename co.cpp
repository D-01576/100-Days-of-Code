#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(const std::string& accNumber, const std::string& accHolder)
        : accountNumber(accNumber), accountHolderName(accHolder), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        std::cout << "Amount " << amount << " deposited successfully.\n";
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Amount " << amount << " withdrawn successfully.\n";
        } else {
            std::cout << "Insufficient balance.\n";
        }
    }

    void checkBalance() {
        std::cout << "Account Holder: " << accountHolderName << "\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Balance: " << balance << "\n";
    }
};

int main() {
    std::string accountNumber, accountHolderName;
    double initialDeposit;
    std::cout << "Enter the account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter the account holder name: ";
    std::cin.ignore(); // Ignore the newline character in the input buffer
    std::getline(std::cin, accountHolderName);
    std::cout << "Enter the initial deposit amount: ";
    std::cin >> initialDeposit;

    BankAccount account(accountNumber, accountHolderName);
    account.deposit(initialDeposit);

    int choice;
    double amount;
    while (true) {
        std::cout << "\nBank Account Menu:\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the deposit amount: ";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Enter the withdrawal amount: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                std::cout << "Thank you for using our banking system.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

