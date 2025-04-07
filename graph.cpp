//arielsaadon1446@gmail.com


#include "graph.hpp"
#include <iostream>

namespace graph{
    
    Edge::Edge(int v, Edge *n, int w){
        vertex = v;
        next = n;
        weight = w;
    }

    Edge::~Edge(){}

    Graph::Graph(int v){
        vertices = v;
        adjList = new Edge*[vertices];
        for(int i = 0; i < vertices; i++){
            adjList[i] = nullptr;
        }
    }
    Graph::~Graph(){
        for(int i = 0; i < vertices; i++){
            Edge * current = adjList[i];
            while (current)
            {
                Edge *temp = current;
                current = current -> next;
                delete temp;
            }
            
        }
        delete[] adjList;
    }

    void Graph::addEdge(int u, int v, int weight){
    if(u < 0 || u >= vertices || v < 0 || v >= vertices ){
        std:: cout << "invalid vertx index";
        return;
    }

        adjList[u] = new Edge(v,adjList[u],weight);
        adjList[v] = new Edge(u,adjList[v],weight);
    }

    void Graph::removeEdge(int u , int v){

    if(u < 0 || u >= vertices || v < 0 || v >= vertices ){
        std:: cout << "invalid vertex index";
        return;
    }
    //undirected- from u to v
    Edge *curr = adjList[u];
    Edge *prev = nullptr;
    while (curr != nullptr && curr->vertex != v)
    {
     prev = curr;
     curr = curr->next;   
    }

    if(curr != nullptr){ //found the edge
        if(prev == nullptr){
            adjList[u] = curr->next;
        }
        else{
            prev->next = curr->next;
        }
        delete curr;
    }
    //undirected- from v to u
    curr = adjList[v];
    prev = nullptr;
    while (curr != nullptr && curr->vertex != u)
    {
     prev = curr;
     curr = curr->next;   
    }

    if(curr != nullptr){ //found the edge
        if(prev == nullptr){
            adjList[v] = curr->next;
        }
        else{
            prev->next = curr->next;
        }
        delete curr;
    }
    

    }

    void Graph::print_graph(){
        
        for(int i = 0; i < vertices; i++){
            std:: cout << "Adjacency list of vertex " << i <<":";
            Edge *curr = adjList[i];
            while (curr != nullptr)
            {
                std:: cout << "-> " << curr->vertex << "(" << curr->weight << ")";
                curr = curr->next;
            }
            std::cout << std::endl;
        }


    }

    int Graph::getVertices(){
        return vertices;
    }

    Edge** Graph::getAdjList(){
        return adjList;
    }

}