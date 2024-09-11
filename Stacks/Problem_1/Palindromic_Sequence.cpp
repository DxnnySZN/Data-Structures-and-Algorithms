#include <iostream>
#include <stack>

using namespace std;

/* palindromic sequence example: 4 10 20 20 10 -> yes (10 20 20 10 makes it palindromic)
                                 5 1 2 3 2 2 -> no */
int main() {
    int n;
    while(cin >> n){ // read number of elements and process until end of input
        // special case: if the number of elements is 0, it's automatically a palindrome
        if(n == 0){
            cout << "yes" << endl;
            continue;
        }

        stack<int> nums; // stack to hold first half of the sequence

        // push the first half of the numbers into the stack
        for(int i = 0; i < n / 2; ++i){
            int num;
            cin >> num;
            nums.push(num);
        }

        // if n is odd, skip the middle element
        if(n % 2 != 0){
            int middle;
            cin >> middle;
        }

        bool isPalindrome = true;

        // check the second half of the sequence
        for(int i = n / 2 + (n % 2); i < n; ++i){ // included (n % 2) because if n is odd, the loop must start at the second half after skipping the middle element
            int num;
            cin >> num;
            if(nums.empty() || num != nums.top()){
                isPalindrome = false;
            }
            if(!nums.empty()){
                nums.pop();
            }
        }   

        if(isPalindrome){
            cout << "yes" << endl;
        } 
        else{
            cout << "no" << endl;
        }
    } 
    return 0;

    /* Test_Case: 4 10 20 20 10 -> n = 4
                                   read 4 numbers: 10 20 20 10

                                   process first half: n / 2 = 2
                                   push the first 2 numbers onto the stack: 10, 20
                                   stack after this operation: [20, 10]

                                   n % 2 == 0 so no middle element to skip

                                   starting index for the second half is 2

                                   read 20, compare with stack top (20): they match so pop the stack
                                   stack after popping: [10]

                                   read 10, compare with stack top (10): they match so pop the stack
                                   stack after popping: []

                                   result: stack is empty so it is palindromic

                  5 1 2 3 2 2 ->   n = 5
                                   read 5 numbers: 1 2 3 2 2

                                   process first half: n / 2 = 2
                                   push the first 2 numbers onto the stack: 1, 2
                                   stack after this operation: [2, 1]

                                   n % 2 == 1 so read middle element: 3

                                   starting index for the second half is 3 (n / 2 + 1)

                                   read 2, compare with stack top (2): they match so pop the stack
                                   stack after popping: [1]

                                   read 2, compare with stack top (1): they do not match

                                   result: stack still has 1 so it is not palindromic

       Output:    yes
                  no */
}