
#include<iostream>
#include<math.h>
using namespace std;

class Loan_Details
{
    int LoanID, Time;





    string Name;
    float Principle, IRate, EMI, Amount, Interest;

    void CalculateDetails()
    {
        float temp = (float)pow(1+IRate, Time);

        EMI = Principle*IRate*temp/(temp - 1);
        Amount = EMI*Time;
        Interest = Amount - Principle;
    }

    public:

    void AddData(string N = "Name", int ID = 0, float P = 0, float IR = 0, int T = 0)
    {
        Name = N;
        LoanID = ID;
        Principle = P;
        IRate = IR/100;
        Time = T;

        CalculateDetails();
    }

    void LoanSummary()
    {
        cout<<"\n\nLoan ID : "<<LoanID;
        cout<<"\nName : "<<Name;
        cout<<"\nPrinciple : "<<Principle;
        cout<<"\nInterest Rate (%) : "<<IRate*100;
        cout<<"\nTime ( IN Months) : "<<Time;
        cout<<"\nEMI : "<<EMI;
        cout<<"\nTotal Interest : "<<Interest;
        cout<<"\nTotal Amount to Pay : "<<Amount;
    }
};

int main()
{
    Loan_Details Loan[20];

    int LoanID, Time, choice=0, Count=0;
    string Name;
    float Principle, IRate;

    do
    {
        cout<<"\n WELCOME TO LOAN MANAGEMENT SYSTEM :\nChoices:";
        cout<<"\n1. Add New Loan Details\n2. All Loans Details  Summary\n0. Exit System\nEnter choice: ";
        cin>>choice;

        if(choice==1){
            cout<<"\nEnter details for Loan "<<Count+1;
            cout<<"\nLoan ID : ";
            cin>>LoanID;
            cout<<"Name : ";
            cin.ignore();
            getline(cin, Name);
            cout<<"Principle : ";
            cin>>Principle;
            cout<<"Interest Rate (%) : ";
            cin>>IRate;
            cout<<"Time (Months) : ";
            cin>>Time;
            Loan[Count].AddData(Name, LoanID, Principle, IRate, Time);
            cout<<"\nNew Loan Added!!";
            cout<<"\n\nLoan Details are:";
            Loan[Count].LoanSummary();
            Count++;
        }
        else if(choice==2){
            if(Count<1)
            cout<<"\nNO Loans in System!";
            else
            {
                for(int i=0; i<Count;i++)
                {
                    cout<<"\nLoan "<<i+1<<" Details:";
                    Loan[i].LoanSummary();
                }
            }
        }
        else
        break;
    }while(choice==1||choice==2);
    cout<<"\nYUG SHAH\n24CE114";

    return 0;
}

