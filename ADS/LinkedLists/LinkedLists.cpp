#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

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

// Outputting the data attribute of the Node
void iterate(Node* n) {
	while (n != nullptr) {
		cout << n->data << " ";
		n = n->next;
	}
}

//Push Node to the start of the list as head
static void pushAsHead(Node*& head, int val) {
	Node* newNode = new Node();
	newNode->data = val;
	newNode->next = head;
	head = newNode;
}

//Push Node to the end of the list as tail
static void pushToTail(Node*& head, int val) {
	Node* newNode = new Node();
	newNode->data = val;

	// If the list is empty, set the new node as the head
	if (head == nullptr) {
		head = newNode;
		return;
	}

	// Traverse to the end of the list
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}

	// Link the new node to the last node
	temp->next = newNode;
}

// Inserting after a specific Node
static void insertAfter(Node*& prev_node, int new_data) {
	if (prev_node == nullptr) {
		std::cout << "The given previous node cannot be NULL" << std::endl;
		return;
	}

	Node* new_node = new Node();  // Create a new node with the given value
	new_node->data = new_data;

	// Adjust the pointers to insert the new node
	new_node->next = prev_node->next;
	prev_node->next = new_node;

}

int main() {
	Node* head = new Node();;
	Node* second = new Node();;
	Node* third = new Node();;

	head->data = 1;
	second->data = 2;
	third->data = 3;

	head->next = second;
	second->next = third;
	third->next = nullptr;

	// Outputting the data attribute of the Node
	iterate(head);
	cout << endl;
	// Pushing to the start of the list
	pushAsHead(head, 11);
	iterate(head);
	cout << endl;
	pushToTail(head, 99);
	iterate(head);
	cout << endl;
	insertAfter(second, 69);
	iterate(head);

	// Cleaning up memory
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	
	return 0;
}