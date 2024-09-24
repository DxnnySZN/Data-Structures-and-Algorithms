// insertion sort has time complexity of O(n^2) which indicates this sorting method is inefficient

#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& v){
    for(int i = 1; i < v.size(); ++i){
        int element = v[i];
        int j = i;
        while(j > 0 && v[j - 1] > element){ // you need to first verify if j is greater than 0. if the two conditions were flipped, then the code will run in an error
            v[j] = v[j - 1];
            --j;
        }
        v[j] = element;
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
    insertion_sort(v);
    cout << "vector after insertion sort: [";
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
               vector after insertion sort: [1, 2, 3, 4, 5] */
}