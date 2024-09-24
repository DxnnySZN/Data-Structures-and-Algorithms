#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> dictionary;
    map<string, int>::iterator i;
    char letter; // either 'a' or 'f'
    string word;
    while(cin >> letter){
        if(letter == 'a'){
            cin >> word;
            i = dictionary.find(word);
            if(i == dictionary.end()){ // if word is not in dictionary
                dictionary.insert(make_pair(word, 1));
            }
            else{
                ++i->second; // increment the frequency of the word by 1
            }
        }
        else if(letter == 'f'){
            cin >> word;
            i = dictionary.find(word);
            if(i == dictionary.end()){
                cout << 0;
            }
            else{
                cout << i->second;
            }
            cout << endl;
        }
    }
    return 0;

    /* Test_Case: a time (adds "time" to the dictionary with a frequency of 1)
                  a light (adds "light" to the dictionary with a frequency of 1)
                  f speed ("speed" is not in the dictionary, so the output is 0)
                  f time ("time" is in the dictionary with a frequency of 1, so the output is 1)
                  a time (increments the frequency of "time" by 1. the new frequency of "time" is 2)
                  a time (increments the frequency of "time" by 1 again. the new frequency of "time" is 3)
                  a speed (adds "speed" to the dictionary with a frequency of 1)
                  a speed (increments the frequency of "speed" by 1. the new frequency of "speed" is 2)
                  f graph ("graph" is not in the dictionary, so the output is 0)
                  a graph (adds "graph" to the dictionary with a frequency of 1)
                  f time ("time" is in the dictionary with a frequency of 3, so the output is 3)
                  a lake (adds "lake" to the dictionary with a frequency of 1)
                  f lake ("lake" is in the dictionary with a frequency of 1, so the output is 1)

       Output:    0
                  1
                  0
                  3
                  1 */
}