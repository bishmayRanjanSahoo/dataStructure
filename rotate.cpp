#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

void rotate(Node **href, int k){
	if(k==0)
		return;
	
	Node *cur = *href;
	int c=0;
	while(c < k && cur != NULL){
		cur = cur->next;
		c++;
	}
	
	if(cur == NULL)
		return;
	Node *kth = cur;
	
	while(cur->next != NULL)	
		cur = cur->next;
		
	cur->next = *href;
	*href = kth->next;
	kth->next = NULL;	
}

void push(Node **href, int data){
	
	Node *nn = new Node();
	nn->data = data;
	nn->next = *href;
	*href = nn;
}

void printList(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

int main(){
	
	Node *head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	
	cout<<"Before rotation\n";
	printList(head);
	
	rotate(&head, 3);
	
	cout<<"\nAfter rotation\n";
	printList(head);
	
	return 0;
}
