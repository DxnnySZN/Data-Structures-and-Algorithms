// bubble sort has time complexity of O(n^2) which indicates this sorting method is inefficient

#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& v){
    bool isSorted = false;
    int lastIndex = v.size() - 1;
    while(!isSorted){
        isSorted = true;
        for(int i = 0; i < lastIndex; ++i){
            if(v[i] > v[i + 1]){
                swap(v[i], v[i + 1]);
                isSorted = false;
            }
        }
        --lastIndex;
    }
}

int main() {
    vector<int> v(5);
    v = {3, 2, 5, 1, 4};
    cout << "vector without sorting: [";
    for(int i = 0; i < v.size(); ++i){
        if(i != v.size() - 1){
            cout << v[i] << ", ";
        }
        else{
            cout << v[i] << "]";
        }
    }
    cout << endl;
    bubble_sort(v);
    cout << "vector after bubble sort: [";
    for(int i = 0; i < v.size(); ++i){
        if(i != v.size() - 1){
            cout << v[i] << ", ";
        }
        else{
            cout << v[i] << "]";
        }
    }
    return 0;

    /* Output: vector without sorting:      [3, 2, 5, 1, 4]
               vector after bubble sort:    [1, 2, 3, 4, 5] */
}