#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

Node *reverse(Node *head, int k){
	
	Node *current = head;
	Node *next = NULL;
	Node *prev = NULL;
	int count = 0;
	while( current!= NULL && count < k){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	
	if(next != NULL)
		head->next = reverse(next, k);
		
	return prev;	
}

void printList(Node *head){
	
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

void push(Node **href, int data){
	Node *nn = new Node();
	nn->data = data;
	nn->next = *href;
	*href = nn;
}

int main(){
	
	Node *head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	
	cout<<"Before reverse\n";
	printList(head);
	
	head = reverse(head, 3);
	
	cout<<"\nAfter reverse from 3\n";
	printList(head);
	return 0;
}
