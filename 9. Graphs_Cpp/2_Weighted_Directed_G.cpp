
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
 
    return 0;
}
