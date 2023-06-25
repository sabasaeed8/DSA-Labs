#include <iostream>
#include <string>
using namespace std;


class node{
	public:
		int data;
		node* next;
};
class queue{
	public:
	node *first,*last;
	public:
		queue(){             // Constructor
			first = NULL;
			last = NULL;		
		}
	
	// *********** ENQUEUE **********//
	node* Enqueue(int x){
		node *new_node = new node();
		new_node-> data = x;
		new_node-> next = NULL;
		if(first == NULL && last == NULL){   
			first = new_node;  
			last = new_node;
		}
		else{
			last->next = new_node;
			last = new_node;
	    }
		return first;	
	}
	
	// *********** DEQUEUE **********//	
	void Dequeue(){
		node*n = first;
		if (first == NULL){
			cout << "Queue is Empty." << endl;
		}
		if (first == last){
			first=last=NULL;
		}
		else{
			first = first->next;
			delete n;
		}				
	}
	
	// *********** FIRST ELEMENT **********//
	int Peek(){
		if (first == NULL){
			cout << "Queue is empty." << endl;
		}
		return first->data;		
	}
	
	// *********** EMPTY_QUEUE **********//
	bool IsEmpty(){
		if (first == NULL){
			return true;
		}
		else{
			return false;
		}
			
	}
	
	//*********** DISPLAY QUEUE **********//
	void displayQueue(){
		node* n = first;
		if (first == NULL){
			cout << "Queue is empty." << endl;
		}
       else{
        while (n != NULL)
        {
            cout << n->data << "-> ";
            n = n->next;
        }
    }	
	}	
};
int main(){
//	******** Enqueuw elements *********//
	queue Queue1;
	Queue1.Enqueue(1);
	Queue1.Enqueue(2);
	Queue1.Enqueue(3);
	Queue1.Enqueue(4);
	Queue1.Enqueue(5);
	Queue1.Enqueue(6);
	cout << "Queue: " ;
	Queue1.displayQueue();
	cout << " " << endl;
	
//	******** Top Element ********//
	cout << "Peek Element in queue : ";
	cout << Queue1.Peek();
	cout << " " << endl;
	
//	******** DeQueue ********//
	Queue1.Dequeue();
	cout << "After Dequeue: ";
	Queue1.displayQueue();
		
	return 0;

}
