/* (()[[(]])). -> incorrect at position 7 because it should've been (()[[()]]). also incorrect at position 9 but it is not displayed because an earlier position is already wrong
   (()[](. -> incorrect at position 6 because it should've been (()[]). */

#include <iostream>
#include <stack>

using namespace std;

int main() {
    char character;
    cin >> character;
    stack<char> characterStack;
    bool correctParenthesization = true;
    int position = 0;
    while(correctParenthesization && character != '.'){ // period ends the evaluation
        if(character == '[' || character == '('){
            characterStack.push(character);
        }
        else if(character == ']'){
            if(characterStack.empty() || characterStack.top() != '['){
                correctParenthesization = false;
            }
            else{
                characterStack.pop(); // remove from the stack since it is not pending anymore
            }
        }
        else if(character == ')'){
            if(characterStack.empty() || characterStack.top() != '('){
                correctParenthesization = false;
            }
            else{
                characterStack.pop(); // remove from the stack since it is not pending anymore
            }
        }
        cin >> character;
        ++position;
    }
    if(correctParenthesization && characterStack.empty()){ // if characterStack.empty() is true, there are zero pending parentheses to be closed
        cout << "correct" << endl;
    }
    else{
        cout << "incorrect" << position << endl;
    }
    return 0;
}