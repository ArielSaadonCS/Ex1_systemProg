//arielsaadon1446@gmail.com

#include "graph.hpp"
#include <iostream>

using namespace std;
using namespace graph;

int main() {
    try {
        // Create a graph
        Graph g(5);
        g.addEdge(0, 1, 2);
        g.addEdge(0, 3, 6);
        g.addEdge(1, 2, 3);
        g.addEdge(1, 3, 8);
        g.addEdge(1, 4, 5);
        g.addEdge(2, 4, 7);
        g.addEdge(3, 4, 9);

        cout << "Original Graph:" << endl;
        g.print_graph(); 

        // Create algorithms object
        Algorithms algos(&g);

        // BFS
        cout << "\nBFS from vertex 0:" << endl;
        Graph bfsTree = algos.bfs(0);
        bfsTree.print_graph();

        // DFS
        cout << "\nDFS Forest:" << endl;
        Graph dfsForest = algos.dfs();
        dfsForest.print_graph();

        // Dijkstra
        cout << "\nDijkstra from vertex 0:" << endl;
        Graph dijkstraTree = algos.dijkstra(0);
        dijkstraTree.print_graph();

        // Prim
        cout << "\nPrim's MST:" << endl;
        Graph primTree = algos.prim();
        primTree.print_graph();

        // Kruskal
        cout << "\nKruskal's MST:" << endl;
        Graph kruskalTree = algos.kruskal();
        kruskalTree.print_graph();

    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

