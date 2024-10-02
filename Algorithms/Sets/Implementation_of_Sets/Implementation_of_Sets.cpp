// a set represents an unordered collection of distinct elements where elements cannot be duplicated

#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> sigmaSet;
    sigmaSet.insert(5);
    sigmaSet.insert(2);
    sigmaSet.insert(8);

    // check if a specific element is in the set
    if(sigmaSet.find(5) != sigmaSet.end()){
        cout << "element 5 is in the set" << endl;
    }
    else{
        cout << "element 5 is not in the set" << endl;
    }

    // method 1 to iterate through a set
    for(auto i = sigmaSet.begin(); i != sigmaSet.end(); ++i){
        cout << *i << " ";
    }
    cout << endl;

    // method 2 to iterate through a set
    for(auto& element : sigmaSet){
        cout << element << " ";
    }
    cout << endl;

    cout << "the size of the set is " << sigmaSet.size() << endl;
    return 0;

    /* Output: element 5 is in the set
               2 5 8 
               2 5 8 
               the size of the set is 3 */
}