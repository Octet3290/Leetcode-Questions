// C++ Program to return elements of left view of the binary tree

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp=new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
	// corner Case
	if(str.length() == 0 || str[0] == 'N')
	return NULL;
	
	//Creting vector of strings from input 
	// string after spliting by space
	vector<string> ip;
	
	istringstream iss(str);
	for(string str; iss >>str;)
	 ip.push_back(str);
	
	// create the root of the tree
	Node* root = newNode(stoi(ip[0]));
	
	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);
	
	// Starting from the second element
	int i=1;
	while(!queue.empty() && i< ip.size())
	{
		Node* currNode = queue.front();
		queue.pop();
		
		//Get the current node's value from the string
		string currVal = ip[i];
		
		// If the left child is not null
		if(currVal!= "N"){
			currNode->left = newNode(stoi(currVal));
			
		// Push it to the queue
		queue.push(currNode->left) 
		
		}
		
		// For the right child
		i++;
		if(i>= ip.size())
		break;
		currVal = ip[i];
		
		// If the right child is not null
		if(currVal !="N")
		{
			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));
			
			// push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}
	return root;
}

// Main fuction
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		getline(cin,s);
		Node* root=buildTree(s);
		vector<int> vec = leftView(root);
		for(int x:vec)
		cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int> res;
   queue<Node*> q;
   if(root == NULL) return res;
   q.push(root);
   while(!q.empty()){
       int n = q.size();
       res.push_back(q.front()->data);
       for(int i=0; i<n; i++){
           if(q.front()->left != NULL) q.push(q.front()->left);
           if(q.front()->right != NULL) q.push(q.front()->right);
           q.pop();
       }
   }
   return res;
}

