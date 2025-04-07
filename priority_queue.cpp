//arielsaadon1446@gmail.com


#include "priority_queue.hpp"
#include <iostream>
#include <stdexcept>

namespace graph{

PriorityQueue::PriorityQueue(int cap) {
    heap = new int[cap];
    capacity = cap;
    size = 0;
}

PriorityQueue::~PriorityQueue() {
    delete[] heap;
}

void PriorityQueue::swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void PriorityQueue::heapifyUp(int index, int* dist) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (dist[heap[index]] < dist[heap[parent]]) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void PriorityQueue::heapifyDown(int index, int* dist) {
    int leftChild, rightChild, smallest;
    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        smallest = index;

        if (leftChild < size && dist[heap[leftChild]] < dist[heap[smallest]]) {
            smallest = leftChild;
        }

        if (rightChild < size && dist[heap[rightChild]] < dist[heap[smallest]]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void PriorityQueue::enqueue(int val, int* dist) {
    if (size == capacity) {
        throw std::overflow_error("Queue is full");
    }
    heap[size] = val;
    size++;
    heapifyUp(size - 1, dist);
}

int PriorityQueue::dequeue(int* dist) {
    if (size == 0) {
        throw std::underflow_error("Queue is empty");
    }
    int min_value = heap[0];
    heap[0] = heap[size - 1];
    size--;
    if (size > 0) {
        heapifyDown(0, dist);
    }
    return min_value;
}

bool PriorityQueue::is_empty() {
    return size == 0;
}

bool PriorityQueue::contains(int index) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == index) {
            return true;
        }
    }
    return false;
}

int PriorityQueue::extract_min(int* dist, bool* visited, int vertices) {
    int min_value = __INT_MAX__;
    int min_index = -1;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && dist[i] < min_value) {
            min_value = dist[i];
            min_index = i;
        }
    }

    return min_index;
}


}