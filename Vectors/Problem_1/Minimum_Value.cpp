#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numsSize; 
    cin >> numsSize;
    vector<int> nums(numsSize);
    for(int i = 0; i < numsSize; ++i){
        cin >> nums[i]; // reads the element from nums one by one
    }

    int minimum = nums[0];
    // runtime: θ(numsSize - 1) -> θ(numsSize)
    for(int j = 1; j < numsSize; ++j){
        if(nums[j] < minimum){
            minimum = nums[j];
        }
    }

    // responsible for outputting the whole nums vector
    cout << "the minimum value of [";
    for(int k = 0; k < nums.size(); ++k){
        if(k != nums.size() - 1){
            cout << nums[k] << ", ";
        }
        else{
            cout << nums[k] << "]";
        }
    }
    cout << " is " << minimum << endl;
    return 0;
}