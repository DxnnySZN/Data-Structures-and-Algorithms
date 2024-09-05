#include <iostream>
#include <stack>

using namespace std;

/* palindromic sequence example: 4 10 20 20 10 -> yes (10 20 20 10 makes it palindromic)
                                 5 1 2 3 2 2 -> no */
int main() {
    int num;
    cin >> num;
    bool isPalindrome = true;
    // base case
    if(num == 1 || num == 0){
        isPalindrome;
    }
    stack<int> nums;
    for(int i = 0; i < num / 2; ++i){
        cin >> num;
        nums.push(num);
    }
    // if num is odd, read the middle value
    if(num % 2 != 0){
        cin >> num; 
    }
    while(!nums.empty() && isPalindrome){
        cin >> num;
        isPalindrome = (num == nums.top());
        nums.pop();
    }
    if(isPalindrome){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}