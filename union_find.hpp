//arielsaadon1446@gmail.com


#pragma once

namespace graph{

class unionFind
{
private:
    int *parent;
    int *rank;
    int size;
public:
    unionFind(int n);
    ~unionFind();

    void create();
    int find(int u);
    void unite(int u, int v);
};


}