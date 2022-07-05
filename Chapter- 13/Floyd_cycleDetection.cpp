#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int value;
	Node* Link;

	Node(int value){
		this->value = value;
		Link = NULL;
	}
};

Node* head = NULL;
class linked_List {
public:
	void insert(int item){
		Node* New_node = new Node(item);
		if (head == NULL)
			head = New_node;
		else {
			New_node->Link = head;
			head = New_node;
		}
	}

	bool loop_detection(){
		Node *slowPointer = head,
			*fastPointer = head;

		while (slowPointer != NULL && fastPointer != NULL && fastPointer->Link != NULL) {
			slowPointer = slowPointer->Link;
			fastPointer = fastPointer->Link->Link;
			if (slowPointer == fastPointer)
				return 1;
		}
		return 0;
	}
};

int main(){
	linked_List LS;
	LS.insert(10);
	LS.insert(20);
	LS.insert(30);
	LS.insert(40);
	LS.insert(50);

	Node* temp = head;
	while (temp->Link != NULL)
		temp = temp->Link;

	temp->Link = head;

	if (LS.loop_detection())
		cout << " Loop exists in Linked List " << endl;
	else
		cout << " Loop doesn't exists in Linked List " << endl;

	return 0;
}
