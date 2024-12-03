#include <iostream>
#include <string>
#include "src/ReplaceNthOccurrence.cpp"

using namespace std;

int main()
{
    string text;
    int n;
    char old_value, new_value;

    cout << "Enter the source string: ";
    getline(cin, text);

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Enter the old value: ";
    cin >> old_value;

    cout << "Enter the new value: ";
    cin >> new_value;

    string new_str = ReplaceNthOccurrence(text, n, old_value, new_value);

    cout << "Modified string: " << new_str << endl;

    return 0;
}