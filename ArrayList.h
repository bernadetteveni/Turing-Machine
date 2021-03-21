//
//  ArrayList.h
//  Bernadette Veninata
//
// The action table declared as a variable of an array-based list type defined as a C++ class "ArrayList", where each item corresponds to a struct "Command" consisting of five members corresponding to: (1) the current state, (2) the symbol read from the tape, (3) the next state, (4) the symbol to be written to the tape, and (5) the direction to move the read/write pointer, respectively.

#ifndef ArrayList_h
#define ArrayList_h

#include <stdio.h>
#include <iostream>

using namespace std;

struct Command{
    int currentState;
    int nextState;
    char symbolRead; //'B' is blank
    char symbolWrite; //'B' is blank
    char directionMovePointer; //L R - H (hold)
};

const int MAX_LENGTH = 100;

class ArrayList
{
public:
    // Purpose: Initializes the list.
    // Parameter(s): N/A
    // Precondition(s): N/A
    // Returns: N/A
    ArrayList();
    
    // Purpose: Sets p.
    // Parameter(s): N/A
    // Precondition(s): N/A
    // Returns: N/A
    void ResetP();
    
    // Purpose: Sets p to point to the next element in the list.
    // Parameter(s): N/A
    // Precondition(s): ResetP is called prior to the initial call to Iterate.
    // Postcondition(s): IsPSet is called after each call to Iterate.
    // Returns: The next element in the list.
    int Iterate();
    
    // Purpose: Sets p (to q).
    // Parameter(s):
    //  <1> Command q: reference to a pointer q.
    // Precondition(s): N/A
    // Postcondition(s): IsPSet is called after each call to SetP.
    // Returns: N/A.
    void SetP(Command q);
    
    // Purpose: Returns the value of the element pointed to by p.
    // Parameter(s): N/A
    // Precondition(s): Call IsPSet prior to calling Read.
    // Returns: Integer value pointed to by p.
    Command Read();
    
    // Purpose: Writes a new value into the element pointed to by p.
    // Parameter(s):
    //  <1> Command x: New value pointed to by p.
    // Precondition(s): Call IsPSet prior to calling Write.
    // Returns: N/A
    void Write(Command x);
    
    // Purpose: Returns the length of the list.
    // Parameter(s): N/A
    // Precondition(s): N/A
    // Returns: Integer of number of elements in the list.
    int Length();
    
    // Purpose: Inserts a new element at the end of the list.
    // Parameter(s):
    //  <1> Command x: New element pointed to by p, where p is at the end (length) of the list.
    // Precondition(s): Call IsFull prior to calling InsertUnsorted.
    // Returns: N/A
    void InsertUnsorted(Command x);
    
private:
    int p;
    int length;
    Command a[MAX_LENGTH];
};

#endif /* ArrayList */


