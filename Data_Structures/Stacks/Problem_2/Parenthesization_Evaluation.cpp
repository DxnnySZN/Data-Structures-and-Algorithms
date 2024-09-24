#include <iostream>
#include <stack>

using namespace std;

/* (()[[](]])). -> incorrect at position 7 because it should've been (()[[]()])). also incorrect at position 9 and 11 but it is not displayed because an earlier position is already wrong
   (()[](. -> incorrect at position 6 because it should've been (()[]). */

int main() {
    string line;

    // read input lines until end of file
    while(getline(cin, line)){
        stack<char> characterStack;
        bool correctParenthesization = true;
        int position = 0;

        // process each character in the line
        for(char character : line){
            if(character == '[' || character == '('){
                characterStack.push(character);
            } 
            else if(character == ']'){
                if(characterStack.empty() || characterStack.top() != '['){
                    correctParenthesization = false;
                    break; // stop further processing for this line
                } 
                else{
                    characterStack.pop(); // remove matched '['
                }
            } 
            else if(character == ')'){
                if(characterStack.empty() || characterStack.top() != '('){
                    correctParenthesization = false;
                    break; // stop further processing for this line
                } 
                else{
                    characterStack.pop(); // remove matched '('
                }
            } 
            else if(character == '.'){
                break; // end of test case
            }
            ++position;
        }

        // determine the result for this line
        if(correctParenthesization && characterStack.empty()){
            cout << "correct" << endl;
        } 
        else{
            cout << "incorrect " << position << endl;
        }
    }
    return 0;

    /* Test_Case: (()[[](]])). -> (: push onto the stack | stack = ['(']
                                  (: push onto the stack | stack = ['(', '(']
                                  ): pop from the stack | stack = ['(']
                                  [: push onto the stack | stack = ['(', '[']
                                  ]: pop from the stack | stack = ['(']
                                  [: push onto the stack | stack = ['(', '[']
                                  ]: pop from the stack | stack = ['(']
                                  ]: mismatch detected as there's no matching '[' for ']'
                                  ): the error was already found before this character

                                  the first mismatch occurs at position 7 (the 8th character)

                  (()[](. ->      (: push onto the stack | stack = ['(']
                                  (: push onto the stack | stack = ['(', '(']
                                  ): pop from the stack | stack = ['(']
                                  [: push onto the stack | stack = ['(', '[']
                                  ]: pop from the stack | stack = ['(']
                                  (: push onto the stack | stack = ['(', '(']
                                  .: end of the test case. the stack is not empty which indicates there is one unmatched opening parenthesis

                                  the mismatch occurs at position 6 (after '(' located at position 5) because the code expects a ')' after '('

                  ([[([((()))])]]). -> [: push onto the stack | stack = ['[']
                                       [: push onto the stack | stack = ['[', '[']
                                       (: push onto the stack | stack = ['[', '[', '(']
                                       [: push onto the stack | stack = ['[', '[', '(', '[']
                                       (: push onto the stack | stack = ['[', '[', '(', '[', '(']
                                       (: push onto the stack | stack = ['[', '[', '(', '[', '(', '(']
                                       ): pop from the stack | stack = ['[', '[', '(', '[', '(']
                                       ): pop from the stack | stack = ['[', '[', '(', '[']
                                       ): pop from the stack | stack = ['[', '[', '(']
                                       ]: pop from the stack | stack = ['[', '[']
                                       ]: pop from the stack | stack = ['[']
                                       ]: pop from the stack | stack = []
                                       .: end of the test case. the stack is empty and all brackets are matched

       Output:    incorrect 7
                  incorrect 6
                  correct */
}