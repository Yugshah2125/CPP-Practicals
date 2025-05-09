
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    vector<int> transactionIDs = {101, 203, 101, 405, 203, 506, 405};
    cout << "Transaction IDs: ";
    for(const int& a : transactionIDs)
    {
        cout << a << " ";
    }

    cout << endl;

    set<int> uniqueTransactionIDs(transactionIDs.begin(), transactionIDs.end());

    cout << "Unique Transaction IDs (sorted): ";
    for (const int& id : uniqueTransactionIDs)
    {
        cout << id << " ";
    }
    cout << endl;

    cout << endl << "Yug Shah\n24CE114";

    return 0;
}
