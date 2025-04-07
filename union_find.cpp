//arielsaadon1446@gmail.com


#include "union_find.hpp"
namespace graph{

unionFind::unionFind(int n){
        size = n;
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        
    }

    unionFind::~unionFind(){
        delete[] parent;
        delete[] rank;
    }

    int unionFind::find(int u){
        if(parent[u] != u){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionFind::unite(int u , int v){

        int root_u = find(u);
        int root_v = find(v);

        if(root_u == root_v){
            return;
        }

        if(rank[root_u] < rank[root_v]){
            parent[root_u] = root_v;
        }
        else if(rank[root_u] > rank[root_v]){
            parent[root_v] = root_u;
        }
        else{
            parent[root_v] = root_u;
            rank[root_u]++;
        }



    }


}



