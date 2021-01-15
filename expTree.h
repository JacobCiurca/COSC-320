#ifndef EXPTREE_H_INCLUDED
#define EXPTREE_H_INCLUDED
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#ifndef NULL
#include <cstddef>
#endif  // NULL
#include "d_tnode.h"

tnode<char> *buildExpTree1()
{

	tnode<char> *root, *b, *c;

            b = new tnode<char> ('a');
            c = new tnode<char> ('b');
            root = new tnode<char> ('*', b, c);
            return root;


}

tnode<char> *buildExpTree2()
{

	tnode<char> *root, *b, *c, *d, *e;

           d = new tnode<char> ('a');
           e = new tnode<char> ('b');
           c = new tnode<char> ('c');
           b = new tnode<char> ('+', d, e);
           root = new tnode<char> ('*', b, c);
           return root;



}
tnode<char> *buildExpTree3(){

    tnode<char> *root, *b, *c, *d, *e, *f, *g, *h, *i;

        h = new tnode<char> ('a');
        i = new tnode<char> ('b');
        g = new tnode<char> ('c');
        e = new tnode<char> ('d');
        c = new tnode<char> ('e');
        f = new tnode<char> ('+', h, i);
        d = new tnode<char> ('*', f, g);
        b = new tnode<char> ('/', d, e);
        root = new tnode<char> ('-', b, c);
        return root;
}
template <typename T>
void PreorderOutput(tnode<T> *t, const string& separator = " ")
{
   // the recursive scan terminates on a empty subtree
   if (t != NULL)
   {
        cout << t->nodeValue << separator;
      PreorderOutput(t->left, separator);	// descend left
      PreorderOutput(t->right, separator);	// descend right
      			// output the node
   }
}


void prefixOutput(tnode<char> *exp){

    if(exp != NULL){
        cout << exp ->nodeValue << " ";
        prefixOutput(exp->left);
        prefixOutput(exp->right);
    }

}
tnode<char> *buildExpTree(const string& exp)
{
	// newnode is the address of the root of subtrees we build
	tnode<char> *newnode, *lptr, *rptr;
	char token;
	// subtrees go into and off the stack
	stack<tnode<char> *> s;
	int i = 0;


	// loop until i reaches the end of the string
	while(i != exp.length())
	{
		// skip blanks and tabs in the expression
		while (exp[i] == ' ' || exp[i] == '\t')
			i++;

		// if the expression has trailing whitespace, we could
		// be at the end of the string
		if (i == exp.length())
			break;

		// extract the current token and increment i
		token = exp[i];
		i++;

		// see if the token is an operator or an operand
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			// current token is an operator. pop two subtrees off
			// the stack.
			rptr = s.top();
			s.pop();
			lptr = s.top();
			s.pop();

			// create a new subtree with token as root and subtees
			// lptr and rptr and push it onto the stack
			newnode = new tnode<char>(token,lptr,rptr);
			s.push(newnode);
		}
		else // must be an operand
		{
			// create a leaf node and push it onto the stack
			newnode = new tnode<char>(token);
			s.push(newnode);
		}
	}

	// if the expression was not empty, the root of the expression
	// tree is on the top of the stack
	if (!s.empty())
		return s.top();
	else
		return NULL;
}



#endif // EXPTREE_H_INCLUDED
