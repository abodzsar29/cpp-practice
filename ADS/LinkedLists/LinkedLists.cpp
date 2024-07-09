#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

// Outputting the data attribute of the Node
void iteratorForList(Node* n) {
	while (n != nullptr) {
		cout << n->data << " ";
		n = n->next;
	}
}

//Push Node to the start of the list
void push(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
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
	iteratorForList(head);
	cout << endl;
	// Pushing to the start of the list
	push(&head, 11);
	iteratorForList(head);

	// Cleaning up memory
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	
	return 0;
}