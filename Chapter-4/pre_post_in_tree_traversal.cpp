#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* new_Node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


void pre_Order(struct Node* node){
	if (node == NULL)
		return;
	cout << node->data << " ";
	pre_Order(node->left);
	pre_Order(node->right);
}


void post_order(struct Node* node){
	if (node == NULL)
		return;
	post_order(node->left);
	post_order(node->right);
	cout << node->data << " ";
}



void In_Order(struct Node* node){
	if (node == NULL)
		return;

	In_Order(node->left);
	cout << node->data << " ";
	In_Order(node->right);
}



int main(){
	struct Node* root = new_Node(1);
	root->left = new_Node(4);
	root->right = new_Node(3);
	root->left->left = new_Node(9);
	root->left->right = new_Node(20);

	cout << "PREORDER traversal: ";
	pre_Order(root);
	cout<<endl;

	cout << " POSTORDER traversal: ";
    post_order(root);
	cout<<endl;

	cout << "INORDER traversal: ";
	In_Order(root);
	cout<<endl;

	return 0;
}

