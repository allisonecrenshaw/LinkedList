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
bool LinkedList::addNode(int passedID, string passedInfo) {
    bool ok = false;
    Node *current;
    Node *previous;

    // check if given id is negative or already exists
    if (passedID < 0) {ok = false;}
    else if (head == NULL) { // if head null, assign passed args to head
        ok = true;
        head = new Node;
        head->data.id = passedID;
        head->data.data = passedInfo;
        head->prev = NULL;
        head->next = NULL;
    }
    else { // if not negative and head exists
        current = head;
        while (current) { //move to next, compare passedID to ID in that node
            if (passedID == current->data.id) { ok = false; }
            else {
                ok = true;
                // if added node needs to replace the head node
                if (current->data.id == head->data.id &&
                passedID < current->data.id) {
                    // call method for adding head node
                    addHeadNode(passedID, passedInfo);
                } // end if
            } // end else
        } // end while
    } // end outer else (for valid data that is not the first node added)
    return ok;
}

void LinkedList::addHeadNode(int, string) {
    
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



