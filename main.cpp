//
//  main.cpp
//  Bernadette Veninata
//Implementation of a turing machine which will read the symbol from the tape in the cell currently under the read/write pointer. Then, given the current state of the Turing machine and the value of the symbol read from the tape, write a symbol to the tape in the cell currently under the read/write pointer, change state, and move the read/write pointer to the cell on the left or right of the cell currently under the read/write pointer. The symbol written to the tape, the change of state, and the direction that the read/write pointer is moved is determined by the rule in the action table that corresponds to the current state and the value of the symbol read from the tape.
//

#include <iostream>
#include "DoubleLinkedList.h"
#include "ArrayList.h"
#include <fstream>
#include <string>

using namespace std;

void print(DoubleLinkedList &list);

int main() {
    DoubleLinkedList tape;
    ArrayList actionTable;
    Command tempCommand;
    
    int state;
    char temp;
    bool finish = false;
    int first;
    int pointerPosition;
    
    //input data from the file
    
    ifstream inData;
    inData.open("count.txt");
//    inData.open("subtract.txt");
    if(!inData){
        cout << "File did not open." << endl;
        return 0;
    }
    
    //fill in initial state
    inData >> state;
    cout << "The state is " << state << endl;
    
    //fill the cell values on the tape
    inData >> temp;
    bool firstChar = true;
    while(temp != '\n'){
        if(temp == ' '){
            temp = inData.get();
            continue;
        }
        if(firstChar){
            tape.insertHead(temp);
            firstChar = false;
        }
        else
            tape.insertTail(temp);
        temp = inData.get();
    }
    
    cout << "Tape preview: " << endl;
    tape.resetP();
    tape.iterateRight();
    while(tape.isPSet()){
        cout << tape.read();
        tape.iterateRight();
    }
    cout << endl;
    cout << endl;
    
    //fill the action table
    inData >> first;
    while (first != -1) {
        tempCommand.currentState = first;
        inData >> tempCommand.symbolRead;
        inData >> tempCommand.nextState;
        inData >> tempCommand.symbolWrite;
        inData >> tempCommand.directionMovePointer;
        actionTable.InsertUnsorted(tempCommand);
        inData >> first;
    }

    cout << "Action Table preview (" << actionTable.Length() << " tables):" << endl;
    actionTable.ResetP();
    for(int i=0; i<actionTable.Length()-1; i++){
        actionTable.Iterate();
        tempCommand = actionTable.Read();
        cout << tempCommand.currentState << " ";
        cout << tempCommand.symbolRead << " ";
        cout << tempCommand.nextState << " ";
        cout << tempCommand.symbolWrite << " ";
        cout << tempCommand.directionMovePointer;
        cout << endl;
    }
    cout << endl;

    inData >> pointerPosition;
    cout << "The pointer is on the " << pointerPosition << "th position: " <<  endl;

    tape.resetP();
    tape.iterateRight();
    while(tape.isPSet()){
        cout << tape.read();
        tape.iterateRight();
    }

    cout << endl;

    for(int i = 0; i < pointerPosition-1; i++){
        cout << " ";
    }
    cout << "^" << endl;

    //end input data from the file
    inData.close();

    //setting the proper position of the read/write pointer
    tape.resetP();
    for(int i=0; i<pointerPosition; i++){
        tape.iterateRight();
    }

    //start of turing machine

    while(finish != true){ 
        actionTable.ResetP();
        for(int i = 0; i<actionTable.Length(); i++){ //loop to go through AT
            actionTable.Iterate(); //moce to symbolRead
            tempCommand = actionTable.Read(); //send symbolRead to Command list
            if(tape.read() == tempCommand.symbolRead && state == tempCommand.currentState){
                state = tempCommand.nextState;
                tape.write(tempCommand.symbolWrite);

                //saving the p
                Node* savedP = tape.getP();

                //printing the tape
                tape.resetP();
                tape.iterateRight();
                while(tape.isPSet()){
                    cout << tape.read();
                    tape.iterateRight();
                }
                cout << endl;

                //printing the pointer
                for(int i = 0; i < pointerPosition-1; i++){
                    cout << " ";
                }
                cout << "^" << endl;

                //restoring the p
                tape.setP(savedP);
                if(tempCommand.directionMovePointer == 'L'){
                    tape.iterateLeft();
                    pointerPosition--;
                    break;
                }
                else if(tempCommand.directionMovePointer == 'R'){
                    tape.iterateRight();
                    pointerPosition++;
                    break;
                }
                else if(tempCommand.directionMovePointer == 'H'){
                    cout << "Program halted/finished." << endl;
                    finish = true;
                }
            }
        }
    }
    return 0;
}

bool balanced = true;
cout << "value: ";
char value;
cin  >> value;
while (value != '1'){
    if(value == '{' || value == '(' || value == '['){
        stack.push(value);
    } //{
    //enter another bracket
    else if (value == '}'){
        char current = stack.pop(); //pop top value { off the stack
        //balanced is true
        if(current != '{'){
            balanced = false;
            break;
        }
    }
    else if(value == ')'){
        char current = stack.pop(); //pop top value { off the stack
        //balanced is true
        if(current != '('){
            balanced = false;
            break;
        }
    }
    else if(value == ']'){
        char current = stack.pop(); //pop top value { off the stack
        //balanced is true
        if(current != '['){
            balanced = false;
            break;
        }
    }
    cin >> value;
}

void push(int x){ //linked list
    Node* q = new Node; //declare a new node to be pushed on stack
    q -> data = x; //put data x in node
    q -> next = top; // next value is head
    top = q; //pointer top goes up to q, pointer q is replaced with top
    height++; //height is updated
}
//at the end of the function, anything that is not declared in class the gets deleted ie. q

void push(int x){ //array
    top++;
    a[top]=x;
}

main(){
    Stack stack1;
    Stack stack2;
    stack1 = stack2;
    
}

//operator overloading "=" for a stack: stack1 = stack2
template<class Itemtype> // deep copying
void StackType<ItemType>::operator=(StackType<ItemType>& source){
    //return memory to free store NodeType<ItemType>∗ tempPtr;
    while(topPtr != NULL){ //deleting everything in stack 1 before putting stuff from stack 2 into it
        tempPtr = topPtr; //same as in keynote
        topPtr = topPtr −> next;
        delete tempPtr; //deletes the head in the loop until head = NULL
    }
    
    
    
    //start copying NodeType<ItemType>∗ ptr1; NodeType<ItemType>∗ ptr2;
    if(source.topPtr ==NULL) //source is where we're copying from
        topPtr = NULL; //source is NULL, so set ours to null
    //copying head
    else{ //copy head of source over
        topPtr = new NodeType<ItemType>;
        topPtr−>info = source.topPtr−>info;
        ptr1 = source.topPtr−>next; //dont want to mess up topPtr
        ptr2 = topPtr; // so we make ptr1 and ptr2
    }
    //copy body
    while ( ptr1 != NULL){ //looping through stack 2
        ptr2−>next = new NodeType<ItemType>; //create a new node so its not null
        ptr2 = ptr2−>next;
        ptr2−>info = ptr1−>info ;
        ptr1 = ptr1−>next;
    }
    //copy tail
    ptr2−>next = NULL; //copy the null at the end bc 253
}
