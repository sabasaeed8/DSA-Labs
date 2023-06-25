#include <iostream>
#include <string>
using namespace std;

class node{
	public:
		int data;
		node* next;
};
class link_list{
	public:
	node *head,*last;
	public:
		link_list(){             // Constructor
			head = NULL;
			last = NULL;		
		}
        ~link_list(){}            // destructor	
    //******** Adding new node to link list *********// 	
	node* add_node(int data){
		node *new_node = new node();
		new_node-> data = data;
		new_node-> next = NULL;
		if(head == NULL){   
			head = new_node;  // if head = null, our new node will be the first node
			last = new_node;
		}
		else{
			last->next = new_node;
			last = new_node;
	    }
		return head;		
	}
	
	//********* Empty Linked List **************//
	bool isEmpty() {
    //It returns true if linked list is empty otherwise false.
		if (head == NULL) {
			cout << "List is empty" << endl;
			return true;
		}
        else{
        	cout << "List is not empty" << endl;
        	return false;
		} 
    } 
    
    //********* Insertion at head ************* //
    node* insertAtHead(int x){   //insert at start of list
	    node* new_head = new node();
	    new_head -> data = x;
	    new_head-> next = head;
	    head = new_head;
	    return new_head;
}

    //********* Insertion at given index *********//
    node* insertNode(int index, int x){    //insert at the given index
        node* Node = new node();
        Node->data= x;
    	node * p = head;
    	int node_index = 0;
        while (node_index < index-1){
    		p = p->next;
    		node_index++;	
		}
		Node->next = p->next;
		p->next = Node;
		return head;   	
	}   
	
    //********* Insertion at end *********//
    node* insertAtEnd(int x){   //insert at end of list
	    node* Node = new node();
		node*n = head;
	    while (n->next != NULL){
	    	n= n->next;
		}
		Node->data = x;
		n->next = Node;
		Node->next= NULL;
		return head;
		
	} 
	
    // ************ Find node ***************//
	bool findNode(int x){  //search for data value x in the list
	node*n = head;
	while(n != NULL){
		if (n->data == x){
			cout << x << " is present in the linked list." << endl;
			return true;
		}
		else{
			cout << x << " is not present in the linked list." << endl;
			return false;
		}
		n=n->next;
		}		
	}
	
	// ************ Delete node ***************//
	bool deleteNode(int x){   //delete all occurrences of x
        node*n = head;
        while (head->data == x){
         head = head->next;
        }
        while(n->next != NULL){
            if(n->next->data == x){
                n->next = n->next->next;     
            }
            n= n->next;     
        } 
        return true; 
    }
	
	// ************ Delete from start ***************//
	bool deleteFromStart(){ //deletes starting node of list
	    node*n = head;
	    head = head->next;
	    delete n;
	    return true;
    } 
    
    // ************ Delete from end ***************//
    bool deleteFromEnd(){ //deletes last node of list
        node*n = head->next;
        node*p = head;
		while(n-> next != NULL){
			n= n->next;
			p = p->next;
		}  
		p->next = NULL; 
		delete n;
		return true; 
    }
    
    // ************ Display List ***************//
    void displayList(){
    	node* n = head;
    	if (head == NULL){
    		cout << "List is empty." << endl;
		}
    	while (n !=NULL){
    		cout << n->data << "->";
    		n = n->next;
		}
	}
	
	// ************ Reverse Linked_List ***************//
	node* reverseList(){   //reverses the linklist and returns a new list
	    node* previous = NULL;
	    node* current = head;  
	    while(current != NULL)
	    {   
	        node* next = current->next;
	    	current->next = previous;
	        previous = current;
	        current= next;
		}
		head = previous;
		return head;
	    
	} 
	
};	

    // ************ Sort the Linked_List ***************//
    node* sortList(node*list_head){  //sorts the input-ed list {
        node *i,*j;
        for (i=list_head;i->next!=NULL;i=i->next){
        	for (j=i->next;j!=NULL;j=j->next){
        		if (i->data > j->data){
        			int temp= i->data;
        			i->data = j->data;
        			j->data = temp;	
				}
			}	
	    }
		return list_head;           
	}
	
	//************ Remove Duplicates ***************//
    node* removeDuplicates(node *list_head){   //removes duplicates from list
        node *i = list_head;
        node *j = i->next;
        while(j!= NULL){
        	if (j->data == i->data){
        		node *temp = j;
        		j= j->next;
        		i->next=j;
        		delete temp;
			}
			else{
				i=j;
				j=j->next;
			}
		}
        return list_head;
	} 
	
	//************ Meger Lists ***************//
    node* mergeLists(node *list1_head, node *list2_head){ //merges two lists
        node* h1 = list1_head;
        node* mergeList;
        while (h1->next !=NULL){
    		h1 = h1->next;
		}
		h1->next = list2_head;
		return list1_head;
	}
	
	void displayList(node*head){
    	node* n = head;
    	while (n !=NULL){
    		cout << n->data << "->";
    		n = n->next;
		}
	}
	
    
int main(){
	//***** Creating a linked list********//
	cout << "Linked List 1 : ";
	link_list list1;
	list1.add_node(5);
	list1.add_node(8);
	list1.add_node(5);
	list1.add_node(6);
	list1.add_node(7);
	list1.add_node(8);
	list1.add_node(11);
	list1.add_node(2);
	list1.add_node(8);
	list1.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;
	//***** Check if list is empty or not *******//
	list1.isEmpty();
	cout << "                                                       " << endl;
	//***** Insertion at head *******//
	cout << "Insert 1 at Head: ";
	list1.insertAtHead(1);
	list1.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;
	//***** Insertion at given index *******//
	cout << "Insert 10 at index 3: ";
	list1.insertNode(3,10);
	list1.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;
	//***** Insertion at given index *******//
	cout << "Insert 11 at End : ";
	list1.insertAtEnd(11);
	list1.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;
	//*********** Find Node ******************//
	cout << "Find Node: " ;
	list1.findNode(1);
	cout << "                                                       " << endl;
	// *********** delete all occurrences of x *********//
	cout << "Delete Node 8: ";
	list1.deleteNode(8);
	list1.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;
	// *********** delete from Start *********//
    cout << "Delete from Start: ";
	list1.deleteFromStart();
	list1.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;
	// *********** delete from End *********//
	cout << "Delete from End: ";
	list1.deleteFromEnd();
	list1.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;
	// *********** Reverse List *********//
    cout << "Reverse List: ";
	list1.reverseList();
	list1.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;
    // *********** Sort List *********//
    cout << "Sorted List: ";
	sortList(list1.head);
	list1.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;
	// *********** Remove Duplicates *********//
    cout << "Remove Duplicates: ";
	removeDuplicates(list1.head);
	list1.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;   
	//***** Creating a linked list********//
	cout << "Linked List 1 : ";
	list1.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;
	cout << "Linked List 2 : ";
	link_list list2;
	list2.add_node(15);
	list2.add_node(14);
	list2.add_node(27);
	list2.add_node(16);
	list2.add_node(13);
	list2.add_node(11);
	list2.add_node(5);
	list2.add_node(28);
	list2.displayList();
	cout << " " << endl;
	cout << "                                                       " << endl;
	// *********** Merge Lists *********//
    cout << "Merge Lists: ";
    displayList(mergeLists(list1.head,list2.head));
	cout << " " << endl;
	cout << "                                                       " << endl;

	
    
}
