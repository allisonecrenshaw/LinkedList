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
    head = nullptr;
}
LinkedList::~LinkedList() {

}






/*******************************
 * addNode, compareNodes
*******************************/
bool LinkedList::addNode(int passedID, string passedString) {
    bool ok = false;

    // check if given id is negative
    if (passedID > 0) {
        if (head == nullptr) { // if head null, assign passed args to head
            ok = true;
            head = new Node;
            head->data.id = passedID;
            head->data.data = passedString;
            head->prev = nullptr;
            head->next = nullptr;
        }
        else { // if not negative and head exists
            ok = compareNodes(passedID, passedString);
        } // end outer else (for valid data that is not the first node added)
    } // end of if value is non-negative

    return ok;
} // end addNode



bool LinkedList::compareNodes(int passedID, string passedString) {
    bool ok = false;
    bool stop = false;
    Node *current;
    Node *previous;

    // start with head
    current = head;

    // while not ok and next still exists
    while (current && !stop) {
        // if possible insertion before current, stop.
        if (passedID < current->data.id)
            stop = true;
        else {
            previous = current;
            current = current->next;
        }
    } // end while

    // select which addNode method to use
    if (passedID < current->data.id && !current->prev) {
        ok = true;
        addHeadNode(passedID, passedString);
    }
    else if (passedID < current->data.id && passedID != previous->data.id) {
        ok = true;
        addMiddleNode(passedID, passedString, current, previous);
    }
    else if (passedID > current->data.id && !current->next) {
        ok = true;
        addTailNode(passedID, passedString, current);
    }

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
    newNode->prev = nullptr;

    // now put new Node as head's value and reassign prev/next as needed
    head->prev = newNode; // moves current head up in list
    head = newNode; // gives new value to head
} // end addHeadNode()

void LinkedList::addMiddleNode(int passedID, string passedString,
                               Node* previous, Node* current) {
    // allocate mem for new node
    Node *newNode = new Node;
    newNode->data.id = passedID;
    newNode->data.data = passedString;

    // reassign previous and next vals so that links are not lost
    previous->next = newNode;
    newNode->prev = previous;
    current->prev = newNode;
    newNode->next = current;
} // end addMiddleNode()

void LinkedList::addTailNode(int passedID, string passedString, Node* current) {
    // allocate mem for new node
    Node *newNode = new Node;
    newNode->data.id = passedID;
    newNode->data.data = passedString;

    // reassign current to point to new tail, make tail point to current as its prev
    newNode->prev = current;
    newNode->next = nullptr;
    current->next = newNode;
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



