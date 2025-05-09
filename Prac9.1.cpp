#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

double getValidatedInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a numerical value.\n";
        } else {
            return value;
        }
    }
}

int main() {
    try {
        double loanAmount = getValidatedInput("Enter the total loan amount: ");
        double annualIncome = getValidatedInput("Enter your annual income: ");

        if (annualIncome == 0) {
            throw runtime_error("Annual income cannot be zero. Division by zero is not allowed.");
        }

        double ratio = loanAmount / annualIncome;
        cout << "Loan-to-Income Ratio: " << ratio << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << endl << "Yug Shah\n24CE114";

    return 0;
}

