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
    cout << "Please enter a vertex from the above graph ";
    string v;
    cin >> v;
    list<string> path;
    list<string> testpath;
    int pathsize;
    pathsize = minimumPath(g, "A", v, path);
    string pathvertex = "A";
    if(pathsize < minimumPath(g, "B", v, testpath)){
        pathsize = minimumPath(g, "B", v, path);
        pathvertex = "B";
    }
    if(pathsize < minimumPath(g, "C", v, testpath)){
        pathsize = minimumPath(g, "C", v, path);
        pathvertex = "C";
    }
    if(pathsize < minimumPath(g, "D", v, testpath)){
        pathsize = minimumPath(g, "D", v, path);
        pathvertex = "D";
    }
    if(pathsize < minimumPath(g, "E", v, testpath)){
        pathsize = minimumPath(g, "E", v, path);
        pathvertex = "E";
    }
    if(pathsize < minimumPath(g, "F", v, testpath)){
        pathsize = minimumPath(g, "F", v, path);
        pathvertex = "F";
    }
    cout << "Vertex with largest minimum-path value: " << pathvertex << endl;
    cout << "Minimum path value: " << pathsize << endl;
    cout << "Minimum path is ";
    list<string>::iterator iter;
    for(iter = path.begin(); iter != path.end(); iter++){
        cout << *iter << " ";
    }







    return 0;
}
