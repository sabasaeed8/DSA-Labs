#include <iostream>
#include <string>
using namespace std;


class Node{
	public:
	int key;
	Node *left;
	Node *right;
	};
class BST {
	public:
		Node *root;
	public:
	BST(){ // constructor
	   root = NULL;
   }
	~BST(){} // destructor
	// **************** IsEmpty ****************** //
	bool isEmpty(){
		if (root == NULL){
		   cout << "Tree is empty." << endl;
		   return true;
	}
		else{
		   cout << "Tree is not empty." << endl;
		   return false;
	}
	}
	
    // **************** Insert Node ****************** //
	Node* insertNode(int key){ //insert in BST 
	    Node *y = NULL;
	    Node *x = root;
	    Node *new_node = new Node();
		new_node-> key = key;
		new_node->left = NULL;
		new_node-> right = NULL;  
	    while (x != NULL){
			y = x;
			if (key < x->key){	
			    x = x->left;}   
			else{    
			    x = x->right;	   	
		    }        
	    }
		
	    if (y==NULL){
	    	root = new_node;
		}
		else if (key < y->key){
			y->left = new_node;
		}
		else {
			y->right = new_node;
		}
		return root;
		
    }
    
    // **************** Find Node ****************** //
	bool findNode(int key){ //search for data value x in the BST
        if (root == NULL){
        	return NULL;
		}
		if (key == root->key){
			cout << key << " is present" << endl;
        	return true;
		}
		else if (key < root->key){
			root = root->left;
			return findNode(key);
		}
		else {
			root = root->right;
			return findNode(key);
		}
		return false;		      
	}
	
	// **************** Delete Node ****************** //

    Node* findMin(Node* r)
    {
        if(r == NULL)
            return NULL;
        else if(r->left == NULL)
            return r;
        else
            return findMin(r->left);
    }
    
    Node * deleteNode(Node *root, int key)
   {
    if(root==NULL) 
        return NULL;
    else if(key < root->key) 
        root->left = deleteNode(root->left, key);
    else if(key > root->key) 
        root->right = deleteNode(root->right, key);
    else 
    {
        // Case1 : both childs are null
        if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			Node *temp = findMin(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right,temp->key);
		}
	}
    return root;
}    

    // **************** InOrderTraversal ****************** //
	void inOrderTraversal (Node *root) {//prints using in order traversal technique
	    if (root != NULL){
	      inOrderTraversal (root->left);
		  cout << root->key << " ";
		  inOrderTraversal (root->right);
     	}
	    
	}
	
	// **************** PreOrderTraversal ****************** //
	void preOrderTraversal (Node *root){ //prints using in pre traversal technique
        if (root != NULL){
          cout << root->key << " ";	
	      inOrderTraversal (root->left);  
		  inOrderTraversal (root->right);
     	}
    }
    
    // **************** PostOrderTraversal ****************** //
	void postOrderTraversal (Node *root){ //prints using in post traversal technique
	    if (root != NULL){
	      inOrderTraversal (root->left);  
		  inOrderTraversal (root->right);
		  cout << root->key << " ";
     	}
    }
	};
	

int main(){
	//***** Creating a BST ********//
	BST Tree1;
	Tree1.insertNode(50);
	Tree1.insertNode(30);
	Tree1.insertNode(20);
	Tree1.insertNode(40);
	Tree1.insertNode(70);
	Tree1.insertNode(60);
	Tree1.insertNode(80);
	
	// **************** InOrderTraversal ****************** //
	cout << "Inorder Traversal: ";
	Tree1.inOrderTraversal(Tree1.root);
	cout << "                                                       " << endl;
	
	// **************** PreOrderTraversal ****************** //
	cout << "Preorder Traversal: ";
	Tree1.preOrderTraversal(Tree1.root);
	cout << "                                                       " << endl;
	
	// **************** PostOrderTraversal ****************** //
	cout << "Postorder Traversal: ";
	Tree1.postOrderTraversal(Tree1.root);
	cout << "                                                       " << endl;
	
	//***** Check if list is empty or not *******//
	Tree1.isEmpty();
	cout << "                                                       " << endl;
	
	//***** Find Node *******//
	cout << "Find Node: ";
	Tree1.findNode(80); 
	cout << "                                                       " << endl;
	
	
	return 0;
}

