/*Write a program for an inventory management system using both procedural and
object-oriented approaches. The system should handle products with attributes:
ID, name, quantity, and price.
Implement these functionalities:
o Add a new product.
o Update the quantity of an existing product.
o Calculate the total value of all products.
Objective: Compare the procedural and object-oriented implementations by
evaluating code reusability and complexity.*/

#include<iostream>
using namespace std;

struct ProductDetails
{
    int id;
    char name[50];
    int quantity;
    float price;
} Products[100];

int AddProduct();
int UpdateQuantity();
void CalculateTotalValue(int a);

int main()
{
    int NumProducts;
    cout << "Enter number of Products: ";
    cin >> NumProducts;

    for(int i = 0; i < NumProducts; i++)
    {
        cout << "Product ID: ";
        cin >> Products[i].id;
        cout << "Product Name: ";
        cin >> Products[i].name;
        cout << "Product Quantity: ";
        cin >> Products[i].quantity;
        cout << "Product Price: ";
        cin >> Products[i].price;
    }

    int choice, num, flag = 0;

    cout << "Your choice: ";
    cin >> choice;

    switch(choice)
    {
    case 1:
        num = AddProduct();

        int NewNumProducts = NumProducts + num;


        for(int i = NumProducts; i < NewNumProducts; i++)
        {
            cout << "Product ID: ";
            cin >> Products[i].id;
            cout << "Product Name: ";
            cin >> Products[i].name;
            cout << "Product Quantity: ";
            cin >> Products[i].quantity;
            cout << "Product Price: ";
            cin >> Products[i].price;
        }

        NumProducts = NewNumProducts;
        break;

    case 2:
        int id_update, update_quantity;
        cout << "Enter Product ID of which you want to update quantity: ";
        cin >> id_update;


        for(int i = 0; i < NumProducts; i++)
        {
            if(id_update == Products[i].id)
            {
                update_quantity = UpdateQuantity();
                Products[i].quantity = update_quantity;
                flag = 0;
                break;
            }
            else {
                flag = 1;
            }
        }

        if(flag == 1)
        {
            cout << "No such ID found\n";
        }
        break;


    case 3:
        CalculateTotalValue(NumProducts);
        break;

    default:
        cout << "Enter a valid number between 1 to 3\n";
    }

    return 0;
}

int AddProduct()
{
    int n;
    cout << "Enter how many new products to be added: ";
    cin >> n;

    return n;
}

int UpdateQuantity()
{
    int quan;
    cout << "Enter updated amount of quantity: ";
    cin >> quan;
    return quan;
}

void CalculateTotalValue(int a)
{
    float total = 0;
    for(int i = 0; i < a; i++)
    {
        total = total + (Products[i].quantity * Products[i].price);
    }

    cout << "Total value of all products = $" << total << endl;
}

