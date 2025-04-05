#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s; // Reads a word
    getline(cin, s); // Reads a line
    cout << s << endl;

    // Substring extraction
    string s1 = "abcdefghi";
    string sub = s1.substr(1, 3); // From index 1, length 3
    string sub2 = s1.substr(2); // From index 2 to the end

    // Finding substrings
    int pos = s1.find("cd"); // Returns the index of the first occurrence, or string::npos if not found
    int rpos = s1.rfind("e"); // Last occurrence

    // Modifying strings
    s1.insert(2, "xyz"); // Inserts "xyz" at index 2
    s1.erase(1, 3); // Erases 3 characters from index 1
    s1.replace(0, 4, "new"); // Replaces 4 characters from index 0 with "new"

    // Replacing all occurrences of a character
    replace(s1.begin(), s1.end(), 'a', 'z');

    // Stringstream for splitting
    string sentence = "This is a sentence";
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        cout << word << endl;
    }

    // Character case conversion
    char c = 'a';
    c = toupper(c); // Converts to uppercase
    c = tolower(c); // Converts to lowercase

    // String to number conversion
    string numStr = to_string(123); // Converts integer to string
    int num = stoi("123"); // Converts string to integer
    double dnum = stod("12.34"); // Converts string to double

    // Number to string conversion
    string floatStr = to_string(45.67);

    // Removing whitespace
    string strTrim = "  hello  ";
    strTrim.erase(0, strTrim.find_first_not_of(" ")); // Trim leading spaces
    strTrim.erase(strTrim.find_last_not_of(" ") + 1); // Trim trailing spaces

    // Reversing a string
    string rev = "hello";
    reverse(rev.begin(), rev.end());

    // Sorting a string
    string sorted = "dcba";
    sort(sorted.begin(), sorted.end());

    // Checking if a string contains only digits
    string numCheck = "12345";
    bool isDigits = all_of(numCheck.begin(), numCheck.end(), ::isdigit);

    // Concatenation
    string concat = "Hello" + string(" World");

    // Comparing strings
    string s2 = "apple", s3 = "banana";
    if (s2 < s3) cout << "apple comes before banana" << endl;

    return 0;
}