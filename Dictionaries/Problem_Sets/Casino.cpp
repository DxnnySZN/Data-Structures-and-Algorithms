#include <iostream>
#include <map>

using namespace std;

int main() {
    string name, operation;
    map<string, int> player; // key = name, value = earnings
    map<string, int>::iterator i;
    int x;
    while(cin >> name >> operation){ // while(cin >> name >> operation) -> while we keep reading the name of the person and the operation 
        if(operation == "enters"){
            i = player.find(name);
            if(i != player.end()){
                cout << name << " is already in the casino" << endl;
            }
            else{
                player.insert(make_pair(name, 0)); // make_pair adds a new player and sets the new player's earnings to 0
            }
        }
        else if(operation == "wins"){
            cin >> x; // reads the number
            i = player.find(name);
            if(i == player.end()){
                cout << name << " is not in the casino" << endl;
            }
            else{
                i->second += x; // updates player's value
            }
        }
        else if(operation == "leaves"){
            i = player.find(name);
            if(i == player.end()){
                cout << name << " is not in the casino" << endl;
            }
            else{
                cout << name << " has won " << i->second << endl;
                player.erase(name);
            }
        }
        if(name == "end"){
            break; // ends the loop
        }
    }
    cout << "-----------" << endl;
    for(i = player.begin(); i != player.end(); ++i){
        cout << i->first << " is winning " << i->second << endl;
    }
    return 0;

    /* Casino_Test_Case: Daniel enters
                         Daniel wins 1000
                         Jeff wins 500
                         Jeff leaves
                         Chris leaves
                         Alex enters
                         Alex leaves
                         Logan enters
                         Logan wins 800
                         end
                         
       Output: Jeff is not in the casino
               Jeff is not in the casino
               Chris is not in the casino
               Alex has won 0
               -----------
               Daniel is winning 1000
               Logan is winning 800 */
}