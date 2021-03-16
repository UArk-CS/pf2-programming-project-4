//
// Created by Ben Worthington on 3/15/21.
//

#ifndef PF2_PROGRAMMING_PROJECT_4_STRINGSTACK_H
#define PF2_PROGRAMMING_PROJECT_4_STRINGSTACK_H

#include <cmath>
#include <iostream>
using namespace std;

struct StackNode
{
    int Number;
    StackNode *Next;
};

class StringStack {
public:
    // Constructors
    StringStack();
    StringStack(const StringStack & stack);
    ~StringStack();

    // Methods
    bool IsFull();
    bool IsEmpty();
    void Push(int Number);
    void Pop(int &Number);
    void Top(int &Number);
    int GetLength();
    void Print();

private:
    StackNode *Head;
    int Length;
};


#endif //PF2_PROGRAMMING_PROJECT_4_STRINGSTACK_H
