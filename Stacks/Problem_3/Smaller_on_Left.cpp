#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// find the previous smaller element for every element in a vector
void findPreviousSmaller(vector<int>&nums, int numsSize){
    stack<int> numsResult;
    for(int i = 0; i < numsSize; ++i){
        while(!numsResult.empty()){ // loop until stack is empty
            if(numsResult.top() < nums[i]){ // if top element is less than current element, it is the previous smaller element
                cout << numsResult.top() << ' ';
                break;
            }
            else{
                numsResult.pop();
            }
        }
        if(numsResult.empty()){ // if the stack becomes empty, all the elements to the left of the current element are greater
            cout << -1 << ' ';
        }
        numsResult.push(nums[i]); // push current element into the stack
    }
}

int main(){
    vector<int> nums = {2, 5, 3, 7, 8, 1, 9};
    int numsSize = nums.size();
    findPreviousSmaller(nums, numsSize);
    return 0;

    /* [2, 5, 3, 7, 8, 1, 9] -> [-1, 2, 2, 3, 7, -1, 1] 

    (-1 because nothing is to the left of 2)          
    (2 because 2 is to the left of 5)
    (2 because 2 is to the left of 3. 5 would be ignored because 3 is smaller than 5)
    (3 because 3 is to the left of 7)
    (7 because 7 is to the left of 8)
    (-1 because nothing to the left of 1 is smaller than 1)
    (1 because 1 is to the left of 9) */
}