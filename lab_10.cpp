#include <iostream>
#include "d_graph.h"
#include "d_util.h"
#include <list>
#include <set>
#include <fstream>
using namespace std;

int main()
{

    graph<string> g;
    ifstream data;
    data.open("graphB.dat");
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
    cout << "Performing BFS on graph g\n";
    set<string> s;
    s = bfs(g, "A");
    writeContainer(s.begin(), s.end(), " ");
    cout << endl;
    list<string> l;
    cout << "Performing DFS on graph g\n";
    dfs(g, l);
    writeContainer(l.begin(), l.end(), " ");
    cout << endl;
    cout << "Please enter a vertex to add to the graph\n";
    string ver;
    cin >> ver;
    g.insertVertex(ver);
    cout << "Performing BFS on graph from new vertex to display set of reachable vertices\n";
    s = bfs(g, ver);
    writeContainer(s.begin(), s.end(), " ");
    cout << endl;
    cout << "Performing DFS on new graph giving vertices in reverse order of their finishing times\n";
    dfs(g, l);
    writeContainer(l.begin(), l.end(), " ");







    return 0;
}
