// in C++, dictionaries are called maps
#include <iostream> // io => input output | this inclusion allows the code to be printed in the console
#include <map>

using namespace std; // std => standard

int main(){
    // key: name of student
    // value: #

    map<string, int> results;

    results["Charlie"] = 8;
    results["Anna"] = 7;
    results["Michael"] = 5;
    results["Luna"] = 9;
    results["Anirudh"] = 6;

    // results.begin() accesses the first element | returns a pointer so writing results.begin() by itself and then cout << results.begin() would not run because it's a memory address

    map<string, int>::iterator it = results.begin(); // this is the correct way to write
    string name = it -> first;
    int value = it -> second;

    cout << "Name of Student: " << name << ", #: " << value << endl;
    return 0;
}