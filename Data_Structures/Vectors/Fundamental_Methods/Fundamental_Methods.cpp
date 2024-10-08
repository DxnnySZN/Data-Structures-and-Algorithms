#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(6); // [0, 0, 0, 0, 0, 0]
    cout << "size of vector is " << v.size() << endl;

    v.push_back(5); // [0, 0, 0, 0, 0, 0, 5]
    cout << "new size of vector is " << v.size() << endl;
    cout << "index 6 stores the element " << v[6] << endl;

    v.pop_back(); // [0, 0, 0, 0, 0, 0]
    v.pop_back(); // [0, 0, 0, 0, 0]
    v.pop_back(); // [0, 0, 0, 0]
    cout << "new size of vector after 3 pops is " << v.size() << endl;

    // iterators are objs (like pointers) that point to an element inside the container
    vector<string> electronics;
    electronics.push_back("iPhone 16 Pro");
    electronics.push_back("Samsung Galaxy S24");
    electronics.push_back("Google Pixel 8A");
    electronics.push_back("Samsung Galaxy Z Fold6");

    // electronics -> [iPhone 16 Pro, Samsung Galaxy S24, Google Pixel 8A, Samsung Galaxy Z Fold6]

    vector<string>::iterator firstElement = electronics.begin();
    cout << "iterator begin() is pointing to element " << *firstElement << endl;
    vector<string>::iterator lastElement = --electronics.end();
    cout << "iterator end() is pointing to element " << *lastElement << endl;

    vector<string> newElectronics;
    vector<string>::iterator thirdElement = electronics.begin() + 2;
    electronics.erase(thirdElement);
    for(int i = 0; i < electronics.size(); i++){
        newElectronics.push_back(electronics[i]);
    }
    cout << "electronics vector without the third element is [";
    for(int i = 0; i < newElectronics.size(); i++){
        if(i != newElectronics.size() - 1){
            cout << newElectronics[i] << ", ";
        }
        else{
            cout << newElectronics[i] << "]" << endl;
        }
    }
    return 0;

    /* Output: size of vector is 6
               new size of vector is 7
               index 6 stores the element 5
               new size of vector after 3 pops is 4
               iterator begin() is pointing to element iPhone 16 Pro
               iterator end() is pointing to element Samsung Galaxy Z Fold6
               electronics vector without the third element is [iPhone 16 Pro, Samsung Galaxy S24, Samsung Galaxy Z Fold6] */
}