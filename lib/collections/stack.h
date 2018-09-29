#ifndef STACK_H
#define STACK_H

template <typename T>
struct Node{
    T Data;
    struct Node *nextE;
};
template<typename T>
struct Stack{
    Node<T> * frontNode;
    int size;
};
template<typename T>
bool Stack_Start(Stack<T> &stack){
    stack.frontNode = nullptr;
    stack.size = 0;
    return true;
}

template <typename T>
bool Stack_IsEmpty(Stack<T> stack){
    return stack.size == 0;
}

template <typename T>
bool Stack_Size(Stack<T> stack){
    return stack.size;
}

template<typename T>
bool Stack_Insert(Stack<T> &stack, T &Data){
    Node<T> *newNode = new Node<T>;
    newNode->Data = Data;
    newNode->nextE = stack.frontNode;
    stack.frontNode = newNode;
    stack.size++;
    return true;
}

template<typename T>
bool Stack_Pop(Stack<T> &stack, T &container){
    if(stack.frontNode == nullptr)
        return false;
    container = stack.frontNode->Data;
    Node<T> *oldNode = stack.frontNode;
    stack.frontNode = stack.frontNode->nextE;
    delete oldNode;
    stack.size--;
    return true;
}

#endif // STACK_H
