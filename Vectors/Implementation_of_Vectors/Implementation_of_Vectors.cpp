#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 5;
    vector<int> nums(n); // n in nums(n) allocates the memory for nums
    nums[0] = 3;
    nums[1] = 6;
    nums[2] = 4;
    nums[3] = 8;
    nums[4] = 2;
    cout << nums[0] << " " << nums[1] << " " << nums[2] << " " << nums[3] << " " << nums[4] << endl; // running this without initially assigning values to indices will automatically return 0 for each index

    int rizzlers = 10;
    vector<double> rizzRoom(rizzlers);
    for(int i = 0; i < rizzlers; ++i){
        cin >> rizzRoom[i]; // this is what forces me to manually input values in Test_Case.txt so the code can run the vector as intended
    }
    for(int i = 0; i < rizzlers; ++i){
        cout << "The rizzler with index " << i << " has the mark(value): " << rizzRoom[i] << endl;
    }
    return 0;

    /* Test_Case: 3.4 10 7.8 6.1 4.2 6.7 4.1 8.3 9.1 2.8 

       Output: 
       3 6 4 8 2
       The rizzler with index 0 has the mark(value): 3.4
       The rizzler with index 1 has the mark(value): 10
       The rizzler with index 2 has the mark(value): 7.8
       The rizzler with index 3 has the mark(value): 6.1
       The rizzler with index 4 has the mark(value): 4.2
       The rizzler with index 5 has the mark(value): 6.7
       The rizzler with index 6 has the mark(value): 4.1
       The rizzler with index 7 has the mark(value): 8.3
       The rizzler with index 8 has the mark(value): 9.1
       The rizzler with index 9 has the mark(value): 2.8 */
}