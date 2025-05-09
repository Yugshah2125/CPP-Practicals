#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

ostream& alignColumn(ostream& os) {
    return os << left << setw(20);
}

int main() {
    ifstream inputFile("student_data.txt");

    if (!inputFile) {
        cerr << "Error: Unable to open the file!" << endl;
        return 1;
    }

    cout << alignColumn << "Name"
         << alignColumn << "Marks"
         << alignColumn << "Grade" << endl;
    cout << string(60, '-') << endl;

    string name, grade;
    int marks;

    while (inputFile >> ws && getline(inputFile, name, ',') && inputFile >> marks >> ws && getline(inputFile, grade)) {
        cout << alignColumn << name
             << alignColumn << marks
             << alignColumn << grade << endl;
    }

    inputFile.close();
    cout << endl << "Yug Shah\n24CE114";

    return 0;
}

