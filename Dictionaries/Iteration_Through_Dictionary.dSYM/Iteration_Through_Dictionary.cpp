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
        cout << "The student " << i->first << " has the #: " << i->second << endl;
    }
    /* output == The student Anirudh has the #: 6
                 The student Anna has the #: 7
                 The student Charlie has the #: 8
                 The student Luna has the #: 9
                 The student Michael has the #: 5 

       ------------------------------------------------------------------------ 
                 Mini-Segment of the Advanced Ways to Iterate Subunit
       ------------------------------------------------------------------------ */
     
    map<string, int>::reverse_iterator ri;
    for (ri = results.rbegin(); ri != results.rend(); ++ri) { 
        cout << "The student " << ri->first << " has the #: " << ri->second << endl;
    } 
    /* output == The student Michael has the #: 5
                 The student Luna has the #: 9
                 The student Charlie has the #: 8
                 The student Anna has the #: 7
                 The student Anirudh has the #: 6 */

    // this segment returns the same output as the first for loop
    map<string, int>::iterator j;
    j = results.begin();
    while(j != results.end()){
        cout << "The student " << j->first << " has the #: " << j->second << endl;
        ++j;
    }
    return 0;
}