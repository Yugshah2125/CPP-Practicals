
#include <iostream>
using namespace std;

class inventory {
    int pid, quantity;
    float rate;
    string name;

public:
    void get_data(int id, int quant, float price, string name1) {
        pid = id;
        quantity = quant;
        rate = price;
        name = name1;
    }

    int search_id(int id) {
        if (pid == id) {
            return 1;
        }
        return 0;
    }

    void increase_stocks(int quant) {
        quantity += quant;
        cout << "Updation successful.\n";
    }

    int decrease_stocks(int quant) {
        if (quantity >= quant) {
            quantity -= quant;
            cout << "Amount to be paid: " << rate * quant << "\n";
            return 1;
        } else {
            return 0;
        }
    }

    void return_total(int quant) {
        int totalbill = rate * quant;
        cout << "Total bill: " << totalbill << "\n";
    }

    void show_inventory() {
        cout << "\nName: " << name;
        cout << "\nPID: " << pid;
        cout << "\nQuantity: " << quantity;
        cout << "\n----------------------------------";
    }
};

int main() {
    inventory r[30];
    int id, quant, counter = 0, choice1, choice2;
    float price;
    string name1;

    // Loop to add items
    while (true) {
        cout << "\nEnter the id of item " << counter + 1 << " :";
        cin >> id;
        cout << "\nEnter the quantity of item " << counter + 1 << " :";
        cin >> quant;
        cout << "\nEnter the price of item " << counter + 1 << " :";
        cin >> price;
        cout << "\nEnter the name of item " << counter + 1 << " :";
        cin >> name1;

        r[counter].get_data(id, quant, price, name1);
        counter++;

        cout << "\nEnter 1 to add more items or 0 to proceed: ";
        cin >> choice1;
        if (choice1 == 0)
            {break;}
    }

    while (true) {
        cout << "\nEnter 1 to increase the stocks :\nEnter 2 to purchase the items :\nEnter 3 to show inventory :\nEnter 4 to exit :";
        cin >> choice2;

        switch (choice2) {
        case 1:
            {
                cout << "\nEnter the id of item whose quantity you want to increase: ";
                cin >> id;
                cout << "\nEnter the quantity to increase: ";
                cin >> quant;
                bool found = false;
                for (int i = 0; i < counter; i++) {
                    if (r[i].search_id(id) == 1) {
                        r[i].increase_stocks(quant);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Sorry, ID not found.\n";
                }
                break;
            }
        case 2:
            {
                cout << "\nEnter the id of item you want to purchase: ";
                cin >> id;
                cout << "\nEnter the quantity to purchase: ";
                cin >> quant;
                bool found = false;
                for (int i = 0; i < counter; i++) {
                    if (r[i].search_id(id) == 1) {
                        if (r[i].decrease_stocks(quant) == 1) {
                            r[i].return_total(quant);
                        } else {
                            cout << "\nSorry, insufficient stock.\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Sorry, ID not found.\n";
                }
                break;
            }
        case 3:
            {
                for (int i = 0; i < counter; i++) {
                    r[i].show_inventory();
                }
                break;
            }
        case 4:
            {
                cout << "\nThank you. Visit again.\n";
                cout<< endl << "YUG SHAH\n24CE114";
                return 0;
            }
        default:
            {
                cout << "\nInvalid choice. Try again.\n";
                break;
            }
        }
    }
    cout<< endl << "YUG SHAH \n24CE114";
    return 0;
}
