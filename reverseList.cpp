#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

void reverse(Node **href){
	
	Node *curr = *href;
	Node *prev = NULL;
	Node *temp = NULL;
	
	while(curr != NULL){
		temp = curr->next;
		curr->next = prev; //Help in reversing
		prev = curr;
		curr = temp;
	}
	*href = prev;
}

void print(Node *head){
	while(head != NULL){
		cout<<" "<<head->data;
		head = head->next;
	}
}

void push(Node **href, int new_data){
	
	Node *nn = new Node();
	nn->data = new_data;
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
	
	print(head);
	
	reverse(&head);
	
	cout<<"\n";
	
	print(head);
	return 0;
}
