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
 * addNode, compareNodes
*******************************/
bool LinkedList::addNode(int passedID, string passedString) {
    bool ok = false;

    // check if given id is negative or already exists
    if (passedID < 0) {ok = false;}
    else if (head == NULL) { // if head null, assign passed args to head
        ok = true;
        head = new Node;
        head->data.id = passedID;
        head->data.data = passedString;
        head->prev = NULL;
        head->next = NULL;
    }
    else { // if not negative and head exists
        ok = compareNodes(passedID, passedString);
    } // end outer else (for valid data that is not the first node added)
    return ok;
} // end addNode

bool LinkedList::compareNodes(int passedID, string passedString) {
    bool ok = false;
    Node *current;
    Node *previous;

    current = head;
    while (current) { //move to next, compare passedID to ID in that node
        // if else structure to determine when/how to add node
        if (passedID == current->data.id) { ok = false; } // repeated ID
        else { // if ID not repeated, move to add the node
            // if added node needs to replace the head node
            if (current->data.id == head->data.id &&
                passedID < current->data.id) {
                // call method for adding head node
                addHeadNode(passedID, passedString);
            } // end if
            else { // middle and tail nodes (not head)
                if (current->prev) // already checked not head, if also not tail
                    addMiddleNode(passedID, passedString);
                else
                    addTailNode(passedID, passedString);
            }
        } // end else
        current = NULL; // just to stop endless loop while I get everything figured out
    } // end while
    return ok;
}





/*******************************
 * addHeadNode, addMiddleNode,
 * addTailNode
*******************************/
void LinkedList::addHeadNode(int passedID, string passedString) {
    // allocate mem for a new node
    Node *newNode = new Node; // will hold passed data
    newNode->data.id = passedID;
    newNode->data.data = passedString;
    newNode->next = head;

    // now put in head's position and reassign things as needed
    head->prev = newNode;
    head = newNode;
}

void LinkedList::addMiddleNode(int passedID, string passedString) {

}

void LinkedList::addTailNode(int passedID, string passedString) {

}




/*******************************
 * deleteNode, getNode
*******************************/
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



