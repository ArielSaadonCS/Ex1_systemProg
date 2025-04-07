//arielsaadon1446@gmail.com


#include "queue.hpp"
#include <iostream>
namespace graph{


Queue::Queue(int cap){
    data = new int[cap];
    capacity = cap;
    size = 0;
    front = 0;
    rear = -1;
}
Queue::~Queue(){
    delete[] data;
}

void Queue::enqueue(int val){
    if (size == capacity) {
        throw std::overflow_error("Queue is full");
    }
    rear = (rear + 1)%capacity;
    data[rear] = val;
    size++;
}

int Queue::dequeue(){
    if (size == 0) {
        throw std::overflow_error("Queue is empty");
    }
    int value = data[front];
    front = (front + 1)%capacity;
    size--;
    return value;
}

bool Queue::is_empty(){
    return size == 0;
}

}