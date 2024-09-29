/* merge sort has time complexity of O(n * logn) 
this is much better than selection sort, insertion sort, and bubble sort */

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& v, int left, int mid, int right){
    int numElements = right - left + 1;
    vector<int> solution(numElements);
    int i = left; // beginning element of first half subsequence
    int j = mid + 1; // beginning element of second half subsequence
    int solutionIdx = 0;  
    while(i <= mid && j <= right){ // while the elements on the first half subsequence and the elements on the second half subsequence aren't finished, we keep comparing
        if(v[i] <= v[j]){
            solution[solutionIdx] = v[i];
            ++i;
        }
        else{
            solution[solutionIdx] = v[j];
            ++j;
        }
        ++solutionIdx;
    }
    // if all the elements of the second half subsequence are taken, only i <= mid is true
    while(i <= mid){
        solution[solutionIdx] = v[i];
        ++i;
        ++solutionIdx;
    }
    // if all the elements of the first half subsequence are taken, only j <= right is true
    while(j <= right){
        solution[solutionIdx] = v[j];
        ++j;
        ++solutionIdx;
    }
    // this is only implemented in the case that the user wants to start sorting from a non-zero position
    for(solutionIdx = 0; solutionIdx < numElements; ++solutionIdx){
        v[left + solutionIdx] = solution[solutionIdx];
    }
}

void merge_sort(vector<int>& v, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(v, left, mid); // from beginning element to the middle
        merge_sort(v, mid + 1, right); // from element after the middle to the end
        merge(v, left, mid, right); // successfully sorts the vector
    }
}

int main(){
    vector<int> v(5);
    v = {3, 2, 5, 1, 4};
    cout << "vector before sorting: ";
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
    merge_sort(v, 0, v.size() - 1);
    cout << "vector after sorting: ";
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;

    /* Output: vector before sorting: 3 2 5 1 4 
               vector after sorting:  1 2 3 4 5 */
}