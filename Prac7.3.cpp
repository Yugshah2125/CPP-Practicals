#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addItem() {
    ofstream file("inventory.txt", ios::app);
    if (!file) {
        cerr << "Error! Cannot open file." << endl;
        return;
    }

    string f_name;
    int quantity;
    float price;

    cout << "Enter Item Name: ";
    cin >> f_name;
    cout << "Enter Quantity: ";
    cin >> quantity;
    cout << "Enter Price: ";
    cin >> price;

    file << f_name << " " << quantity << " " << price << endl;
    file.close();

    cout << "Item added successfully.\n";
}

void viewInventory() {
    ifstream file("inventory.txt");
    if (!file) {
        cerr << "Error! Cannot open file." << endl;
        return;
    }

    string f_name;
    int quantity;
    float price;

    cout << "\n--- Inventory List ---\n";
    while (file >> f_name >> quantity >> price) {
        cout << "Item: " << f_name
             << ", Quantity: " << quantity
             << ", Price: $" << price << endl;
    }

    file.close();
}

void searchItem() {
    ifstream file("inventory.txt");
    if (!file) {
        cerr << "Error! Cannot open file." << endl;
        return;
    }

    string target;
    cout << "Enter item name to search: ";
    cin >> target;

    string f_name;
    int quantity;
    float price;
    bool found = false;

    while (file >> f_name >> quantity >> price) {
        if (f_name == target) {
            cout << "\nItem Found:\n";
            cout << "Name: " << f_name << "\nQuantity: " << quantity << "\nPrice: $" << price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item not found in inventory.\n";
    }

    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n--- Inventory Management ---\n";
        cout << "1. Add Item\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewInventory(); break;
            case 3: searchItem(); break;
            case 4: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    cout << endl << "Yug Shah\n24CE114";

    return 0;
}
