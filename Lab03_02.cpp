#include <iostream>
#include "max.h"
#include "d_tnode.h"
using namespace std;

int main()
{
    int max=0;
    tnode<int> *t = buildIntTree();
    FindMaxValue(t, max);
    cout << "The max value for this integer tree is: " << max << endl;
    return 0;
}
