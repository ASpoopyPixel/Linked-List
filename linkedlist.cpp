/************************************
 * Name: Bryson Shane
 * Assignment: 6
 * Purpose of file: This file contains the methods to access the linked
 * list. 
 * 
 ************************************/
#include <iostream>
#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList(){
    /******************************
    * This is our constructor for the linked list.
    * On call, it will create a node. and assign the Head to null.
    * 
    *******************************/
    head = NULL;

}

LinkedList::~LinkedList(){
    /*********************************************
    * This is the deconstructor. It calls clear list,
    * method to deallocate all the pointers and delete them.
    * 
    **********************************************/
    clearList();
}

bool LinkedList::addNode(int id, string* data) {
    /*********************************************
    * The addNode method searches for the position on where to 
    * and makes sure the list don't get disconnected. It first checks to see
    * if the given values are valid if not, it will return false and add nothing.
    * Otherwise it will check if head is currently pointing to anything if not, it'll add to the head automatically.
    * if there's something to the head, it checks to see where the id fits inbetween the values
    * It will then see if there's any duplicates. If a duplicate is found, it will return false.
    * If not, it keeps the list connected and adds the node into it.
    * 
    * @param id: the id that is given to be assigned to the node
    * @param *data: the data that's being added to the to the node. Passed by reference since string.
    * @attrib added: a flag to show that the values were added
    * @attrib *newNode: pointer of a newNode, the node that's being added.
    * @attrib *current: the current position of the linked list.
    * @return added: returns true if the node was added otherwise returns false.
    **********************************************/
    
    bool added = false;

    if (id >= 0 && !data->empty()) {

        if (!head) {
            Node* newNode = new Node{ id, *data, nullptr, nullptr };
            head = newNode;
            added = true;
        }
        else {
            Node* current = head;

            while (current->next && current->data.id != id) {
                current = current->next;
            }

            if (current->data.id != id) {
                Node* newNode = new Node{ id, *data, nullptr, nullptr };
                current->next = newNode;
                newNode->prev = current;
                added = true;
            }
        }
    }

    return added;
}

    


bool LinkedList::deleteNode(int id){
    /*******************************************
    * DeleteNode searches for the node by the int and iteriates through 
    * the linked list and deletes the node that matches the id.
    * It will keep the list connected by using a temp node to move the position of the node
    * to the previous, next, or head. Depending on which node was deleted.
    * 
    * @param id: the id we're searching for to delete.
    * @attrib deleted: the flag if the variable was deleted
    * @attrib *current: the current position of the node
    * @attrib *prev: used to assign a node to the previous position if conditions are met
    * @return deleted: returns true if the value was deleted otherwise returns false.
    ********************************************/
    bool deleted = false;

    Node* current = head;
    Node* prev = nullptr;

    while (current && !deleted) {
        if (current->data.id == id) {
            if (prev) {
                prev->next = current->next;
                if (current->next) {
                    current->next->prev = prev;
                }
            }
            else {
                head = current->next;
                if (head) {
                    head->prev = nullptr;
                }
            }
            delete current;
            deleted = true;
        }

        prev = current;
        current = current->next;
    }

    return deleted;
}

bool LinkedList::getNode(int id, Data* dataOut) {
    /**********************************
    * getNode searches for the node in the linked list 
    * by the id and gives the data inside it.
    * returns true if its found otherwise it returns false.
    * 
    * @param id: id we're searching for
    * @param dataOut: the data the will be given
    * 
    * @attrib current: the current position of the linked list.
    * @attrib nodeFound: if the node is found it returns true otherwise it returns false.
    ************************************/
    
    
    Node* current = head;
    bool nodeFound = false;

    while (current && !nodeFound){
        if (current->data.id == id) {
            *dataOut = current->data;
            nodeFound = true;
        }
        current = current->next;
    }
    
    return nodeFound;
}

void LinkedList::printList(bool reverse) {
    /***********************
    * Simply displays the Nodes in order.
    * If reverse is set to true, goes through the linked list
    * and prints the linked list in reverse order.
    * 
    * @param reverse: if set to true print the list backwards.
    * @attrib current: current position in the linked list.
    ************************/
    Node* current = head;
    if(reverse){
        while (current->next) {
            current = current->next;
        }
        while (current) {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->prev;
        }
    }
    else {
         while (current) {
             std::cout << current->data.id << ": " << current->data.data << std::endl;
             current = current->next;
         }
    }
}
    
int LinkedList::getCount() {
    /**************************
    * Get count simply counts the total amount
    * of nodes existing and returns that amount.
    * It goes until curr hits null
    * 
    * 
    * @attrib count: the total amount of nodes in the list.
    * @attrib *curr: current position of the list.
    * @return count: the total amount of nodes is returned.
    ***************************/
    int count = 0;
    Node* curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

bool LinkedList::clearList() {
    /****************************
    * Clearlist simply emptys the list and
    * destroys all the nodes. it assigns each node
    * to a temp node and is then deallocated.
    * 
    * @attrib *temp: the node that temporarily stores the current node's position
    * and is then deleted.
    * 
    * @return true: confirms the list was deleted.
    *******************************/
    
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return true;
}

bool LinkedList::exists(int id) {
    /**********************************
    * exist simply checks to see if the node is existing.
    * It only returns true or false.
    * 
    * @param id: the id we're searching for to see if the node exist.
    * 
    * @attrib found: signals the node was found
    * @attrib *current: the current position of the linked list.
    * 
    * @return found: returns true if it was otherwise it returns false
    ***********************************/
    bool found = false;
    Node* current = head;

    while (current && !found) {
        if (current->data.id == id) {
            found = true;
        }
        current = current->next;
    }

    return found;
}