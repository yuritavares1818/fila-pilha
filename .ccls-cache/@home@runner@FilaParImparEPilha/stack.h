#ifndef STACK_H
#define STACK_H

#include "./node.h"

class Stack {
    private:
        Node *Top;
        int Size;

    public:
        Stack();
        ~Stack();
        void Push(int item);
        int Pop();
        int GetSize();
        bool IsEmpty();
        void List();
};

#endif
