//arielsaadon1446@gmail.com


#ifndef QUEUE_HPP
#define QUEUE_HPP
namespace graph{

class Queue{
    private:
    int *data;
    int front;
    int rear;
    int capacity;
    int size;

    public:
    Queue(int cap);
    ~Queue();
    void enqueue(int val);
    int dequeue();
    bool is_empty();
};
}

#endif