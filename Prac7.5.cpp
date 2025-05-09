#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

ostream& currency(ostream& os) {
    return os << "RS.";
}

int main() {
    vector<pair<string, double>> students = {
        {"Alice", 89.5},
        {"Bob", 76.25},
        {"Charlie", 92.0},
        {"Diana", 84.75}
    };

    vector<double> tuitionFees = {50000.0, 45000.5, 52000.75, 48000.25};

    cout << left << setw(15) << "Name"
         << right << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    for (size_t i = 0; i < students.size(); ++i) {
        cout << left << setw(15) << students[i].first
             << right << setw(10) << fixed << setprecision(2) << students[i].second
             << setw(10) << currency << fixed << setprecision(2) << tuitionFees[i] << endl;
    }

    cout << endl << "Yug Shah\n24CE114";

    return 0;
}
