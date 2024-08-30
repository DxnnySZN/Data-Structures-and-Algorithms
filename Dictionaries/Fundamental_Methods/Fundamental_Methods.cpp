#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> books;
    books["Solaria"] = 1998;
    books["Velsim"] = 1942;
    books["Good Tree"] = 2005;
    books["Last Sword"] = 1879;
    books["Space Travel"] = 2017;

    // empty: test whether dictionary is empty | output == Not Empty
    if(books.empty()){ 
        cout << "Empty Dictionary";
    }
    else{
        cout << "Not Empty";
    }
    cout << endl;

    // size: return dictionary size | output == We have a total of 5 books in the library
    cout << "We have a total of " << books.size() << " books in the library" << endl;
    
    // insert: insert elements
    auto p = books.insert({"Computer", 1932}); // auto infers the data type p is supposed to be
    cout << "Name: " << p.first->first << endl; // output == Name: Computer
    cout << "Year: " << p.first->second << endl; // output == Year: 1932
    cout << "Boolean: " << p.second << endl; // returns 1 (meaning true) because the new element has been inserted in the dictionary

    pair<map<string, int>::iterator, bool> t = books.insert({"Computer", 1932}); // same thing as auto t = books.insert({"Computer", 1932});
    cout << "Name: " << t.first->first << endl; // output == Name: Computer
    cout << "Year: " << t.first->second << endl; // output == Year: 1932 | year doesn't update because "Computer" already exists 
    cout << "Boolean: " << t.second << endl; // returns 0 (meaning false) because "Computer" already exists in the dictionary

    // erase: erase elements
    int n = books.erase("Solaria"); // n = 1 because only 1 element has been erased
    cout << "Solaria -> " << books["Solaria"] << endl; // output == Solaria -> 0

    map<string, double> mcdonalds;
    mcdonalds["McChicken"] = 6.99;
    mcdonalds["McRibs"] = 7.99;
    mcdonalds["McFlurry"] = 2.99;
    mcdonalds["Fries"] = 3.99;

    auto i = mcdonalds.begin();
    cout << mcdonalds["Fries"] << endl; // output == 3.99
    mcdonalds.erase(i);
    cout << mcdonalds["Fries"] << endl; // output == 0

    // find: get iterator to element | output == It is inside
    auto j = mcdonalds.find("McRibs");
    if(j != mcdonalds.end()){
        cout << "It is inside" << endl;
    }
    else{
        cout << "No element of this key" << endl;
    }

    map<string, double> sushi;
    sushi["Nigiri"] = 9.99;
    sushi["Sashimi"] = 8.49;
    sushi["Maki"] = 8.99;
    sushi["Crunchy Roll"] = 11.49;

    /* output == Sashimi has the price: 8.49
    this is because the while loop erases all keys and values of sushi except Sashimi
    running "cout << k->first << " has the price: " << k->second << endl" without the while loop would result in output == Crunchy Roll has the price: 11.49 */
    auto k = sushi.begin();
    while (k != sushi.find("Sashimi")){
        k = sushi.erase(k);
    }
    cout << k->first << " has the price: " << k->second << endl;
    return 0;
}