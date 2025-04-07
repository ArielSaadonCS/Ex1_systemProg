//arielsaadon1446@gmail.com


#pragma once

namespace graph{


class PriorityQueue{
    private:
    int *heap;
    int capacity;
    int size;

    void heapifyUp(int index, int *dist);
    void heapifyDown(int index, int *dist);
    int parent(int i);
    int left(int i);
    int right(int i);

    public:
    PriorityQueue(int capacity);
    ~PriorityQueue();
    void enqueue(int val, int*dist);
    int dequeue(int *dist);
    bool is_empty();
    bool contains(int index);
    int extract_min(int *dist, bool *visited, int vertices);
    void swap(int &a, int &b);
};

}