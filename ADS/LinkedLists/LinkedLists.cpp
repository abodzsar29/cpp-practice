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
static void SNiterate(SNode* n) {
	while (n != nullptr) {
		std::cout << n->data << " ";
		n = n->next;
	}
}

//Push Node to the start of the list as head
static void SNpushAsHead(SNode*& head, int val) {
	SNode* newNode = new SNode();
	newNode->data = val;
	newNode->next = head;
	head = newNode;
}

//Push Node to the end of the list as tail
static void SNpushToTail(SNode*& head, int val) {
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
static void SNinsertAfter(SNode*& prev_node, int new_data) {
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
static void SNinsertAtPosition(SNode*& head, int position, int data) {
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


// Doubly Linked List Node:

class DNode {
public:
	int data;
	DNode* next;
	DNode* prev;

};

static void DNpushAsHead(DNode*& head, int data) {
	DNode* second = new DNode();
	second->data = data;
	if (head == nullptr) {
		head = second;
		second->next = nullptr;
		second->prev = nullptr;
		return;
	}

	head->prev = second;
	second->next = head;
	second->prev = nullptr;
	head = second;
}

static void DNpushAsTail(DNode*& head, int data) {
	DNode* newNode = new DNode();
	newNode->data = data;

	if (head == nullptr) {
		head = newNode;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		return;
	}

	//Iterate:
	DNode* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	newNode->next = nullptr;
}

static void DNpushToPosition(DNode*& head, int pos, int data) {
	DNode* newNode = new DNode();
	newNode->data = data;
	if (pos == 1) {
		newNode->next = head;
		newNode->prev = nullptr;

		if (head != nullptr) {
			head->prev = newNode;
		}
		head = newNode;
		return;
	}
	if (pos <= 0) {
		std::cout << "The position int cannot be 0 or smaller" << std::endl;
		return;
	}
	
	if (head == nullptr) {  // Edge case for empty list
		head = newNode;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		return;
	}
	
	int sizeCount = 1;  // Edge case for when pos bigger than list
	DNode* sizeNode = head;
	while (sizeNode->next != nullptr) {
		sizeCount += 1;
		sizeNode = sizeNode->next;
	}
	if (pos > sizeCount + 1) {
		std::cout << "The position for insertion is too big. The max is: " << sizeCount + 1 << std::endl;
		return;
	}

	DNode* temp = head;
	for (int x = 2; x < pos; ++x) { // Ensure temp doesn't become nullptr
		temp = temp->next;
	}

	newNode->next = temp->next;
	if (temp->next != nullptr) {
		temp->next->prev = newNode;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

int main() {
	std::cout << "##################################################" << std::endl;
	std::cout << "Singly Linked List objects:" << std::endl;
	//Initialisation of the SNode class attributes
	SNode* SNhead = new SNode();
	SNode* SNsecond = new SNode();
	SNode* SNthird = new SNode();

	SNhead->data = 1;
	SNsecond->data = 2;
	SNthird->data = 3;

	SNhead->next = SNsecond;
	SNsecond->next = SNthird;
	SNthird->next = nullptr;

	// Outputting the data attribute of the Node
	std::cout << "Linked List with initial values: ";
	SNiterate(SNhead);
	std::cout << std::endl;

	// Pushing to the start of the list
	std::cout << "Pushing 11 as the head of the list: ";
	SNpushAsHead(SNhead, 11);
	SNiterate(SNhead);
	std::cout << std::endl;

	std::cout << "Pushing 99 as tail of the list: ";
	SNpushToTail(SNhead, 99);
	SNiterate(SNhead);
	std::cout << std::endl;

	std::cout << "Inserting 69 after the second value: ";
	SNinsertAfter(SNsecond, 69);
	SNiterate(SNhead);
	std::cout << std::endl;

	std::cout << "Inserting 999 into the 5th position: ";
	SNinsertAtPosition(SNhead, 5, 999);
	SNiterate(SNhead);

	// Cleaning up memory
	while (SNhead != nullptr) {
		SNode* SNtemp = SNhead;
		SNhead = SNhead->next;
		delete SNtemp;
	}
	
	std::cout << std::endl << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "Doubly Linked List objects:" << std::endl;
	/////////////////////////////////////////////////////////////////////////
	DNode* head = nullptr; // Initialize an empty doubly linked list

	// Test DNpushAsHead
	std::cout << "Pushing 10 as the head of the list, then 20 & 30:" << std::endl;
	DNpushAsHead(head, 10); // List: 10
	DNpushAsHead(head, 20); // List: 20 -> 10
	DNpushAsHead(head, 30); // List: 30 -> 20 -> 10

	// Display the list
	DNode* temp = head;
	std::cout << "Current List after pushing to head: ";
	while (temp != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;

	// Test DNpushAsTail
	std::cout << "Pushing 40 and 50 as the tail of the list:" << std::endl;
	DNpushAsTail(head, 40); // List: 30 -> 20 -> 10 -> 40
	DNpushAsTail(head, 50); // List: 30 -> 20 -> 10 -> 40 -> 50

	// Display the list
	temp = head;
	std::cout << "Current List after pushing to tail: ";
	while (temp != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;

	// Test DNpushToPosition
	std::cout << "Inserting 25 at position 2:" << std::endl;
	DNpushToPosition(head, 2, 25); // List: 30 -> 25 -> 20 -> 10 -> 40 -> 50

	std::cout << "Inserting 15 at position 5:" << std::endl;
	DNpushToPosition(head, 5, 15); // List: 30 -> 25 -> 20 -> 10 -> 15 -> 40 -> 50

	std::cout << "Inserting 5 at position 1 (new head):" << std::endl;
	DNpushToPosition(head, 1, 5); // List: 5 -> 30 -> 25 -> 20 -> 10 -> 15 -> 40 -> 50

	// Display the list
	temp = head;
	std::cout << "Final List after pushing to specific positions: ";
	while (temp != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;

	// Cleanup: Free the allocated memory
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}

	std::cout << "Memory cleaned up. Exiting program." << std::endl;
	return 0;
}

