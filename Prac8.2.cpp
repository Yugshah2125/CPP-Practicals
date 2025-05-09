#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);

    for (char &ch : input) {
        if (ispunct(ch)) {
            ch = ' ';
        } else {
            ch = tolower(ch);
        }
    }

    map<string, int> wordFrequency;
    istringstream stream(input);
    string word;

    while (stream >> word) {
        ++wordFrequency[word];
    }

    cout << "\nWord Frequency Distribution:\n";
    for (const auto &entry : wordFrequency) {
        cout << entry.first << ": " << entry.second << '\n';
    }

    cout << endl << "Yug Shah\n24CE114";

    return 0;
}

