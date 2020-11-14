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
            //cout << "First head added...";
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
    int loopCount = 0;

    // start with head
    current = head;

    // while not ok and next still exists
    //cout << "Begin while loop." << endl;
    while (current && stop == false) {
        loopCount++;
        //cout << "Loop #" << loopCount << "...current ID is " << current->data.id << endl;
        if (passedID < current->data.id) {
            //cout << "Passed ID < current ID, changing stop to true." << endl;
            stop = true;
        }
        else {
            //cout << "Moving to next item." << endl;
            //cout << "Changing previous to current"<< endl;
            previous = current;
            //cout << "Changing current to next." << endl;
            current = current->next;
        }
    } // end while

    // head case: current not null (haven't reached tail) + less than head
    if (current && passedID < current->data.id && !current->prev) {
        ok = true;
        addHeadNode(passedID, passedString);
        //cout << "Head added...";
    } // else if we're less than current, but not head (prev), and not equal to the prev
    else if (current && passedID < current->data.id && passedID != previous->data.id) {
        ok = true;
        addMiddleNode(passedID, passedString, previous, current);
        //cout << "Middle added...";
    } // else if we are at the tail
    else if (!current && passedID > previous->data.id) {
        ok = true;
        addTailNode(passedID, passedString, previous);
        //cout << "Tail added...";
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

void LinkedList::addTailNode(int passedID, string passedString, Node* previous) {
    // allocate mem for new node
    Node *newNode = new Node;
    newNode->data.id = passedID;
    newNode->data.data = passedString;

    // reassign current to new tail, make tail point to current as its prev
    newNode->next = NULL;
    newNode->prev = previous;
    previous->next = newNode;
} // end addTailNode()




/*******************************
 * deleteNode, getNode
*******************************/
bool LinkedList::deleteNode(int id) {
    // bool deleteNode(int); pass this method an id to delete.
    // Return true or false to indicate success or failure.
    // Delete the memory the node was using.
    bool found = false;
    Node *current;

    current = head;
    while (current && !found) {
        if (id == current->data.id)
            found = true;
        else
            current = current->next;
    }

    if (found) {
        if (!current->prev) {
            current->next->prev = NULL;
            head = current->next;
            delete current;
        } else if (!current->next) {
            current->prev->next = NULL;
            delete current;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    return found;
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
    while (current) {
        loop++;
        cout << current->data.id << endl;
        current = current->next;
    }
    cout << "End of linked list." << endl << line << endl;
}

int LinkedList::getCount() {
    int count = 0;
    Node *current = head;

    while (current) {
        count++;
        current = current->next;
    }

    return count;
}

bool LinkedList::clearList() {
    return false;
}

bool LinkedList::exists(int) {
    bool exists = false;
    return exists;
}



