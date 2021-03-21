//
//  DoubleLinkedList.cpp
//  Bernadette Veninata

#include "DoubleLinkedList.h"


DoubleLinkedList::DoubleLinkedList(){
// this is the constructor
// initializes the list
    p = NULL;
    head = NULL;
    lengthOfList = 0;
}

void DoubleLinkedList::resetP(){
// sets p
    p = NULL;
}

void DoubleLinkedList::iterateRight(){
// sets p to point ot the next node in the list
// always call ResetP prior to the intial call to IterateRight
// always call IsPSet after each call to IterateRight
    if(p == NULL)
       p = head;
    else
       p = p -> next;
}

void DoubleLinkedList::iterateLeft(){
// sets p to point to the previous node in the list
// always call IsPSet prior to each call to IterateLeft
// always call IsPSet after each call to IterateLeft
    p = p -> previous;
}

bool DoubleLinkedList::isPSet(){
// checks whether p points to a node in the list
    if(p == NULL)
        return false;
    return true;
}

Node* DoubleLinkedList::getP(){
// returns the current value of p
    return p;
}

void DoubleLinkedList::setP(Node* q){
// always call IsEmpty prior to calling SetP
// always call IsPSet after each call to SetP
// sets p
    p = head;
    while(p != NULL && q != p)
        p = p -> next;
}

char DoubleLinkedList::read(){
// returns the value of the node pointed to by p
// p must be set prior to calling Read
// always call IsPSet prior to calling Read
    return p -> value;
}

void DoubleLinkedList::write(char x){
// writes a new value into the node pointed to by p
// p must be set prior to calling Write
// always call IsPSet prior to calling Write
// will cause a problem in a sorted list if the key is changed
    p -> value = x;
}

int DoubleLinkedList::length(){
// returns the number of nodes in the list
    return lengthOfList;
}

void DoubleLinkedList::insertHead(char x){
// inserts a new node at the beginning of the list
// always call IsFull prior to calling InsertHead
// sets p
    Node* q = new Node;
    q -> value = x;
    q -> previous = NULL;
    if(head == NULL)
        q -> next = NULL;
    else{
        head -> previous = q;
        q -> next = head;
    }
    head = q;
    p = head;
    lengthOfList++;
}

void DoubleLinkedList::insertTail(char x){
// inserts a new node at the end of the list
// always call IsFull prior to calling InsertTail
// always call IsEmpty prior to calling InsertTail
// p must be set prior to calling InsertTail
// always call IsPSet prior to calling InsertTail
// starts scanning at the node p is pointing to
// scans from left to right
// sets p
    Node* q = new Node;
    q -> value = x;
    q -> next = NULL;
    Node* prevP = p -> previous;
    while(p != NULL){
        prevP = p;
        p = p -> next;
    }
    prevP -> next = q;
    q -> previous = prevP;
    p = q;
    lengthOfList++;
}
