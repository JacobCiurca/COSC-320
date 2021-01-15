#ifndef COUNTONECHILD_H_INCLUDED
#define COUNTONECHILD_H_INCLUDED
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <queue>

#ifndef NULL
#include <cstddef>
#endif  // NULL

#include "d_tnode.h"
using namespace std;
tnode<char> *buildTreeOne(){
    tnode<char> *root, *b, *c, *d, *e, *f, *g;
    d = new tnode<char> ('D');
    f = new tnode<char> ('F');
    g = new tnode<char> ('F');
    e = new tnode<char> ('E', (tnode<char> *) NULL, g);
    b = new tnode<char> ('B', d, (tnode<char> *)NULL);
    c = new tnode<char> ('C',e, f);
    root = new tnode<char> ('A',b, c);
    return root;

}
template <typename T>
void countOneChild(tnode<T> *t, int& count){
    if(t != NULL){
        if (t->left == NULL && t->right != NULL){
            count++;
        }
        if (t->left != NULL && t->right == NULL){
            count++;
        }
        countOneChild(t->left, count);		// descend left
		countOneChild(t->right, count);	// descend right
    }
}

#endif // COUNTONECHILD_H_INCLUDED
