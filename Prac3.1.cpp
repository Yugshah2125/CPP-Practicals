#include<iostream>
#include<vector>
using namespace std;

class employee{
    string emp;
    float salary;
    float bonus;

public:
    employee(string name, int sal, int bon)
    {
        emp = name;
        salary = sal;
        bonus = bon;
    }

    void display()
    {
        cout << "Employee's Name: " << emp << endl;
        cout << "Employee's Basic Salary: " << salary << endl;
        cout << "Employee's Bonus: " << bonus << endl;
        cout << "Employee's Total Salary: " << totalSalary() << endl;
    }

    float totalSalary()
    {
        return salary + bonus;
    }
};

int main()
{
    vector<employee>emp;

    string name;
    float sal;
    float bon;

    int n;

    cout << "Enter number of entries you wan to make: ";
    cin >> n;
    cin.ignore();

    cout << endl << endl << "=========Enter Employee Details=========" << endl << endl;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter Name: ";
        getline(cin, name);


        cout << "Enter Basic Salary: ";
        cin >> sal;

        cout << "Enter Bonus: ";
        cin >> bon;

        emp.push_back(employee(name, sal, bon));
        cin.ignore();

        cout << endl;
    }

    cout << endl << endl << "=========Employee Details=========" << endl << endl;

    for(auto&i:emp)
    {
        i.display();
        cout << endl;
    }

}
