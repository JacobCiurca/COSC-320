#include <iostream>
#include "d_graph.h"
#include "d_util.h"
#include <fstream>
using namespace std;

int main()
{

    graph<string> g;
    ifstream data;
    data.open("graphA.dat");
    int vertex;
    int edge;
    string a;
    string e1;
    string e2;
    int e3;
    data >> vertex;
    for(int i=0; i<vertex; i++){
            data >> a;
            g.insertVertex(a);

    }
    data >> edge;
    for(int i=0; i<edge; i++){
        data >> e1;
        data >> e2;
        data >> e3;
        g.insertEdge(e1, e2, e3);
    }
    cout << "Here is your starting graph" << endl;
    cout << g;
    cout << "Inserting edge from F to D with weight 1" << endl;
    g.insertEdge("F", "D", 1);
    cout << "Erasing vertex B" << endl;
    g.eraseVertex("B");
    cout << "Erasing edge from A to D" << endl;
    g.eraseEdge("A", "D");
    cout << "Please enter a new vertex to be inserted" << endl;
    string v;
    cin >> v;
    g.insertVertex(v);
    cout << "Here are the neighbors of vertex " << v << endl;
    set<string> v5 = g.getNeighbors(v);
    int size = 0;
    for(auto it = v5.begin(); it != v5.end(); ++it){
        cout << *it << endl;
        size++;
    }
    if(size == 0){
        cout << v << " has no neighbors" << endl;
    }
    cout << "Creating vertex G" << endl;
    g.insertVertex("G");
    cout << "Adding edge from G to C with weight 1" << endl;
    g.insertEdge("G", "C", 1);
    cout << "Adding edge from G to F with weight 1" << endl;
    g.insertEdge("G", "F", 1);
    cout << "Adding edge from D to G with weight 1" << endl;
    g.insertEdge("D", "G", 1);
    cout << "Final graph" << endl;
    cout << g;




    return 0;
}
