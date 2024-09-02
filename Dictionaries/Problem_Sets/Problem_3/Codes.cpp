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
}