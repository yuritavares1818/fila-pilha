/*
 * Rodar com `g++ main.cpp` no shell e rodar a.out
 */

#include <iostream>
#include "queue.cpp"
#include "stack.cpp"

using std::cout;
using std::cin;
using std::endl;

void show_separator();
void manager_stack(int number, Stack* stack);

int main() {
    int number = 0;

    Queue *oddQueue = new Queue();
    Queue *evenQueue = new Queue();

    Stack *stack = new Stack();

    do {
        show_separator();
        cout << "Digite o valor (0 encerra insercao): ";
        cin >> number;

        if (number != 0 && number % 2 == 0) {
            evenQueue->Enqueue(number);
            cout << "Adicionado " << number << " na fila par" << endl;
        }
        if (number % 2 == 1) {
            oddQueue->Enqueue(number);
            cout << "Adicionado " << number << " na fila impar" << endl;
        }
    } while (number != 0);

    while (!(oddQueue->IsEmpty() && evenQueue->IsEmpty())) {
        show_separator();
        if (!oddQueue->IsEmpty()) {
            number = oddQueue->Dequeue();
            manager_stack(number, stack);
        }

        if (!evenQueue->IsEmpty()) {
            number = evenQueue->Dequeue();
            manager_stack(number, stack);
        }
    }

    show_separator();
    cout << "Ambas filas vazias!" << endl;

    if (stack->IsEmpty()) cout << "Pilha finalizou vazia!" << endl;
    else {
        cout << "Elementos sobrados na pilha abaixo" << endl;
        stack->List();
    }

    delete evenQueue;
    delete oddQueue;
    delete stack;

    return 0;
}

void manager_stack(int number, Stack* stack) {
    if (number > 0) {
        stack->Push(number);
        cout << "Adicionado " << number << " na pilha" << endl;
        return;
    }

    cout << "Numero " << number << " tentando remover elemento da pilha" << endl;

    if (stack->IsEmpty()) {
        cout << "Pilha vazia, nenhum elemento para remover" << endl;
        return;
    }

    int stackNumber = stack->Pop();

    cout << "Removido " << stackNumber << " da pilha" << endl;
}

void show_separator() {
    cout << "========================================" << endl;
}
