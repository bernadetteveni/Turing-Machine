//
//  ArrayList.cpp
//  Bernadette Veninata

#include "ArrayList.h"

ArrayList::ArrayList(){
    length  = 0;
    p = -1;
}

void ArrayList::ResetP(){
    p = -1;
}

int ArrayList::Iterate(){
    return p++;
}

void ArrayList::SetP(Command q){
    a[p].currentState=q.currentState;
    a[p].symbolRead=q.currentState;
    a[p].nextState=q.currentState;
    a[p].symbolWrite=q.currentState;
    a[p].directionMovePointer=q.currentState;

}

Command ArrayList::Read(){
    return a[p];
}

void ArrayList::Write(Command x){
    a[p] = x;
}

int ArrayList::Length(){
    return length;
}

void ArrayList::InsertUnsorted(Command x){
    p = length;
    a[p] = x;
    length++;
}
