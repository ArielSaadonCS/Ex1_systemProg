//arielsaadon1446@gmail.com


#pragma once


namespace graph{

    class Edge{
     public:
         int vertex;
         int weight;
         Edge *next;
            Edge(int vertex, Edge *next = nullptr, int weight=1);
            ~Edge();
         };
    
    class Graph{
        private:
        int vertices;
        Edge** adjList;
    
        public:
        Graph(int v);
        ~Graph();
        void addEdge(int u, int v, int weight =1);
        void removeEdge(int u , int v);
        void print_graph();
        int getVertices();
        Edge** getAdjList();
    };

    class Algorithms{
        private:
        Graph *graph;
        public:
        Algorithms(Graph *g);
        Graph bfs(int start);
        Graph dfs();
        Graph dijkstra(int start);
        Graph prim();
        Graph kruskal();
    };
    
    }