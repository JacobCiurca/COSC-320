#include <iostream>
#include <stdlib.h>
#include "preqrec.h"
#include "d_except.h"
#include "d_pqueue.h"
#include "d_heap.h"
using namespace std;

int main()
{

    int f = rand()%39;
    int f1 = rand()%39;
    int f2 = rand()%39;
    int f3 = rand()%39;
    int f4 = rand()%39;
    int f5 = rand()%39;
    int f6 = rand()%39;
    int f7 = rand()%39;
    int f8 = rand()%39;
    int f9 = rand()%39;
    miniPQ<procReqRec> pq;
    procReqRec p("Process A", f);
    procReqRec p1("Process B", f1);
    procReqRec p2("Process C", f2);
    procReqRec p3("Process D", f3);
    procReqRec p4("Process E", f4);
    procReqRec p5("Process F", f5);
    procReqRec p6("Process G", f6);
    procReqRec p7("Process H", f7);
    procReqRec p8("Process I", f8);
    procReqRec p9("Process J", f9);
    pq.push(p);
    pq.push(p1);
    pq.push(p2);
    pq.push(p3);
    pq.push(p4);
    pq.push(p5);
    pq.push(p6);
    pq.push(p7);
    pq.push(p8);
    pq.push(p9);
    while(pq.empty() == false){
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}
