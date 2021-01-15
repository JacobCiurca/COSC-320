#ifndef STATECITY_CLASS
#define STATECITY_CLASS

#include <iostream>
#include <string>

using namespace std;

// object stores the state name and city in the state
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

#endif	// STATECITY_CLASS


