#include<iostream>
#include<vector>
using namespace std;

class student{
protected:
    float marks;

public:
    void setMarks(float m)
    {
        marks = m;
    }
    virtual string computerGrade() = 0;
    ~student(){}
};

class Undergraduate: public student
{
public:
    string computerGrade() override
    {
    if(marks >= 85) return "A";
    else if(marks >= 70) return "B";
    else if(marks >= 50) return "C";
    else return "F";
    }
};

class Postgraduate: public student
{
public:
    string computerGrade() override
    {
    if(marks >= 85) return "A";
    else if(marks >= 75) return "B";
    else if(marks >= 60) return "C";
    else return "F";
    }
};


int main()
{
    vector<student*> students;

    int n;
    cout << "Enter number of studnets: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int type;
        float m;
        cout << "\nEnter student type (1 for UG, 2 for PG): ";
        cin >> type;

        cout << "Enter marks: ";
        cin >> m;

        student* s = nullptr;

        if(type == 1)
        {
            s = new Undergraduate();
        }
        else if(type == 2)
        {
            s = new Postgraduate();
        }
        else
        {
            cout << "Invalid student type. Skipping....\n";
            continue;
        }

        s->setMarks(m);
        students.push_back(s);
    }

    cout << "\nStudent Guides:\n";
    for(size_t i = 0; i < students.size(); ++i)
    {
        cout << "Student" << i + 1 << "Grade: " << students[i]->computerGrade() << endl;
    }

    for(size_t i = 0; i < students.size(); ++i)
    {
        delete students[i];
    }

    cout << endl << "Yug Shah\n24CE114";

    return 0;

}

