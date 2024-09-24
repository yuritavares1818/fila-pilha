#include <iostream>
#include "./stack.h"

using std::cout;
using std::endl;

Stack::Stack() {
    this->Size = 0;
    this->Top = nullptr;
}

Stack::~Stack() {
    while (!this->IsEmpty()) this->Pop();
}

void Stack::Push(int item) {
    Node* node = new Node();
    node->next = nullptr;
    node->item = item;
    this->Size++;

    if (this->IsEmpty()) {
        this->Top = node;
        return;
    }

    node->next = this->Top;
    this->Top = node;
}

int Stack::Pop() {
    if (this->IsEmpty()) return 0;

    Node* node = this->Top;
    this->Top = node->next;
    int item = node->item;
    delete node;
    this->Size--;
    return item;
}

int Stack::GetSize() {
    return this->Size;
}

bool Stack::IsEmpty() {
    return this->Top == nullptr;
}

void Stack::List() {
    if (this->IsEmpty()) {
        cout << "Pilha Vazia" << endl;
        return;
    }

    Node* node;

    for (node = this->Top; node->next != nullptr; node = node->next) {
        cout << node->item << " < ";
    }
    
    cout << node->item << endl;
}
