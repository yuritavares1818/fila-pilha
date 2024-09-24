#include <iostream>
#include "./queue.h"

Queue::Queue() {
    this->First = nullptr;
    this->First = nullptr;
}

Queue::~Queue() {
    while (!this->IsEmpty()) this->Dequeue();
}

int Queue::GetSize() {
    return this->Size;
}

void Queue::Enqueue(int item) {
    Node* node = new Node();
    node->item = item;
    node->next = nullptr;

    this->Size++;

    if (this->First == nullptr) {
        this->First = node;
        this->Last = node;
        return;
    }

    this->Last->next = node;
    this->Last = node;
}

int Queue::Dequeue() {
    if (this->First == nullptr) return 0;

    Node* node = this->First;
    this->First = this->First->next;

    int item = node->item;
    delete node;

    this->Size--;

    return item;
}

bool Queue::IsEmpty() {
    return this->First == nullptr;
}
