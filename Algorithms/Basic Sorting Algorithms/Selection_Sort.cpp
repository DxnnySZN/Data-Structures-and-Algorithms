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
    int randomGeneratedInt = rand() % 50 + 1; // generates int between 1 and 50
    while(cin >> size){
        vector<int> v(size);
        for(int i = 0; i < size; ++i){
            v[i] = randomGeneratedInt;
            if(size != 0){
                cout << v[i] << " ";
            }
            else{
                cout << v[i];
            }
        }
        selection_sort(v);
        cout << "'s reverse sequence is ";
        for(int i = 0; i < v.size(); ++i){
            if(size != 0){
                cout << v[i] << " ";
            }
            else{
                cout << v[i];
            }
        }
        cout << endl;
    }
    return 0;
}