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
}