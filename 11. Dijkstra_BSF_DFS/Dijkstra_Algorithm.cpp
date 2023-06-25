#include <iostream>
#include <cstdlib>

using namespace std;
 
 
struct Node
{
    int data;
    int weight;
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
        Graph(int vertex)  //Constructor
        {
            this->vertex = vertex;
            array = new List [vertex];
            for (int i = 0; i < vertex; ++i)
                array[i].head = NULL;
        }
        
        
	// ********** Adding new Edge *********	 
        void addEdge(int src, int dest, int weight)
        {
            Node *temp = new Node();
	        temp->data = dest;
	        temp->weight = weight;
	        temp->next = array[src].head;
	        array[src].head = temp;
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
        
    // ********** Distance between nodes *********
	    float nodeDistance(int i,int j){
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
    
	// ********** Dijkstra Algorithm *********	
        int minDistance(int distance[] , bool visited[] ){ 
		    int min = INT_MAX,min_index;
			for (int v=0; v<vertex; v++){
				if (visited[v] == false && distance[v] <= min){
					min = distance[v],min_index = v;
				}
			} 
			return min_index;
		  
    
    }
    
	    int printSolution(int distance[], int n)
	    {
	        cout << "Vertex   Distance from Source\n";
	        for (int i = 0; i < vertex; i++)
	           cout << " \t\t \n", i, distance[i];
	    }
    // ********** Dijkstra Algorithm *********	
        void dijkstra( int src ){
        	int distance[vertex];
        	bool visited[vertex];
        	for(int v = 0; v<vertex; v++)
            {
               distance[v] = INT_MAX;
               visited[v] = false;    
            }
            
            distance[src] = 0;   // Source vertex distance is set 0  
			for(int v = 0; v<vertex; v++)
            { 
               int u = minDistance(distance,visited);
               visited[v] = true; 
			   
			   for(int v=0; v<vertex; v++){
			   	 int d = nodeDistance(u,v);
			   	 if(distance[u] + d < distance[v]){
			   	 	distance[v] = distance[u] + d;
					}
			   }   
            }  
			printSolution(distance, vertex); 
		}
		
	
        
};
 

 
int main()
{
    cout << " Weighted Directed Graph:" << endl;
    cout << " (vertex,weight)" << endl;
    Graph graph1(5);
    graph1.addEdge(0, 2, 1);
    graph1.addEdge(0, 4, 5);
    graph1.addEdge(1, 0, 6);
    graph1.addEdge(1, 3, 2);
    graph1.addEdge(1, 2, 3);
    graph1.addEdge(2, 3, 2);
    graph1.addEdge(3, 4, 8);
    graph1.addEdge(4, 2, 2);
 
    // print the adjacency list representation of the above graph
    graph1.printGraph();
    
    graph1.dijkstra(0);
 
    return 0;
}
