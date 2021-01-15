#include <iostream>
#include "d_tnode.h"
#include "CountOneChild.h"
using namespace std;

int main()
{
    int count=0;
    tnode<char> *t = buildTreeOne();
    countOneChild(t, count);
    cout << "There are " << count << " one child interior nodes in tree one.\n";


    return 0;
}
