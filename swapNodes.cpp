#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

void swapNodes(Node **href, int x, int y){
	if(x==y)
		return;
	
	Node *prevX = NULL, *currX = *href;
	
	while(currX && currX->data != x){
		prevX = currX;
		currX = currX->next;
	}
	
	Node *prevY = NULL, *currY = *href;
	
	while(currY && currY->data != y){
		prevY = currY;
		currY = currY->next;
	}
	
	//either x or y is not present
	
	if(currY == NULL || currX == NULL)	
		return;
	
	if(prevX != NULL)
		prevX->next = currY;
	else
		*href = currY;	
		
	if(prevY != NULL)	
		prevY->next = currX;
	else
		*href = currX;
		
	//swap next pointers
	
	Node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;				
}

 void push(Node **href, int x){
 	
 	Node *nn = new Node();
 	nn->data = x;
 	nn->next = *href;
 	*href = nn;
 }
 
 void printList(Node *node){
 	
 	while(node != NULL){
 		cout<<" "<<node->data;
 		node = node->next;
	 }
 	
 }
 
 int main()  
{  
    Node *start = NULL;  
  
    /* The constructed linked list is:  
    1->2->3->4->5->6->7 */
    push(&start, 7);  
    push(&start, 6);  
    push(&start, 5);  
    push(&start, 4);  
    push(&start, 3);  
    push(&start, 2);  
    push(&start, 1);  
  
    cout << "Linked list before calling swapNodes() ";  
    printList(start);  
  
    swapNodes(&start, 4, 3);  
  
    cout << "\nLinked list after calling swapNodes() ";  
    printList(start);  
  
    return 0;  
}  
