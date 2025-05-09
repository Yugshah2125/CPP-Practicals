#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base constructor\n";
    }

    virtual ~Base()
    {
        cout << "Base destructor\n";
    }
};

class Derived : public Base
{
private:
    int* data;

public:
    Derived()
    {
        data = new int[100];
        cout << "Derived constructor\n";
    }

    ~Derived()
    {
        delete[] data;
        cout << "Derived destructor\n";
    }
};

int main()
{
    Base* obj = new Derived();

    delete obj;

    cout << endl << "Yug Shah\n24CE114";

    return 0;
}

