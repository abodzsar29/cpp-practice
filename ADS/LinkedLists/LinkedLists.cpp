#include <iostream>

// Passing in pointers by pointer * vs reference *&:
/*
By pointer *:
The function receives a copy of the pointer. Both the original pointer and the copied pointer point to the same memory address,
meaning they refer to the same node. Modifications to the pointer itself within the function do not affect the original pointer
passed from the caller. The object that the pointer points to can be modified. The original pointer cannot be changed to point to a different node.

By reference *&:
Passing the actual pointer itself. This allows the function to modify the original pointer, making it possible to change what node the pointer points to.
The original pointer is modified, not just the object it points to. Useful when the function needs to update the pointer to point to a different
node, such as updating the head of a linked list.
*/

/////////////////////////////////////////////////////////////////////////

// Singly Linked List Node:
class SNode {
public:
	int data;
	SNode* next;
};

// Outputting the data attribute of the Node
static void iterate(SNode* n) {
	while (n != nullptr) {
		std::cout << n->data << " ";
		n = n->next;
	}
}

//Push Node to the start of the list as head
static void pushAsHead(SNode*& head, int val) {
	SNode* newNode = new SNode();
	newNode->data = val;
	newNode->next = head;
	head = newNode;
}

//Push Node to the end of the list as tail
static void pushToTail(SNode*& head, int val) {
	SNode* newNode = new SNode();
	newNode->data = val;

	// If the list is empty, set the new node as the head
	if (head == nullptr) {
		head = newNode;
		return;
	}

	// Traverse to the end of the list
	SNode* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}

	// Link the new node to the last node
	temp->next = newNode;
}

// Inserting after a specific Node with a direct pointer to it in prev_node
static void insertAfter(SNode*& prev_node, int new_data) {
	if (prev_node == nullptr) {
		std::cout << "The given previous node cannot be NULL" << std::endl;
		return;
	}

	SNode* new_node = new SNode();  // Create a new node with the given value
	new_node->data = new_data;

	// Adjust the pointers to insert the new node
	new_node->next = prev_node->next;
	prev_node->next = new_node;

}

//Inserting after required Node, without having an already existing pointer to it
static void insertAtPosition(SNode*& head, int position, int data) {
	if (position < 0) {
		std::cout << "Position must be >= 0." << std::endl;
		return;
	}

	SNode* newNode = new SNode();
	newNode->data = data;

	if (position == 0) {
		newNode->next = head;
		head = newNode;
		return;
	}

	SNode* n = head;
	int pos = 2;
	while (pos != position && n != nullptr) {
		n = n->next;
		pos++;
	}
	
	// If the position is out of bounds
	if (n == nullptr) {
		std::cout << "Position is out of bounds." << std::endl;
		delete newNode; // Clean up the unused node
		return;
	}

	newNode->next = n->next;
	n->next = newNode;
}

/////////////////////////////////////////////////////////////////////////



int main() {

	//Initialisation of the SNode class attributes
	SNode* head = new SNode();
	SNode* second = new SNode();
	SNode* third = new SNode();

	head->data = 1;
	second->data = 2;
	third->data = 3;

	head->next = second;
	second->next = third;
	third->next = nullptr;

	// Outputting the data attribute of the Node
	std::cout << "Linked List with initial values: ";
	iterate(head);
	std::cout << std::endl;

	// Pushing to the start of the list
	std::cout << "Pushing 11 as the head of the list: ";
	pushAsHead(head, 11);
	iterate(head);
	std::cout << std::endl;

	std::cout << "Pushing 99 as tail of the list: ";
	pushToTail(head, 99);
	iterate(head);
	std::cout << std::endl;

	std::cout << "Inserting 69 after the second value: ";
	insertAfter(second, 69);
	iterate(head);
	std::cout << std::endl;

	std::cout << "Inserting 999 into the 5th position: ";
	insertAtPosition(head, 5, 999);
	iterate(head);

	// Cleaning up memory
	while (head != nullptr) {
		SNode* temp = head;
		head = head->next;
		delete temp;
	}
	

	/////////////////////////////////////////////////////////////////////////


	return 0;
}