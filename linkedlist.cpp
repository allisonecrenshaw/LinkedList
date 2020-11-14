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

    // check if given id is negative
    if (passedID > 0) {
        if (head == NULL) { // if head null, assign passed args to head
            ok = true;
            head = new Node;
            head->data.id = passedID;
            head->data.data = passedString;
            head->prev = NULL;
            head->next = NULL;
            cout << "First head added...";
        }
        else { // if not negative and head exists
            ok = compareNodes(passedID, passedString);
        } // end outer else (for valid data that is not the first node added)
    } // end of if value is non-negative

    printList();

    return ok;
} // end addNode



bool LinkedList::compareNodes(int passedID, string passedString) {
    bool ok = false;
    bool stop = false;
    Node *current;
    Node *previous;
    int loopCount = 0;

    // start with head
    current = head;

    // while not ok and next still exists
    cout << "Begin while loop." << endl;
    while (current && stop == false && loopCount < 20) {
        loopCount++;
        cout << "Loop #" << loopCount << "...current ID is " << current->data.id << endl;
        if (passedID < current->data.id) {
            cout << "Passed ID < current ID, changing stop to true." << endl;
            stop = true;
        }
        else {
            cout << "Moving to next item." << endl;
            cout << "Changing previous to current"<< endl;
            previous = current;
            cout << "Changing current to next." << endl;
            current = current->next;
        }
    } // end while

    // select which addNode method to use
    if (passedID < current->data.id && !current->prev) {
        ok = true;
        addHeadNode(passedID, passedString);
        cout << "Head added...";
    }
    else if (passedID < current->data.id && passedID != previous->data.id) {
        ok = true;
        addMiddleNode(passedID, passedString, previous, current);
        cout << "Middle added...";
    }
    else if (passedID > current->data.id) {
        ok = true;
        addTailNode(passedID, passedString, current);
        cout << "Tail added...";
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

    // reassign next and prev as needed
    newNode->next = head;
    newNode->prev = NULL;
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
    cout << "Inside add tail node." << endl;
    cout << "Current is " << current->data.id << endl;
    // allocate mem for new node
    Node *newNode = new Node;
    newNode->data.id = passedID;
    newNode->data.data = passedString;

    // reassign current to new tail, make tail point to current as its prev
    newNode->next = NULL;
    newNode->prev = current;
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
    Node *current;
    current = head;
    string line = "******************************";
    int loop = 0;


    cout << endl << line << endl;
    cout << "Printing linked list..." << endl;
    while (current && loop < 20) {
        loop++;
        cout << current->data.id << endl;
        current = current->next;
    }
    cout << "End of linked list." << endl << line << endl;

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



