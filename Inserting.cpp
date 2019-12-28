#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

void push(Node **href, int new_data){
	Node *nn = new Node();
	nn->data = new_data;
	nn->next = *href;
	*href = nn;
}

void pushAfter(Node *prev_node, int new_data)
{
	if(prev_node->next == NULL){
		cout<<"New node can't be added"	;
		return;
	}
	
	Node *nn = new Node();
	nn->data = new_data;
	nn->next = prev_node->next;
	prev_node->next = nn;
}

void pushLast(Node **href, int new_data){
	Node *nn = new Node();
	Node *temp = *href;
	nn->data = new_data;
	nn->next = NULL;
	
	if(*href == NULL){
		*href = nn;
		return;
	}
	
	while(temp->next!=NULL){
		temp = temp->next;
	}
	
	temp->next = nn;
	return;
}

void printNode(Node *node){
	while(node != NULL){
		cout<<" "<<node->data;
		node = node->next;
	}
}

void deleteNode(Node **href, int key){
	
	Node *temp = *href, *prev;
	
	if(temp != NULL && temp->data == key){
		*href = temp->next;
		free(temp);
		return;
	}
	
	while(temp!=NULL && temp->data!=key){
		prev = temp;
		temp = temp->next;
	}
	
	if(temp==NULL) 
		return;
	
	prev->next = temp->next;
	free(temp);
}

int main()
{
	Node *head = NULL;
	push(&head, 6);// 6
	pushLast(&head, 7); //6->7
	push(&head,4); //4->6->7
	pushAfter(head, 5); //4->5->6->7
	cout<<"Created linked list:\n";
	printNode(head);
	deleteNode(&head, 7);
	cout<<"\nAfter delete\n";
	printNode(head);
}

