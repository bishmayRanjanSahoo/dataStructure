#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};
void removeLoop(Node *loop, Node *head);
int detectLoop(Node *head){
	Node *slow = head, *fast = head;
	
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next; 
		if(slow == fast){
			removeLoop(slow, head);
			return 1;
		}
	}
	return 0;			
}

void removeLoop(Node *loop, Node *head){
	Node *ptr1, *ptr2;
	ptr1 = head;
	while(1){
		ptr2 = loop;
		while(ptr2->next!= loop && ptr2->next != ptr1)
			ptr2 = ptr2->next;	
			if(ptr2->next == ptr1)
				break;
			ptr1 = ptr1->next;	
	}
	
	ptr2->next = NULL;
}

void printList(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

Node *newNode(int data){
	Node *nn = new Node();
	nn->data = data;
	nn->next = NULL;
	return nn;
}

int main(){
	Node *head = newNode(1) ;
	head->next = newNode(2)	;
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	shead->next->next->next->next->next = head->next->next;
	int a = detectLoop(head);
	if(a == 1)
		cout<<"Loop is detected\n";
	else
		cout<<"Loop is not there\n";
	cout<<"after removing the loop\n";
	printList(head);
	return 0;
}


