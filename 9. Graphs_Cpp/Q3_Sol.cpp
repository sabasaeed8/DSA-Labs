// Lab9 (2019-CE-04)(SABA) 
#include <iostream>
#include <cstdlib>
using namespace std;
 
 
struct Node
{
    int data;
    float weight;
    Node* next;
};
 
struct List
{
    Node *head;
};
 

class Graph
{
    private:
        int vertex;
        List* array;
    public:
        Graph(int vertex)  // Constructor
        {
            this->vertex = vertex;
            array = new List [vertex];
            for (int i = 0; i < vertex; ++i)
                array[i].head = NULL;
        }
        
		 
        Node* create_Node(int dest,float weight)
        {
            Node* newNode = new Node();
            newNode->data = dest;
            newNode->weight = weight;
            newNode->next = NULL;
            return newNode;
        }
        
	// ********** Adding new Edge *********	  
        void addEdge(int src, int dest, float weight)
        {   
            
            Node* newNode = create_Node(dest,weight);
            newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = create_Node(src,weight);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
        }
    
    // ********** Tunnel Width *********
	    float tunnelWidth(int i,int j){
	    	Node *src = array[i].head;
	    	if (src->data == j){
	    	    return src->weight;	
			}
	    	while(src){
	    		if (src->next->data ==j){
	    			return src->next->weight;	
				}
	   		    src = src->next;
			}
	    	
        }    
        
    // ********** Path from source to destination *********
   //   Running time: O(number of nodes visited + number of edges scanned) = O(m + n). 
	    bool IsPathExists(int i,int j,int x){
	    	if (i==j){
	    		return true;
			}		
	    	Node *src = array[i].head;
	    	while(src->next != NULL){
    		    if(tunnelWidth(i,src->data) >= x){ 
    		        i = src->data;
					break;
				}
    		    src = src->next; 
            }
        }
        
        
        
    // ********** Largest x that can accomodate from vs to vt *********
	    float largestWidth(int i,int j){
	    	if (i> j){
	    		int temp = i;
	    		i=j;
	    		j=temp;		
			}
	    	bool p = true;
	    	float ans;
	    	if (p == true){
	    		ans = tunnelWidth(i,array[i].head->data) ;
			}
	    	if (i==j){
	    		return ans ;
			}		
	    	Node *src = array[i].head;
	    	while(src->next != NULL){
	    		p = false;
	    		float x = tunnelWidth(i,src->data);
    		    if(ans >= x ){  
    		        ans =  x;
    		        i = src->data;
		         	break;
				}
    		    src = src->next; 
            }
        }
		    	
	  	
				   	
	// ********** Print Graph *********	 	 
        void printGraph()
        {
            
            for (int v = 0; v < vertex; ++v)
            {
                Node* n = array[v].head;
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (n)
                {
                    cout<<"->("<<n->data << "," << n->weight <<")";
                    n = n->next;
                }
                cout<<endl;
            }
        }
};
 

int main()
{   
    cout << " Weighted Undirected Graph:" << endl;
    cout << " (vertex,weight)" << endl;
    Graph graph1(5);
    graph1.addEdge(0, 1, 3.1415);
    graph1.addEdge(0, 2, 1.1);
    graph1.addEdge(0, 3, 2);
    graph1.addEdge(1, 4, 2);
    graph1.addEdge(2, 3, 3.3);
    graph1.addEdge(3, 4, 2.1);
    
    
    // print the adjacency list representation of the above graph
    graph1.printGraph();
    cout << "                                                       " << endl;
    
    
    // ****** Tunnel width ******* 
    cout << " Tunnel width between vertices 0 and 1 : " << graph1.tunnelWidth(0,1) << endl ;
    cout << "                                                       " << endl;
    
    
    // ****** Is Path Exists ******* 
    cout << " Is Path exists from 0 to 4 if x=2 : " ;
    if (graph1.IsPathExists(0,4,2)== true){
    	cout << "True";
	}
	else{
		cout << "False";
	}
	cout << "                                                       " << endl;
	
	cout << " Is Path exists from 0 to 4 if x=3 : " ;
    if (graph1.IsPathExists(0,4,3)== true){
    	cout << "True";
	}
	else{
		cout << "False";
	}
	cout << "                                                       " << endl;
	
	
	// ********** Largest x that can accomodate from vs to vt *********
	cout << " Largest x that can accomodate from 0 to 4 : " << graph1.largestWidth(0,4);
	cout << "                                                       " << endl;
	
	
	
	
    return 0;
}

