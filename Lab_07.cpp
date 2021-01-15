#include <iostream>
#include <fstream>
#include "d_except.h"
#include "d_hash.h"
#include "d_hashf.h"
//extract a word from fin
ifstream& getWord(ifstream& fin, string& w)
{
	char c;

	w = "";	// clear the string of characters

	while (fin.get(c) && !isalpha(c))
		;	// do nothing. just ignore c

	// return on end-of-file
	if (fin.eof())
		return fin;

	// record first letter of the word
	w += tolower(c);

	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);

	return fin;
}

using namespace std;

int main()
{
    ifstream s;
    s.open("dict.dat");
    string strin;
    myhash <string, hFstring> h(1373);
    while(getline(s, strin)){
    h.insert(strin);
    }
    s.close();

    cout << "Please enter the file name to spell check\n";
    string fname;
    cin >> fname;
    s.open(fname);
    string w;
    while(!s.eof()){
    getWord(s, w);
    cout << "Misspelled words: \n";
    if(h.find(w) == h.end()){
        cout << w << endl;
    }
    }
    s.close();

    return 0;
}
