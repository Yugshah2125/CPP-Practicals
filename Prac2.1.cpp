# include <iostream>
using namespace std;
class rectangle
{
    float length,breadth;

public:
    void setdimension(float l, float b  )
    {
        length=l;
        breadth=b;
    }
    float area(float length, float breadth)
    {
        return length*breadth;
    }
    float perimeter(float length, float breadth)
    {
        return 2*(length+breadth);
    }
    void update(float l, float b)
    {
        length=l;
        breadth=b;
    }
};
int main()
{
    rectangle r[25];
    float l,b;
    int n,choice,h;
    cout<<"Enter how many rectangle objects you want to create :";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"\nSet dimension of rectangle "<<i+1;
        cout<<"\nEnter the length :";
        cin>>l;
        cout<<endl;
        cout<<"Enter the breadth :";
        cin>>b;
        r[i].setdimension(l,b);
        cout<<"\n Area :"<<r[i].area(l,b);
        cout<<"\n Perimeter :"<<r[i].perimeter(l,b);
    }

    int exit = 1;

    while(exit)
    {
        cout<<"\nEnter 1 to update the dimensions or 0 to exit : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"\nEnter the no. of that rectangle whose dimensions you want to change : ";
            cin>>h;
            cout<<"\nEnter the new length : ";
            cin>>l;
            cout<<"\nEnter the new breadth : ";
            cin>>b;
            r[h-1].update(l,b);
            cout<<"\n new Area :"<<r[h-1].area(l,b);
            cout<<"\n new Perimeter :"<<r[h-1].perimeter(l,b);
            break;

        case 0:
            cout<<"\nThankyou Visit Again !";
            exit = 0;
            break;
        }
    }




    cout<<"\nYUG SHAH\n24CE114 ";
    return 0;

}
