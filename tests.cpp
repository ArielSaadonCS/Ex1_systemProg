//arielsaadon1446@gmail.com


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "graph.hpp"
#include <iostream>

using namespace graph;

bool hasEdge(Graph &g, int from, int to){
    Edge *node = g.getAdjList()[from];
    while (node != nullptr)
    {
        if(node->vertex == to){
            return true;
        }
        node = node->next;
    }
    return false;
}

int countEdges(Graph &g){
    int total = 0;
    int v = g.getVertices();
    for (int i = 0; i < v; i++)
    {
        Edge *node = g.getAdjList()[i];
       while (node!= nullptr)
       {
        total++;
        node = node->next;
       }
       
    }
    return total/2; //undirected graph

}

TEST_CASE("test BFS build correct traversal tree"){
    graph::Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    graph::Algorithms alg(&g);
    graph::Graph bfs_result = alg.bfs(0);

    CHECK_EQ(bfs_result.getVertices(), 5);
    CHECK(hasEdge(bfs_result,0,1));
    CHECK(hasEdge(bfs_result,0,2));
    bool has_3 = hasEdge(bfs_result,1,3) || hasEdge(bfs_result,2,3);
    CHECK(has_3);

    bool has_4 = hasEdge(bfs_result,2,4) || hasEdge(bfs_result,1,4);
    CHECK(has_4);
}

TEST_CASE("test dfs"){
    graph::Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    graph::Algorithms alg(&g);
    graph::Graph dfs_result = alg.dfs();

    CHECK_EQ(dfs_result.getVertices(), 5);

    bool first = hasEdge(dfs_result,0,1) || hasEdge(dfs_result,0,2);
    CHECK(first);

    bool second = hasEdge(dfs_result,1,3) || hasEdge(dfs_result,2,4);
    CHECK(second);

}



TEST_CASE("test prim"){
    graph::Graph g(5);
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,3,3);
    g.addEdge(3,4,1);

    graph::Algorithms alg(&g);
    graph::Graph prim_result = alg.prim();

    CHECK_EQ(prim_result.getVertices(), 5);
    int edgeCount = countEdges(prim_result);
    CHECK_EQ(edgeCount,4);
    CHECK(hasEdge(prim_result,1,2));
    CHECK(hasEdge(prim_result,3,4));
}


TEST_CASE("test kruskal"){
    graph::Graph g(5);
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,3,3);
    g.addEdge(3,4,1);

    graph::Algorithms alg(&g);
    graph::Graph kruskal_result = alg.kruskal();

    CHECK_EQ(kruskal_result.getVertices(), 5);
    int edgeCount = countEdges(kruskal_result);
    CHECK_EQ(edgeCount,4);
    CHECK(hasEdge(kruskal_result,1,2));
    CHECK(hasEdge(kruskal_result,3,4));
}