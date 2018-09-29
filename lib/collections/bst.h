#ifndef BST_H
#define BST_H
#include <iostream>
/* ARVORE DE BUSCA BINARIA - BINARY SEARCH TREE [BST]
 * Variante de conjunto/agrupamento de dados.
 * +-LISTA DE PALAVRAS-+
 * Galho: Nó da lista, contem referência aos dados e outros galhos
 * Raiz: Nó/galho que contem referência preenchida para outros galhos
 * Data: Dados do usuário
 * Folha: Galho cujo não possui outros galhos referenciados a baixo
 * ---------------------
 * Cada galho contem referência para dois próximos galhos, e a Data
 * do usuário. A inserção de novos galhos é dada pela regra:
 * O galho da esquerda sempre será um valor menor que sua raiz
 * O galho da direita sempre será um valor maior que sua raiz
*/
template <typename T>
struct Node{
    T Data;
    int key;
    Node *leftNode;
    Node *rightNode;
};

template <typename T>
struct BST{
    Node<T> *root;
    int size;
};

template<typename T>
Node<T> * CreateNode(T Data){
    Node<T> *newNode = new Node<T>;
    newNode->key = rand() % 9999;
    newNode->Data = Data;
    newNode->leftNode = nullptr;
    newNode->rightNode = nullptr;
    return newNode;
}

template <typename T>
bool BST_Init(BST<T> &tree){
    tree.root = nullptr;
    tree.size = 0;
    return true;
}

template <typename T>
bool InsertNode(Node<T> *&node, T data){
    if(node == nullptr){
        Node<T> *newNode = CreateNode(data);
        node = newNode;
        return true;
    }else{
        if(data > node->Data)
            return InsertNode(node->rightNode, data);
        else
            return InsertNode(node->leftNode, data);
    }
}

template <typename T>
bool BST_Insert(BST<T> &tree, T data){
    if(InsertNode(tree.root, data)){
        tree.size++;
        return true;
    }
    return false;
}

template <typename T>
bool RemoveNode(Node<T> *&root){
    Node<T> *toRemove;
    Node<T> *greaterNode = root->leftNode;
    if(greaterNode == nullptr){
        toRemove = root;
        root = root->rightNode;
        delete toRemove;
        return true;
    }
    Node<T> *father = nullptr;
    while(greaterNode->rightNode != nullptr){
        father = greaterNode;
        greaterNode = greaterNode->rightNode;
    }
    greaterNode->rightNode = root->rightNode;
    if(father != nullptr){
        father->rightNode = greaterNode->leftNode;
        greaterNode->leftNode = root->leftNode;
    }
    toRemove = root;
    root = greaterNode;
    delete  toRemove;
    return true;
}

template <typename T>
bool BST_Remove(BST<T> &tree, int key){
    Node<T> *toRemove = tree.root;
    while(toRemove->key != key && toRemove != nullptr){
        if(key > toRemove) toRemove = toRemove->rightNode;
        else toRemove = toRemove->leftNode;
    }
    if(toRemove != nullptr){
        RemoveNode(toRemove);
        tree.size--;
        return true;
    }
    return false;
}

template <typename T>
T BST_Search(BST<T> tree, int key){
    Node<T> *currentNode = tree.root;
    while(currentNode != nullptr && key != currentNode->Data){
        if(currentNode->Data < key){
            currentNode = currentNode->rightNode;
        }else{
            currentNode = currentNode->leftNode;
        }
    }
    if(currentNode != nullptr)
        return currentNode->Data;
}

#endif // BST_H
