/******************************
 * Name: Bryson Shane
 * Assignment: 6
 * Purpose of File: This is the header file for the 
 * linked list class cpp file. 
 ******************************/

#include "data.h"

class LinkedList{
	/*********************************
	* This is the linked list class.
	* Contains a constructor and deconstructor 4 setters and 3 getters.
	* @attrib *head: a pointer our linked list structure. Makes the head of a node. 
	**********************************/
	public:
		/***************************************
		* Constructor/Deconstructor
		***************************************/
		LinkedList();
		~LinkedList();

		/***************************************
		* Mutators/Setters
		***************************************/
		bool addNode(int, string*);
		bool deleteNode(int);
		bool getNode(int, Data*);
		bool clearList();

		/***************************************
		* Getters
		***************************************/
		void printList(bool = false);
		int getCount();
		bool exists(int);

	private:
		Node *head;
};