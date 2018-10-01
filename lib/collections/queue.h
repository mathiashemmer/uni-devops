#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
struct Node{
    T Data;
    struct Node *nextE;
};
template<typename T>
struct Queue{
    Node<T> * frontNode;
    Node<T> * endNode;
    int size;
};

template<typename T>
bool Queue_Start(Queue<T> &queue){
    queue.frontNode = queue.endNode = nullptr;
    queue.size = 0;
    return true;
}

template<typename T>
bool Queue_isEmpty(Queue<T> queue){
    return queue.size == 0;
}

template<typename T>
int Queue_Size(Queue<T> queue){
    return queue.size;
}

template<typename T>
bool Queue_Insert(Queue<T> &queue, T Data){
    Node<T> *newNode = new Node<T>;

    newNode->Data = Data;
    newNode->nextE = nullptr;

    if(queue.frontNode == nullptr)
        queue.frontNode = newNode;
    else{
        queue.endNode->nextE = newNode;
    }
    queue.endNode = newNode;
    queue.size++;
    return true;
}

template<typename T>
bool Queue_Pop(Queue<T> &queue, T &container){
    if(queue.frontNode == nullptr)
        return false;

    container = queue.frontNode->Data;
    Node<T> * temp = queue.frontNode;
    queue.frontNode = queue.frontNode->nextE;
    delete temp;
    queue.size--;
    if(queue.size == 0)
        queue.endNode = nullptr;
    return true;
}

template <typename T>
bool Queue_Peek(Queue<T> queue, T &container){
    if(queue.size >0){
        container = queue.frontNode->Data;
        return true;
    }
    return false;
}
#endif // QUEUE_H
