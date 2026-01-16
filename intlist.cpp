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
    while(head!=nullptr) //goes through the list
    {
        Node* temp = head; //create temporary pointer
        head = head->next; //move head pointer to delete data at temporary address
        delete temp;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* current = head;

    while(current!=nullptr)
    {
        sum += current->info;
        current = current->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node*current = head;
    while(current!=nullptr)
    {
        if(current->info==value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* current = head;
    int max = current->info;

    while(current!=nullptr)
    {
        if(max<current->info)
        {
            max = current->info;
        }
        current = current->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double sum = 0.0;
    Node* current = head;

    if(current==nullptr)
    {
        return 0;
    }
    int count = 0;
    while(current!=nullptr)
    {
        sum += current->info;
        count += 1;
        current = current->next;
    }
    return sum/count;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    // IMPLEMENT
    Node* newHead = new Node;
    newHead->info = value;
    newHead->next = head;
    head = newHead;

    if(tail==nullptr)
    {
        tail = newHead;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
    Node* newEnd = new Node;
    newEnd->info = value;
    newEnd->next = nullptr;

    if(!head)
    {
        head = newEnd;
        tail = newEnd;
    }
    else{
        tail->next = newEnd;
        tail = newEnd;
    }
}

// return count of values
int IntList::count() const {
   int count = 0;
   Node* current = head;
   while(current!=nullptr)
   {
    count++;
    current = current->next;
   }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    if(this == &source) //self-assignment check (why?)
    {
        return *this;
    }
    while(head!=nullptr) //delete existing list
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    head = nullptr; // empty list

    if(source.head == nullptr) //checks for empty list at source
    {
        return *this;
    }

    head = new Node;
    head->info = source.head->info;
    head->next = nullptr;

    Node* current = head; // create two currents, to create deep copies
    Node* sourceCurrent = source.head->next;

    while(sourceCurrent!=nullptr) //goes through the list and copies elements from source to current.
    {
        current->next = new Node;
        current = current->next;
        current->info = sourceCurrent->info;
        current->next = nullptr;

        sourceCurrent = sourceCurrent->next;
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    //IMPLEMENT THIS
    head = nullptr;
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

