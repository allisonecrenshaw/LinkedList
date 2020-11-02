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

    // start with head and begin comparisons
    current = head;
    while (current && passedID != current->data.id && ok == false) {
        if (passedID < current->data.id) { // if less than current node, insert before
            if (!current->prev) // if needing to replace head node
                addHeadNode(passedID, passedString);
            else if (!current->next)
                addTailNode(passedID, passedString);
            else
                addMiddleNode(passedID, passedString, previous, current);
            ok = true;
        } // end if clause for inserting before current node
        else {
            previous = current;
            current = current->next; // move to next node and repeat loop
        }// already checked for dupe, already checked for insertion
    } // end while
    return ok;
} // end compareNodes





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
} // end addHeadNode()

void LinkedList::addMiddleNode(int passedID, string passedString,
                               Node* previous, Node* current) {
    // allocate mem for new node
    Node *newNode = new Node;
    newNode->data.id = passedID;
    newNode->data.data = passedString;

    // reassign previous and next vals so that links are not lost
    current->prev = newNode;
    previous->next = newNode;
    newNode->prev = previous;
    newNode->next = current;
} // end addMiddleNode()

void LinkedList::addTailNode(int passedID, string passedString) {
    // allocate mem for new node
    Node *newNode = new Node;
    newNode->data.id = passedID;
    newNode->data.data = passedString;

    // reassign 
} // end addTailNode()




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



