//arielsaadon1446@gmail.com

#include "graph.hpp"
#include "queue.hpp"
#include "priority_queue.hpp"
#include "union_find.hpp"
#include <iostream>

namespace graph{

Algorithms::Algorithms(Graph *g){
    graph = g;
}

Graph Algorithms::bfs(int start){
    int vertices = graph->getVertices();
    Edge** adjList = graph->getAdjList();

    if(start < 0 || start >= vertices){
        throw std::invalid_argument("invalid start vertex");
    }

    bool *visited = new bool[vertices](); //set all to false = unvisited
    Queue queue(vertices);
    Graph bfsGraph(vertices);

    visited[start] = true;
    queue.enqueue(start);

    while(!queue.is_empty()){
        int node = queue.dequeue();

        Edge *current = adjList[node];
        while(current != nullptr){
            int v =current->vertex;
            int w = current->weight;
            if(!visited[v]){
                
                visited[v] = true;
                queue.enqueue(v);

                bfsGraph.addEdge(node,v,w);
            }
            current = current->next;
        }

    }
    delete[] visited;
    return bfsGraph;
}

void dfs_visit(int vertex, Edge **adjList, bool *visited, Graph *dfsTree){
    visited[vertex] = true;
    Edge *edge = adjList[vertex];

    while (edge != nullptr)
    {
        if(!visited[edge->vertex]){
            dfsTree->addEdge(vertex, edge->vertex, edge->weight);
            dfs_visit(edge->vertex,adjList,visited,dfsTree);
        }
        edge = edge->next;
    }
    
}

Graph Algorithms::dfs(){
    int vertices = graph->getVertices();
    Edge** adjList = graph->getAdjList();
    bool *visited = new bool[vertices]();
    Graph dfsForest(vertices);
    
    for(int i = 0; i < vertices; i++){
        if(!visited[i]){
            dfs_visit(i, adjList, visited, &dfsForest);
        }
    }

    delete[] visited;

    return dfsForest;

}


void relax(int u , int v , int weight,int *dist, int *pie){
    if(dist[u] != __INT_MAX__ && dist[v] > dist[u] +weight ){
        dist[v] = dist[u]+ weight;
        pie[v] = u;
    }
}
    


Graph Algorithms::dijkstra(int start){
    int vertices = graph->getVertices();
    Edge** adjList = graph->getAdjList();

    for(int i = 0; i < vertices; i++){
        Edge *temp = adjList[i];
        while(temp){
         if(temp->weight < 0){
            throw std::invalid_argument("can't calculate edges with negative weight");
        } 
        temp = temp->next;
    }

    }

    PriorityQueue p_queue(vertices);
    int *dist = new int[vertices]; //for distance between vertices
    int *pie = new int[vertices]; // for knowing who's before the current vertex
    bool *visited = new bool[vertices]();

    for(int i =0 ; i < vertices; i++){//initilaizing
        dist[i] = __INT_MAX__;
        pie[i] = -1;
   
    } 

    dist[start] = 0;
    p_queue.enqueue(start,dist);
    
    while (!p_queue.is_empty())
    {
        int u = p_queue.extract_min(dist,visited,vertices);
        if(u == -1) break;
        if(visited[u]) continue;
        visited[u] = true;
        Edge *curr= adjList[u];
        
        while (curr!=nullptr)
        {
            int v = curr->vertex;
            int weight = curr->weight;

            if(!visited[v] && dist[v] > dist[u] + weight){
                dist[v] = dist[u]+weight;
                pie[v] = u;
                p_queue.enqueue(v,dist);
            }
            curr = curr->next;
        }
    }

    Graph shortestPathTree(vertices);
    for(int i = 0; i < vertices; i++){
     if (pie[i] != -1){
         shortestPathTree.addEdge(pie[i],i,dist[i] - dist[pie[i]]);
     }
     
    }
    
    delete[] visited;
    delete[] pie;
    delete[] dist;

    return shortestPathTree;

}

Graph Algorithms::prim(){
    int vertices = graph->getVertices();
    Edge** adjList = graph->getAdjList();
    int *dist = new int[vertices];
    int *pie = new int[vertices];
    bool *visited = new bool[vertices]();
    PriorityQueue p_queue(vertices);

    for(int i =0 ; i < vertices; i++){//initilaizing
        dist[i] = __INT_MAX__;
        pie[i] = -1;
    } 

    dist[0] = 0; // randomly chosen
    p_queue.enqueue(0,dist);

    Graph mst(vertices);

    while (!p_queue.is_empty()) {
        int u = p_queue.dequeue(dist);
        if(visited[u]){continue;}
        visited[u] = true;

        Edge *curr = adjList[u];

        while (curr != nullptr) {
            int v = curr->vertex;
            int weight = curr->weight;
            if(!visited[v] && weight < dist[v]){
                dist[v] = weight;
                pie[v] = u;
                p_queue.enqueue(v,dist);
            }
            curr = curr->next;
        
        }
        

    }

    for (int i = 0; i < vertices; i++){
        if (pie[i] != -1) {
            mst.addEdge(pie[i], i , dist[i]);
        }
        
    }
    delete[] dist;
    delete[] pie;
    delete[] visited;

    return mst;
}

Graph Algorithms::kruskal(){
    int vertices = graph->getVertices();
    Edge** adjList = graph->getAdjList();

    int edgeCount = 0;

    for (int i = 0; i < vertices; i++) // for avoiding duplicate
    {
        Edge *curr = adjList[i];
        while(curr != nullptr ){
            if(i < curr->vertex){
                edgeCount++;
               
            }
            curr = curr->next;
        }
    }
    
    struct simpleEdge{
        int u, v, weight;
    };

    simpleEdge *edges = new simpleEdge[edgeCount];
    int index = 0;
    for (int u = 0; u < vertices; u++)
    {
        Edge *curr = adjList[u];
        while (curr != nullptr) {
        
            int v = curr-> vertex;
            if(u<v){
                edges[index].u = u;
                edges[index].v = v;
                edges[index].weight = curr->weight;
                index++;
            }
            curr= curr->next;

        }
        
    }
    
    for (int i = 0; i < edgeCount-1; i++) // sorting
    {
        for (int j = 0; j < edgeCount-i-1; j++)
        {
            if(edges[j].weight > edges[j+1].weight){
                simpleEdge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1]= temp;
            }

        }
        
    }

    unionFind uf(vertices);
    Graph mst(vertices);

    for (int i = 0; i < edgeCount; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if(uf.find(u) != uf.find(v)){
            uf.unite(u,v);
            mst.addEdge(u,v,weight);
        }
    }

    delete[] edges;
    return mst;  

    }
}

