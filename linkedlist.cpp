/*********************
Name: Allison Crenshaw
Coding 05
Purpose: This program constructs a fully
 functional doubly linked list class.
**********************/

// include only header file directly
#include "linkedlist.h"

// all linked list methods go here

/*******************************
 * constructor and destructor
*******************************/
LinkedList::LinkedList() {
    head = NULL;
}
LinkedList::~LinkedList() {

}

/*******************************
 * add, delete, and getNode
*******************************/
bool LinkedList::addNode(int passedID, string passedData) {
    bool ok = false;
    Node *thisNode;

    // check if given id is negative or already exists
    if (passedID < 0) {
        ok = false;
    }
    else if (head == NULL) {
        // if head is null, assign passed args to head
        ok = true;
        head->data.id = passedID;
        head->data.data = passedData;
        // need to assign next and prev as null?
    }
    else { // if not negative and not first item (head) of list, then...
        /* compare to first node
         *   if not a dupe, check < and >
         *      if less than head, use addHead function
         *      if greater than head, go to next
         * at next, can create a loop for non-head nodes
         * at next, if not dupe, check < and > current
         *      if less than current, insert before current
         *      else (greater than current),
         *          check if next node to see if adding middle or tail */

    }

    return ok;
}

bool LinkedList::deleteNode(int) {
    bool ok = false;
    return ok;
}

bool LinkedList::getNode(int, Data *) {
    bool ok = false;
    return ok;
}

/*******************************
 * remaining functions
*******************************/
void LinkedList::printList(bool) {

}

int LinkedList::getCount() {
    int count = 0;
    return count;
}

bool LinkedList::clearList() {
    return false;
}

bool LinkedList::exists(int) {
    bool exists = false;
    return exists;
}



