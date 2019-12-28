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
//Iterative
int getCount(Node *head){
	int c =0;
	
	Node *temp = head;
	while(temp!=NULL){
		c++;
		temp = temp->next;
	}
	return c;
}

//Recursive
int getCountRecursive(Node *head){
	
	if(head == NULL)
		return 0;
	
	return 1+ getCountRecursive(head->next);
}

int main(){
	Node *head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	cout<<"total no of node Iterative:"<<getCount(head);
	cout<<"\ntotal no of node Recursive:"<<getCountRecursive(head);
}
