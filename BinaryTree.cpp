#include<iostream>
using namespace std;

struct node{
	int number;
	struct node *left;
	struct node *right;
}*root, *temp, *newNode;

void addNode(int x)
{
	temp = root;
	newNode = new node;

	newNode->number = x;
	newNode->left = NULL;
	newNode->right = NULL;

	if(root == NULL)
    {
		root = newNode;
		return;
	}
	while(true)
	{
		if(temp->number > x)
		{
			if(temp->left==NULL)
			{
				temp->left=newNode;
				return;
			}
			temp = temp->left;
		}
		else
		{
			if(temp->right==NULL)
			{
				temp->right = newNode;
				return;
			}
			temp = temp->right;
		}
	}
}

void inOrder(node *temp)
{
	if(temp!=NULL)
    {
		inOrder(temp->left); // left
		cout<<temp->number<<" "; //root
		inOrder(temp->right); // right
	}
}

void preOrder(node *temp)
{
	if(temp!=NULL)
    {
		cout<<temp->number<<" "; //root
		preOrder(temp->left); // left
		preOrder(temp->right); // right
	}
}

void postOrder(node *temp)
{
	if(temp!=NULL)
    {
		postOrder(temp->left); // left
		postOrder(temp->right); // right
		cout<<temp->number<<" "; //root
	}
}

void searchNode(int number)
{
    temp= root;
    while(temp!=NULL)
    {
        if(temp->number==number)
        {
            cout<<"found";
            return;
        }
        if(temp->number>number)
            temp=temp->left;
        else
            temp=temp->right;
    }
    cout<<"not found";
}

void removeReplace(node *&nodePtr)
{

    node *temp = NULL;

    if (nodePtr == NULL)
        cout << "Can't delete empty node\n";
    else if (nodePtr->right == NULL)
    {
        temp = nodePtr;
        nodePtr = nodePtr->left; // add left child
        delete temp;
    }
    else if (nodePtr->left == NULL)
    {
        temp = nodePtr;
        nodePtr = nodePtr->right; // add right child
        delete temp;
    }

    else
    {
        temp = nodePtr->right;

        while (temp->left)
            temp = temp->left;
        temp->left = nodePtr->left;
        temp = nodePtr;
        nodePtr = nodePtr->right;
        delete temp;
    }
 }

void deleteNode(int num, node *&nodePtr)
{
    if (num < nodePtr->number)
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->number)
        deleteNode(num, nodePtr->right);
    else
        removeReplace(nodePtr);
}

int main()
{
    cout<<"sefira karina/2001586155 \n \n";

	addNode(3);
	addNode(2);
	addNode(4);
	addNode(41);
	addNode(5);
	addNode(10);
	addNode(20);
	addNode(1);
	addNode(6);
	addNode(9);

	inOrder(root);
	cout << endl;
	preOrder(root);
	cout << endl;
	postOrder(root);
	cout<<endl<<endl;

	cout<<"search 99 : ";
	searchNode(99);
	cout << endl;
	cout<<"search 20 : ";
	searchNode(20);

    cout<<"\n\ndelete 41";
    deleteNode(41,root);
    cout << endl;
    inOrder(root);
	cout << endl;
	preOrder(root);
	cout << endl;
    postOrder(root);

    cout<<"\n\ninsert 41";
    addNode(41);
    cout << endl;
    inOrder(root);
	return 0;
}
