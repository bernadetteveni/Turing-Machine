//
//  DoubleLinkedList.h
//  Bernadette Veninata
//
// The tape declared as a variable of a doubly-linked list type defined as a C++ class "DoubleLinkedList", where each node corresponds to one cell on the tape.

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include <stdio.h>
#include <iostream>

using namespace std;

struct Node{
    char value;
    Node* next;
    Node* previous;
};

class DoubleLinkedList{
private:
    Node* head;
    Node* p;
    Node* q;
    int lengthOfList;
    
public:
    DoubleLinkedList();
    void resetP();
    void iterateRight();
    void iterateLeft();
    bool isPSet();
    Node* getP();
    void setP(Node* q);
    char read();
    void write(char x);
    int length();
    void insertHead(char x);
    void insertTail(char x);
};

#endif /* DoubleLinkedList.h */
