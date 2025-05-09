#include<iostream>
#include<vector>
using namespace std;
#define PI 3.14

//Shape Class -> Base Class to store and manage radius of circle
class Shape{
    float radius;
public:
    void getRadius()
    {
        cout << "Enter Radius of Circle: ";
        cin >> radius;
    }
    float passRadius()
    {
        return radius;
    }
};

//Area Class -> Specialized/Derived Class used for calculating area of circle as per radius
class Area : public Shape{
public:
    void CalculateArea()
    {
        float rad = passRadius();
        float Area = PI * rad * rad;
        cout << "Area of the circle(" << rad << " radius): " << Area << endl;
    }
};

int main()
{
    int n;
    cout << "How many circles: ";
    cin >> n;


/*  Using Normal Object Array

    Area o1[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Circle " << i+1 << ":" << endl;
        o1[i].getRadius();
        o1[i].CalculateArea();
    }
*/

    //Using Vectors
    vector<Area> circles(n); // Vector to store Area objects

    for(int i = 0; i < n; i++)
    {
        cout << "Circle " << i + 1 << ":" << endl;
        circles[i].getRadius();
        circles[i].CalculateArea();

    }

    cout << endl << "Yug Shah\n24CE114";

    return 0;
}
