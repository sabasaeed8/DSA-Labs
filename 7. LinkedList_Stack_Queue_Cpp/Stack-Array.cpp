#include <iostream>
#include <string>
using namespace std;


class stacks{
	public:
	int arr[100];
	int top = -1;
	
	// *********** PUSH **********//
	void push(int x){
		if (top == (sizeof(arr)/sizeof(arr[0])) - 1){
			cout << "Overflow." << endl;
			return;
		}
		else{
		
		top = top+1;
		arr[top] = x;
		}		
	}
	
	// *********** POP **********//	
	int pop(){
		if (top == -1){
		   cout << "Stack is empty." << endl;	
		}
		top = top -1;
		return arr[top+1];		
	}
	
	// *********** TOP ELEMENT **********//
	int topElement(){
		return arr[top];
	}
	
	// *********** EMPTY_STACK **********//
	bool stack_empty(){
		if (top == -1){
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
		int i;
		cout << "Stack : ";
		for (i=0;i<=top;i++){
			cout << arr[i] << " ";
		}
		cout << "" << endl;
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
	stack1.push(7);
	stack1.displayStack();
	
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
