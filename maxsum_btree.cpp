#include<iostream>
using namespace std;
#include<climits>

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int data)
{
	Node* temp= new Node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int max_sum=INT_MIN;

int max(int a,int b)
{
	int m=(a>b)?a:b;
	return m;
}

int maxsum(Node* root)
{
	int root_left,root_right,temp1,temp2;
	if(root==NULL)
		return 0;
	root_left=maxsum(root->left);
	root_right=maxsum(root->right);
	temp1=root->data+root_left+root_right;
    temp2=(root->data,root->data+(max(root_left,root_right)));
    max_sum=max(max_sum,max(temp1,temp2));
    return temp2;
}

main()
{
	struct Node *root = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
	maxsum(root);
	cout<<max_sum<<"\n";
}