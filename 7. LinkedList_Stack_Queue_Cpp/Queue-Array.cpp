#include <iostream>
#include <string>
using namespace std;


class queue{
	public:
	int arr[100];
	int first,last;
	public:
		queue(){             // Constructor
			first = -1;
			last = -1;		
		}
	
	// *********** ENQUEUE **********//
	void Enqueue(int x){
		if	(IsFull()){
			cout << "Queue is full." << endl;
			return;
		}
		else if(IsEmpty()){
			first = 0;
			last = 0;
		}
		else{
			last = last+1;
		}
		arr[last] = x;
	}
	
	// *********** DEQUEUE **********//	
	int Dequeue(){
		if	(IsEmpty()){
			cout << "Queue is Empty." << endl;
		}
		else if(first == last){
			first = -1;
			last = -1;
		}
		else{
			first = first+1;
		}
		return arr[first-2];		
	}
	
	// *********** FIRST ELEMENT **********//
	int Peek(){
		if (first == -1){
			cout << "Queu is empty" << endl;
		}
		return arr[first];
	}
	
	// *********** IsFull **********//
	bool IsFull(){
		if (last == (sizeof(arr)/sizeof(arr[0])) - 1){
			return true;
		}
		else{
			return false;
		}
	}
	
	// *********** EMPTY_QUEUE **********//
	bool IsEmpty(){
		if (first == -1 && last== -1){
			return true;
		}
		else{
			return false;
		}	
	}
	
	// *********** DISPLAY QUEUE **********//
	void displayQueue(){
		int i;
		cout << "Queue : ";
		for (i=first;i<=last;i++){
			cout << arr[i] << " ";
		}
		cout << "" << endl;
	}	
};
int main(){
	//******** Enqueuw elements *********//
	queue Queue1;
	Queue1.Enqueue(1);
	Queue1.Enqueue(2);
	Queue1.Enqueue(3);
	Queue1.Enqueue(4);
	Queue1.Enqueue(5);
	Queue1.Enqueue(6);
	Queue1.displayQueue();
	
	//******** Top Element ********//
	cout << "Peek Element in queue : ";
	cout << Queue1.Peek();
	cout << " " << endl;
	
	//******** DeQueue ********//
	Queue1.Dequeue();
	cout << "After Dequeue: ";
	Queue1.displayQueue();
	

	 
		
	return 0;

}
