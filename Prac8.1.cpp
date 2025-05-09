#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseUsingStdReverse(vector<int>& sequence) {
    reverse(sequence.begin(), sequence.end());
}

void reverseUsingIterators(vector<int>& sequence) {
    auto start = sequence.begin();
    auto end = sequence.end() - 1;
    while (start < end) {
        iter_swap(start, end);
        ++start;
        --end;
    }
}

int main() {
    vector<int> sequence;
    int n;

    cout << "Enter the number of elements in the sequence: ";
    cin >> n;

    cout << "Enter the elements of the sequence:\n";
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        sequence.push_back(element);
    }

    cout << "Original sequence: ";
    for (const auto& elem : sequence) {
        cout << elem << " ";
    }
    cout << "\n";

    reverseUsingStdReverse(sequence);
    cout << "Reversed sequence using std::reverse: ";
    for (const auto& elem : sequence) {
        cout << elem << " ";
    }
    cout << "\n";

    reverseUsingIterators(sequence);
    cout << "Reversed sequence using iterators: ";
    for (const auto& elem : sequence) {
        cout << elem << " ";
    }
    cout << "\n";

    cout << endl << "Yug Shah\n24CE114";
    return 0;
}

