#ifndef MAX_H_INCLUDED
#define MAX_H_INCLUDED
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <queue>

#ifndef NULL
#include <cstddef>
#endif  // NULL

#include "d_tnode.h"
tnode<int> *buildIntTree(){
    tnode<int> *root, *b, *c, *d, *e, *f;
    d = new tnode<int> (5);
    e = new tnode<int> (48);
    f = new tnode<int> (12);
    b = new tnode<int> (40, d, (tnode<int> *) NULL);
    c = new tnode<int> (15, e, f);
    root = new tnode<int> (35, b, c);
    return root;

}
template <typename T>
void FindMaxValue(tnode<T> *t, int& max){
    if(t != NULL){
        if(t->nodeValue > max){
            max = t->nodeValue;
        }
        FindMaxValue(t->left, max);		// descend left
		FindMaxValue(t->right, max);	// descend right
    }
}


#endif // MAX_H_INCLUDED
