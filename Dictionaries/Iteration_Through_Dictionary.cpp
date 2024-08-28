#include <iostream> 
#include <map>

using namespace std; 

int main() {
    // key: name of student
    // value: #

    map<string, int> results;

    results["Charlie"] = 8;
    results["Anna"] = 7;
    results["Michael"] = 5;
    results["Luna"] = 9;
    results["Anirudh"] = 6;

    map<string, int>::iterator i;
    for(i = results.begin(); i != results.end(); ++i){ // do i != results.end() because we want access to all the keys and values
    // end() returns a iterator that points to the fictional element after the last one, which is not what we want
        cout << "The student " << i->first << " has the mark: " << i->second << endl;
    }

    // Advanced Ways to Iterate
    map<string, int>::reverse_iterator ri;
    for (ri = results.rbegin(); ri != results.rend(); ++ri) { 
        cout << "The student " << ri->first << " has the mark: " << ri->second << endl;
    } 
    return 0;
}