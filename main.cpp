#include "LinkedList.h"
#include <bits/stdc++.h>
# include <iostream> 
# include <vector>
# include <string> 
# include <memory>
#include <algorithm>
using namespace std;
int main(int argc, char **argv){

    shared_ptr<LinkedList> ll;
    vector<string> input;
    string input_value;

    for (int i = 0; i < 7; ++i) {
        cin>>input_value;
        input.push_back(input_value.substr(0, input_value.find(' ')));

    }

    vector<int> aarray;
    // cool fucntion 
    // dereferencing every iteraton 
    for_each(input.begin(), input.begin() + 4,[&aarray](const string& var){ //#include <algorithm>
        aarray.push_back(stoi(var));
    });

    ll = make_shared<LinkedList>(&aarray[0], aarray.size());

    // convert strings to integers
    int param1 = stoi(input.at(5));
   int param2 = stoi(input.at(6));

//AF standing for addFront

    if (input.at(4) == "AF") {
        ll->addFront(param1);
    }
//AE standing for addEnd
    if (input.at(4) == "AE") {
        ll->addEnd(param1);
    }

//AP standing for addAtPosition

    if (input.at(4) == "AP") {
        ll->addAtPosition(param1, param2);
    }
//S standing for search
    if (input.at(4) == "S") {
        ll->search(param1);
    }

//DF standing for deleteFront
    if (input.at(4) == "DF") {
        ll->deleteFront();
    }

//DE standing for deleteEnd
    if (input.at(4) == "DE") {
        ll->deleteEnd();
    }

//DP standing for deletePosition
    if (input.at(4) == "DP") {
        ll->deletePosition(param1);
    }
//GI standing for getItem

    if (input.at(4) == "GI") {
        ll->getItem(param1);
    }
    // call print items function
    
    ll->printItems();
}