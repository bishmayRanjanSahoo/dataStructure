#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

Node *sortedMerge(Node *a, Node *b);
void split(Node *source, Node **frontref, Node **rearref);

void mergeSort(Node **href){
	Node *head = *href;
	Node *a, *b;
	
	if(head == NULL || head->next == NULL) 
		return;
	
	
	split(head, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	
	*href = sortedMerge(a,b);
}

Node *sortedMerge(Node *a, Node *b){
	Node *result = NULL;
	
	if(a == NULL)
		return b;
	if(b == NULL)	
		return a;
		
	if(a->data <= b->data){
		result = a;
		result->next = sortedMerge(a->next, b);
	}
	else{
		result = b;
		result->next = sortedMerge(a, b->next);
	}
	return result;	
}

void split(Node *source, Node **frontref, Node **rearref){
	Node *fast, *slow;
	slow = source;
	fast = source->next;
	
	while(fast != NULL){
		fast = fast->next;
			if(fast != NULL){
				slow = slow->next;
				fast = fast->next;
			}
	}
	*frontref = source;
	*rearref = slow->next;
	slow->next = NULL;
}

void printList(Node *head){
	while(head != NULL){
		cout<<" "<<head->data;
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

	push(&head, 2);
	push(&head, 4);
	push(&head, 1);
	push(&head, 5);
	push(&head, 3);
	
	mergeSort(&head);
	
	cout<<"Sorted list of 2->4->1->5->3 is\n";
	printList(head);
	return 0;
}
