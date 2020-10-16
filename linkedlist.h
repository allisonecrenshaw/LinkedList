/*********************
Name: Allison Crenshaw
Coding 05
Purpose: This program constructs a fully
 functional doubly linked list class.
**********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "data.h"

class LinkedList {

public:
    LinkedList(); // constructor
    ~LinkedList(); // destructor

    bool addNode(int, string);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool=false);
    int getCount();
    bool clearList();
    bool exists(int);

private:
    // private vars or method prototypes go here
    // none for now but may create helper functions later

}; // end class

#endif //LINKED_LIST_H