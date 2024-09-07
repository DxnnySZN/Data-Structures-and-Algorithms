#include <iostream>
#include <map>

using namespace std;

int main() {
    string query;
    map<string, int> wordBag;
    while(cin >> query){
        if(query == "store"){
            string word;
            cin >> word;
            if(wordBag.find(word) == wordBag.end()) { // if a word is not inside the wordbag, insert the word & set the amount of times word is used = 1
                wordBag.insert(make_pair(word, 1));
            }
            else{
                auto i = wordBag.find(word);
                ++i->second; // increase the word count by 1
            }
        }
        else if(query == "minimum?"){ // whichever word is lexicographically first
            if(wordBag.empty()){
                cout << "indeterminate minimum" << endl;
            }
            else{
                auto i = wordBag.begin();
                cout << "minimum: " << i->first << ", " << i->second << " time(s)" << endl;
            }
        }
        else if(query == "maximum?"){ // whichever word is lexicographically last
            if(wordBag.empty()){
                cout << "indeterminate maximum" << endl;
            }
            else{
                auto i = --wordBag.end();
                cout << "maximum: " << i->first << ", " << i->second << " time(s)" << endl;
            }
        }
        else if(query == "delete"){
            string word;
            cin >> word;
            auto i = wordBag.find(word);
            if(i != wordBag.end()){ // if word is inside
                if(i->second > 1){ // if # of times word appears is > 1, decrease the int by 1. otherwise, remove the word completely
                    --i->second;
                }
                else{
                    wordBag.erase(i);
                }
            }
        }
        if(query == "end"){
            break;
        }
    }
    return 0;

    /* Test_Case: store apple (count is 1)
                  store banana (count is 1)
                  store apple (count is 2)
                  minimum? (apple with 2 occurrences)
                  maximum? (banana with 1 occurrence)
                  store cherry
                  maximum? (cherry with 1 occurrence)
                  delete apple (count is 1)
                  minimum? (apple with 1 occurrence)
                  delete banana (count is 0)
                  delete banana (count is still 0)
                  store banana (count is 1)
                  delete apple (count is 0)
                  minimum? (banana with 1 occurrence)
                  end

       Output:    minimum: apple, 2 time(s)
                  maximum: banana, 1 time(s)
                  maximum: cherry, 1 time(s)
                  minimum: apple, 1 time(s)
                  minimum: banana, 1 time(s) */
}