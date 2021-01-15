#include <iostream>
#include <string>
#include <stack>
#include "d_tnode.h"
#include "d_tnode1.h"
#include "expTree.h"
#include "infixtopostfix.h"
#include "d_tnode.h"
#include "d_expsym.h"
#include "d_except.h"
using namespace std;

int main()
{
    tnode<char> *t1 = buildExpTree1();
    tnode<char> *t2 = buildExpTree2();
    tnode<char> *t3 = buildExpTree3();
    cout << "Pre-order and post-order output for the first binary expression tree:\n";
    PreorderOutput(t1);
    cout << endl;
    postorderOutput(t1);
    cout << endl;
    cout << "Pre-order and post-order output for the second binary expression tree:\n";
    PreorderOutput(t2);
    cout << endl;
    postorderOutput(t2);
    cout << endl;
    cout << "Pre-order and post-order output for the third binary expression tree:\n";
    PreorderOutput(t3);
    cout << endl;
    postorderOutput(t3);
    cout << endl;

    cout << endl;
    cout << "Prefix of tree 2: ";
    prefixOutput(t2);
    cout << endl;
    cout << "Please enter an expression to put in a tree.\n";
    string tree;
    cin >> tree;
    infix2Postfix in;
    in.setInfixExp(tree);
    string post_tree;
    post_tree = in.postfix();
    tnode<char> *t4 = buildExpTree(post_tree);
    cout << "Prefix and Postfix output of the tree.\n";
    prefixOutput(t4);
    cout << endl;
    postorderOutput(t4);
    cout << endl;
    cout << "Tree Display.\n";
    displayTree(t4, 2);
    cout << endl;
    return 0;
}
