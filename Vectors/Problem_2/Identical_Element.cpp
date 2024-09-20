#include <iostream>
#include <vector>
#include <unordered_map> // doesn't maintain the elements in sorted order & has faster lookup and insertion times compared to <map>

using namespace std;

int main() {
    int mostRepeatedValue = 0;
    int highestCount = 0;
    int numsSize;
    cin >> numsSize;
    
    vector<int> nums(numsSize);
    unordered_map<int, int> countMap;

    for(int i = 0; i < numsSize; ++i){
        cin >> nums[i];
        countMap[nums[i]]++;

        if(countMap[nums[i]] > highestCount){
            highestCount = countMap[nums[i]];
            mostRepeatedValue = nums[i];
        }
    }

    cout << mostRepeatedValue << " has " << highestCount - 1 << " identical element";
    if(highestCount - 1 != 1){
        cout << "s";
    }
    cout << " in nums" << endl;
    return 0;

     /* logic behind countMap[nums[i]]++
        ---------------------------------------------------------------------------------------
        Iteration 1 (i = 0, nums[0] = 3):
        countMap[3] doesn't exist yet, so countMap[3] = 0 is initialized, then incremented to 1
        countMap becomes {3: 1}

        Iteration 2 (i = 1, nums[1] = 5):
        countMap[5] doesn't exist yet, so countMap[5] = 0, incremented to 1
        countMap becomes {3: 1, 5: 1}

        Iteration 3 (i = 2, nums[2] = 9):
        countMap[9] doesn't exist yet, so countMap[9] = 0, incremented to 1
        countMap becomes {3: 1, 5: 1, 9: 1}

        Iteration 4 (i = 3, nums[3] = 7):
        countMap[7] doesn't exist yet, so countMap[7] = 0, incremented to 1
        countMap becomes {3: 1, 5: 1, 9: 1, 7: 1}

        Iteration 5 (i = 4, nums[4] = 6):
        countMap[6] doesn't exist yet, so countMap[6] = 0, incremented to 1
        countMap becomes {3: 1, 5: 1, 9: 1, 7: 1, 6: 1}

        Iteration 6 (i = 5, nums[5] = 7):
        countMap[7] already exists and is 1, so it gets incremented to 2
        countMap becomes {3: 1, 5: 1, 9: 1, 7: 2, 6: 1}

        Iteration 7 (i = 6, nums[6] = 4):
        countMap[4] doesn't exist yet, so countMap[4] = 0, incremented to 1
        countMap becomes {3: 1, 5: 1, 9: 1, 7: 2, 6: 1, 4: 1}

        Iteration 8 (i = 7, nums[7] = 0):
        countMap[0] doesn't exist yet, so countMap[0] = 0, incremented to 1
        countMap becomes {3: 1, 5: 1, 9: 1, 7: 2, 6: 1, 4: 1, 0: 1} 
        ---------------------------------------------------------------------------------------

        logic behind if(countMap[nums[i]] > highestCount){
                         highestCount = countMap[nums[i]];
                         mostRepeatedValue = nums[i];
                     }
        --------------------------------------------------------------
        Iteration 1 (i = 0, nums[0] = 3):
        countMap[3] = 1, and highestCount = 0
        since 1 > 0, update highestCount = 1 and mostRepeatedValue = 3

        Iteration 2 (i = 1, nums[1] = 5):
        countMap[5] = 1, and highestCount = 1
        since 1 is not greater than 1, no updates are made

        Iteration 3 (i = 2, nums[2] = 9):
        countMap[9] = 1, and highestCount = 1
        since 1 is not greater than 1, no updates are made

        Iteration 4 (i = 3, nums[3] = 7):
        countMap[7] = 1, and highestCount = 1
        since 1 is not greater than 1, no updates are made

        Iteration 5 (i = 4, nums[4] = 6):
        countMap[6] = 1, and highestCount = 1
        since 1 is not greater than 1, no updates are made

        Iteration 6 (i = 5, nums[5] = 7):
        countMap[7] = 2, and highestCount = 1
        since 2 > 1, update highestCount = 2 and mostRepeatedValue = 7

        Iteration 7 (i = 6, nums[6] = 4):
        countMap[4] = 1, and highestCount = 2
        since 1 is not greater than 2, no updates are made

        Iteration 8 (i = 7, nums[7] = 0):
        countMap[0] = 1, and highestCount = 2
        since 1 is not greater than 2, no updates are made 
        --------------------------------------------------------------

        Test_Case: 8
                   3 5 9 7 6 7 4 0
                  
        Output:    7 has 1 identical element in nums */
}