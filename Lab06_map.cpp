#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, string> m;
    m["Maryland"] = "Baltimore";
    m["New York"] = "New York City";
    m["Virginia"] = "Richmond";
    m["Florida"] = "Miami";
    m["Texas"] = "Austin";
    map<string, string>::const_iterator iter;
    cout << "Please enter a state name to search in the map\n";
    string state;
    cin >> state;
    int count = 0;
    for(iter = m.begin(); iter != m.end(); ++iter){
            if(iter->first == state){
            cout << "(" << iter->first << ", " << iter->second << ")" << endl;              //Search through map looking for the state as key
            count++;                                                                        //if found increase count
            }
    }
    if(count == 0){                                                                         //if state is not found within map
        cout << "Map entry with state name " << state << " not found within the map\n";
    }
    return 0;
}
