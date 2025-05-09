#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;
    vector<pair<string, double>> transactions;
public:
    BankAccount(string accNo, double bal) : accountNumber(accNo), balance(bal) {}
    virtual ~BankAccount() {}
    virtual void deposit(double amount) {
        balance += amount;
        transactions.push_back({"Deposit", amount});
    }
    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactions.push_back({"Withdraw", amount});
        }
    }
    void undoLastTransaction() {
        if (!transactions.empty()) {
            auto last = transactions.back();
            if (last.first == "Deposit") balance -= last.second;
            else if (last.first == "Withdraw") balance += last.second;
            else if (last.first == "Interest") balance -= last.second;
            transactions.pop_back();
        }
    }
    virtual void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(string accNo, double bal, double rate) : BankAccount(accNo, bal), interestRate(rate) {}
    ~SavingsAccount() {}
    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        transactions.push_back({"Interest", interest});
    }
    void display() override {
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CurrentAccount : public BankAccount {
    double overdraftLimit;
public:
    CurrentAccount(string accNo, double bal, double limit) : BankAccount(accNo, bal), overdraftLimit(limit) {}
    ~CurrentAccount() {}
    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            transactions.push_back({"Withdraw", amount});
        }
    }
    void display() override {
        BankAccount::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    BankAccount* account = nullptr;
    int choice;
    string accNo;
    double bal, rate, limit, amount;

    cout << "Choose account type:\n1. Savings Account\n2. Current Account\nChoice: ";
    cin >> choice;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Initial Balance: ";
    cin >> bal;

    if (choice == 1) {
        cout << "Enter Interest Rate (%): ";
        cin >> rate;
        account = new SavingsAccount(accNo, bal, rate);
    } else if (choice == 2) {
        cout << "Enter Overdraft Limit: ";
        cin >> limit;
        account = new CurrentAccount(accNo, bal, limit);
    } else {
        cout << "Invalid Choice";
        return 0;
    }

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Undo Last Transaction\n4. Add Interest (Savings Only)\n5. Display Account\n6. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account->deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
                break;
            case 3:
                account->undoLastTransaction();
                break;
            case 4:
                if (SavingsAccount* sa = dynamic_cast<SavingsAccount*>(account)) {
                    sa->addInterest();
                } else {
                    cout << "Not a Savings Account\n";
                }
                break;
            case 5:
                account->display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);

    delete account;
    cout << endl << "Yug Shah\n24CE114";
    return 0;
}
