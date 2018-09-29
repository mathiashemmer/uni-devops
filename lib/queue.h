#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
struct Node{
    T Data;
    Node<T> *next;
    Node<T> *prev;
};
template<typename T>
struct Queue{
    Node<T> *head;
    Node<T> *tail;
    int size;
};

template<typename T>
bool Queue_Start(Queue<T> &queue){
    queue.head = queue.tail = nullptr;
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
    newNode->next = nullptr;

    if(queue.head == nullptr)
        queue.head = newNode;
    else{
        queue.tail->next = newNode;
    }
    queue.tail = newNode;
    queue.size++;
    return true;
}

template<typename T>
bool Queue_Pop(Queue<T> &queue, T &container){
    if(queue.head == nullptr)
        return false;

    container = queue.head->Data;
    Node<T> * temp = queue.head;
    queue.head = queue.head->next;
    delete temp;
    queue.size--;
    if(queue.size == 0)
        queue.tail = nullptr;
    return true;
}

template <typename T>
bool Queue_Peek(Queue<T> queue, T &container){
    if(queue.size >0){
        container = queue.head->Data;
        return true;
    }
    return false;
}

#endif // QUEUE_H
