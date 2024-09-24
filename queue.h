#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include "./node.h"

using std::string;

class Queue {
    private:
        Node *First;
        Node *Last;
        int Size;

    public:
        Queue();
        ~Queue();
        int GetSize();
        void Enqueue(int data);
        int Dequeue();
        bool IsEmpty();
};

#endif
