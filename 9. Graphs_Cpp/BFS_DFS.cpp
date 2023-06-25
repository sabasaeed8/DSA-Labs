#include <iostream>
#include <string>
using namespace std;


struct node{
	int data;
	node* next;
};

struct List
{
    node *head;
};

//  ********** QUEUE *************** 
class Queue{
	public:
	node *first,*last;
	public:
		Queue(){             // Constructor
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
	
	bool IsEmpty(){
		if (first == NULL){
			return true;
		}
		else{
			return false;
		}
			
	}
};

// ******** STACK **************
class Stack{
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
			return true;
		}
		else{
			return false;
		}	
	}
};

// ******** GRAPH ************** 

class Graph
{
    private:
        int num_vertices;
        List* array;
    public:
        Graph(int num_vertices) // Constructor
        {
            this->num_vertices = num_vertices;
            array = new List [num_vertices];
            for (int i = 0; i < num_vertices; ++i)
                array[i].head = NULL;
        }
        
		 
        node* create_Node(int dest)
        {
            node* newNode = new node();
            newNode->data = dest;
            newNode->next = NULL;
            return newNode;
        }
        
	// ********** Adding new Edge *********	 
        void addEdge(int src, int dest)
        {
            node* newNode = create_Node(dest);
            newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = create_Node(src);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
        }
    
    // ********** Print Graph *********	 	 
        void printGraph()
        {
            
            for (int v = 0; v < num_vertices; ++v)
            {
                node* n = array[v].head;
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (n)
                {
                    cout<<"-> "<<n->data;
                    n = n->next;
                }
                cout<<endl;
            }
        }
    
    // ********* BFS **************
        void BFS(int starting_v) {
            bool *visited = new bool[num_vertices];
            for (int i = 0; i < num_vertices; i++){
            	visited[i] = false;
			}
                

            Queue queue;
            visited[starting_v] = true;
            queue.Enqueue(starting_v);

            while (!queue.IsEmpty()) {
            	int p = queue.Peek();
            	cout << p << ",";
            	queue.Dequeue();
            	node* v = array[p].head;
                while ( v != NULL) {
//                   int adjVertex = *v;
                   if (!visited[v->data]) {
                      visited[v->data] = true;
                      queue.Enqueue(v->data);
                    }
                    v= v->next;
                }
            }
        }
        
        // ********* DFS **************
        void DFS(int starting_v) {
            bool *visited = new bool[num_vertices];
            for (int i = 0; i < num_vertices; i++){
            	visited[i] = false;
			}
                

            Stack stack;
            visited[starting_v] = true;
            stack.push(starting_v);

            while (!stack.stack_empty()) {
            	int p = stack.topElement();
            	cout << p << ",";
            	stack.pop();
            	node* v = array[p].head;
                while ( v != NULL) {
//                   int adjVertex = *v;
                   if (!visited[v->data]) {
                      visited[v->data] = true;
                      stack.push(v->data);
                    }
                    v= v->next;
                }
            }
        }
};


int main(){
	cout << " Undirected Graph:" << endl;
    Graph graph1(5);
    graph1.addEdge(0, 2);
    graph1.addEdge(0, 4);
    graph1.addEdge(1, 4);
    graph1.addEdge(1, 3);
    graph1.addEdge(1, 2);
    graph1.addEdge(2, 3);
    graph1.addEdge(3, 4);
    graph1.addEdge(4, 2);
 
    // print the adjacency list representation of the above graph
    graph1.printGraph();
    cout << " " << endl;
    
    // BFS 
    cout << " BFS starting from vertex 0: ";
    graph1.BFS(0);
    cout << "                                                                                                                         " ;
                                                                                              
    
    // DFS	
    cout << " DFS starting from vertex 0: ";
    graph1.DFS(0);
    
      
    return 0;
    
}
 

	


