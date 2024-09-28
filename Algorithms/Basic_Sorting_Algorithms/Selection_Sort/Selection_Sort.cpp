// selection sort has time complexity of O(n^2) which indicates this sorting method is inefficient

#include <iostream>
#include <vector>

using namespace std;

/* the & gives access to the reference of the original vector
utilize const because the vector will not be changed inside this function */

int minPosition(const vector<int>& v, int left, int right){
    int position = left;
    for(int i = left + 1; i <= right; ++i){
        if(v[i] < v[position]){
            position = i;
        }
    }
    return position;
}

void selection_sort(vector<int>& v){ 
    for(int i = 0; i < v.size() - 1; ++i){
        int j = minPosition(v, i, v.size() - 1);
        swap(v[j], v[i]);
    }
}

int main() {
    int size;
    while(cin >> size){
        vector<int> v(size);
        for(int i = 0; i < size; ++i){
            v[i] = rand() % 50 + 1; // generates int between 1 and 50
            cout << v[i] << " ";
        }
        selection_sort(v);
        cout << "'s sorted sequence is ";
        for(int i = 0; i < v.size(); ++i){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;

    /* Test_Case: 8
    
       Output:    42 18 35 1 20 25 29 9 's sorted sequence is 1 9 18 20 25 29 35 42 */
}