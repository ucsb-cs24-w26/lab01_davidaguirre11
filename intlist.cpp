// intlist.cpp
// Implements class IntList
// David Aguirre 1/8/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    head = nullptr;
    if(source.head==nullptr)
    {
        return; //exits the constructor early
    }
    head = new Node; //creates a new node
    head->info = source.head->info; 
    head->next = nullptr;

    Node* current = head;
    Node* sourceCurrent = source.head->next;
    while(sourceCurrent!=nullptr)
    {
        current->next = new Node; //creates a new node
        current = current->next; //moves current pointer 
        current->info = sourceCurrent->info; //access info of current pointer, to equal info of sourceCurrent pointer
        current->next = nullptr; //next pointer to be a nullptr

        sourceCurrent = sourceCurrent->next; //move sourceCurrent pointer
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    while(head!=nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


// return sum of values in list
int IntList::sum() const {
    return 0; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    return 0; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    return 0.0; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    // IMPLEMENT
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
 
}

// return count of values
int IntList::count() const {
   //IMPLEMENT THIS
   return 0;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    //IMPLEMENT THIS 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

