// in C++, dictionaries are called maps
#include <iostream> // io => input output | this inclusion allows the code to be printed in the console
#include <map>

using namespace std; // std => standard

int main() {
    // key: name of student
    // value: #

    map<string, int> results;

    results["Charlie"] = 8;
    results["Anna"] = 7;
    results["Michael"] = 5;
    results["Luna"] = 9;
    results["Anirudh"] = 6;

    // accessing the first element
    map<string, int>::iterator it = results.begin(); // points to the first element (the key that's lexicographically first, Anirudh)
    string name = it->first;
    int value = it->second;

    cout << "First Name of Student: " << name << ", #: " << value << endl;

    // accessing the last element
    it = --results.end(); // points to the last element (the key that's lexicographically last, Michael)
    name = it->first;
    value = it->second;

    cout << "Last Name of Student: " << name << ", #: " << value << endl;

    cout << results["Anna"] << endl; // returns 7 but if i do results["Anna"] = 10 below results["Anirudh"] = 6, it will return 10

    return 0;
}