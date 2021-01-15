#include <iostream>
#include <set>
using namespace std;
class stateCity{
public:
        stateCity(string s, string c){
            state = s;
            city = c;
        };
        string getState(){
            return state;                                                       //Defined stateCity in main instead of a separate file
        };
        string getCity(){
            return city;
        };
        friend ostream& operator<< (ostream &ostr, const stateCity& obj);
        friend bool operator< (const stateCity& lhs, const stateCity& rhs);
        friend bool operator== (const stateCity& lhs, const stateCity& rhs);
private:
        string state;
        string city;
};
        ostream& operator<< (ostream &ostr, const stateCity& obj){
            ostr << "(" << obj.state << ", " << obj.city << ")";
            return ostr;
        }
        bool operator< (const stateCity& lhs, const stateCity& rhs){
            if(lhs.city < rhs.city){
                return true;
            }
            else if(lhs.city == rhs.city && lhs.state < rhs.state){             //Operator< used to insert objects into set
                return true;                                                    //Must return true if either new city or if the city is in a different state
            }
            else{
                return false;
            }
        }
        bool operator== (const stateCity& lhs, const stateCity& rhs){
            if(lhs.state == rhs.state){
                return true;
            }
            else{                                                               //Operator== used to create find function later in lab
                return false;
            }
        }

        void findState(const set<stateCity>& s, stateCity value){
            set<stateCity>::const_iterator iter = s.begin();
            int count = 0;
            for(iter = s.begin(); iter != s.end(); ++iter){                     //find function, checks state value using == operator overloading and outputs state name if true
                if(*iter == value){
                    cout << *iter << endl;
                    count++;
                }
            }
            if(count == 0){
                cout << value.getState() << " not found in set\n";
            }


        }

int main()
{
    stateCity sc1("Maryland", "Salisbury");
    stateCity sc2("Virginia", "Richmond");
    stateCity sc3("Maryland", "Baltimore");
    stateCity sc4("Florida", "Miami");
    stateCity sc5("Texas", "Houston");
    set<stateCity> sc;
    sc.insert(sc1);
    sc.insert(sc2);
    sc.insert(sc3);
    sc.insert(sc4);
    sc.insert(sc5);
    cout << "Please enter a state to search for in the set.\n";
    string State;
    cin >> State;
    stateCity sc6(State, ""); //declare state object with empty city to search set
    cout << "Searching for stateCity objects with the state " << State << " in the set\n";
    findState(sc, sc6);



    return 0;
}
