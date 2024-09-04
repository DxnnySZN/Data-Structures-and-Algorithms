#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> numbers;
    numbers.push(1);
    numbers.push(3);
    numbers.push(6);
    /* numbers looks like this: 6 -> top element
                                3
                                1 */
    numbers.pop(); 
    /* numbers now looks like this: 3 -> top element
                                    1 */                    
    numbers.push(7);
    numbers.push(9);
    cout << "Top of the stack is: " << numbers.top() << endl; // output = Top of the stack is: 9

    stack<string> names;
    names.push("Daniel");
    if(names.empty()){
        cout << "empty" << endl;
    }
    else{
        cout << "not empty" << endl; // because names has one element, Daniel, names.empty() is false & output = not empty
    }

    stack<int> numbersV2;
    for(int i = 1; i <= 10; i++){
        numbersV2.push(i);
    }
    // this will sum all the elements in the stack
    int sum = 0;
    while(!numbersV2.empty()){
        sum += numbersV2.top();
        numbersV2.pop();
    }
    cout << "Total is " << sum << endl; // output = 55 (10+9+8+7+6+5+4+3+2+1 = 55)

    stack<string> foods;
    foods.push("chicken");
    foods.push("pizza");
    cout << foods.size() << endl; // output = 2
    foods.pop();
    cout << foods.size() << endl; // output = 1
    return 0;
}