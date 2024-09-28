#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    while(cin >> size){
        if(size != 0){
            vector<int> v(size);
            for(int i = 0; i < size; ++i){
                cin >> v[i];
            }
            for(int j = size - 1; j >= 0; --j){ // reverses the sequence once the elements in the vector have been read
                if(j == 0){
                    cout << v[j] << " ";
                }
                else{
                    cout << v[j];
                }
            }
        }
        else{
            cout << "there are no elements in the vector" << endl;
        }
    }
    return 0;

    /* Test_Case: 7
                  2 6 4 5 9 0 1
                  
       Output:    1095462 */
}