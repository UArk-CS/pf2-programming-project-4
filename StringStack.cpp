//
// Created by Ben Worthington on 3/15/21.
//

#include "StringStack.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
StringStack::StringStack()
{
    Head = NULL;
    Length = 0;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
StringStack::StringStack(const StringStack & stack)
{
    // Create first node
    StackNode *copy = new StackNode();
    Head = copy;

    // Walk list to copy nodes
    StackNode *ptr = stack.Head;
    while (ptr != NULL)
    {
        copy->Next = new StackNode();
        copy = copy->Next;
        copy->Number = ptr->Number;
        copy->Next = NULL;
        ptr = ptr->Next;
    }

    // Tidy first node
    copy = Head;
    Head = copy->Next;
    delete copy;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
StringStack::~StringStack()
{
    // Walk stack deleting data
    while (Head != NULL)
    {
        StackNode *Temp = Head;
        Head = Head->Next;
        delete Temp;
    }

    // Reset head
    Head = NULL;
    Length = 0;
}

//-----------------------------------------------------------
// Check to see if stack is full.
//-----------------------------------------------------------
bool StringStack::IsFull()
{
    return (false);
}

//-----------------------------------------------------------
// Check to see if stack is empty.
//-----------------------------------------------------------
bool StringStack::IsEmpty()
{
    return (Length == 0);
}

//-----------------------------------------------------------
// Push data into the stack.
//-----------------------------------------------------------
void StringStack::Push(int Number)
{
    // Check for full stack
    if (IsFull())
        return;

    // Allocate space for data
    StackNode *Temp = new StackNode;
    if (Temp == NULL)
        return;

    // Insert data at head of list
    Temp->Number = Number;
    Temp->Next = Head;
    Head = Temp;
    Length++;
}

//-----------------------------------------------------------
// Pop data from the stack.
//-----------------------------------------------------------
void StringStack::Pop(int &Number)
{
    // Check for empty stack
    if (IsEmpty())
        return;

    // Extract information from node
    Number = Head->Number;

    // Pop item from linked list
    StackNode *Temp = Head;
    Head = Head->Next;
    delete Temp;
    Length--;
}

//-----------------------------------------------------------
// Return data from top of stack.
//-----------------------------------------------------------
void StringStack::Top(int &Number)
{
    // Check for empty stack
    if (IsEmpty())
        return;

    // Return information from node
    Number = Head->Number;
}

//-----------------------------------------------------------
// Return the number of elements in stack.
//-----------------------------------------------------------
int StringStack::GetLength()
{
    return Length;
}

//-----------------------------------------------------------
// Print all records in the stack.
//-----------------------------------------------------------
void StringStack::Print()
{
    // Walk the stack printing data
    cout << "stack: ";
    StackNode *Temp = Head;
    while (Temp != NULL)
    {
        cout << Temp->Number << " ";
        Temp = Temp->Next;
    }
    cout << endl;
}