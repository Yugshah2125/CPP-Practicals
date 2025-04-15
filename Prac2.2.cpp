//Class StudentDetails
//data members: StudentRollNo, StudentName, Student marks of 3 subjects: marks1, marks2, marks3
//methods: InputStudentDetails(), CalAvgMarks()

#include<iostream>
using namespace std;

class StudentDetails
{
    int StudentRollNo;
    string StudentName;
    float marks1, marks2, marks3;

public:
    StudentDetails();
    StudentDetails(int, string, float, float, float);

    void CalAvgMarks();
    void DisplayStudentDetails();
};

StudentDetails::StudentDetails()
{
    StudentRollNo = 0;
    StudentName = "Default Name";
    marks1 = marks2 = marks3 = 0;
}


StudentDetails::StudentDetails(int r, string n, float m1, float m2, float m3)
{
    StudentRollNo = r;
    StudentName = n;
    marks1 = m1;
    marks2 = m2;
    marks3 = m3;
}

void StudentDetails::CalAvgMarks()
{
    float avg_marks = (marks1 + marks2 + marks3)/3;
    cout << "Average Marks = " << avg_marks;
}


void StudentDetails::DisplayStudentDetails()
{
    cout << "Student Roll No.: " << StudentRollNo << endl;
    cout << "Student Name: " << StudentName << endl;
    cout << "Marks 1: " << marks1 << endl;
    cout << "Marks 2: " << marks2 << endl;
    cout << "Marks 3: " << marks3 << endl;
    CalAvgMarks();
}


int main()
{
    int n;

    cout << "Enter number of students in your class: ";
    cin >> n;
    StudentDetails student[n];

    for(int i = 0; i < n; i++)
    {
        int roll;
        float m1, m2, m3;
        string name;

        cout << "Enter Details for Student " << i + 1 << ":" << endl;
        cout << "Student " << "Roll Number: ";
        cin >> roll;

        cin.ignore();
        cout << "Student " << "Name: ";
        getline(cin,name);

        cout << "Student " << "Marks 1: ";
        cin >> m1;

        cout << "Student " << "Marks 2: ";
        cin >> m2;

        cout << "Student " << "Marks 3: ";
        cin >> m3;

        student[i] = StudentDetails(roll, name, m1, m2, m3);
    }

    cout << endl << endl;
    cout << "<------- STUDENT DETAILS --------->" << endl;
    for(int i = 0; i < n; i++)
    {
        student[i].DisplayStudentDetails();
        cout << endl << endl;
    }

    cout << endl << "YUG SHAH\n24CE114";
}
