#include <iostream>
#include <string>
using namespace std;

// ***************** Stacks using linked list *************************
class node{
	public:
		int data;
		node* next;
};

class stacks{
	public:
	node *top;
	public:
		stackst(){             // Constructor
			top = NULL;		
		}
	
	// *********** PUSH **********//	
	node* push(int x){
		node* new_top = new node();
	    new_top -> data = x;
	    new_top -> next = top;
	    top = new_top;
	    return new_top;	
	}
	
	// *********** POP **********//	
	void pop(){
		node*n = top;
		if (top == NULL){
			cout << "Stack is empty." << endl;
		}
	    top = top->next;
	    delete n;		
	}
	
	// *********** TOP ELEMENT **********//
	int topElement(){
		if (top == NULL){
			cout << "Stack is empty." << endl;
		} 
		return top->data;
	}
	
	// *********** EMPTY_STACK **********//
	bool stack_empty(){
		if (top == NULL){
			cout << "Stack is empty." << endl;
			return true;
		}
		else{
			cout << "Stack is not empty." << endl;
			return false;
		}	
	}
	
	// *********** DISPLAY STACK **********//
	void displayStack(){
		node* n = top;
		if (top == NULL){
			cout << "Stack is empty." << endl;
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
	//******** Push elements into stack ********//
	stacks stack1;
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);
	stack1.push(5);
	stack1.push(6);
	stack1.push(9);
	cout << "Stack: ";
	stack1.displayStack();
	cout << " " << endl;
	
	//******** Empty stack ********//
    cout << "Is stack empty? ";
	stack1.stack_empty();
	
	//******** Top Element ********//
	cout << "Top Element in stack : ";
	cout << stack1.topElement();
	cout << " " << endl;
	
	//******** Pop stack ********//
	stack1.pop();
	cout << "Stack after Pop: ";
	stack1.displayStack();
	
	return 0;
}

