/*
SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50

GROUP-B-6. Beginning with an empty binary search tree, Construct binary search tree by 
inserting the values in the order given. After constructing a binary tree - 
i. Insert new node 
ii. Find number of nodes in longest path from root 
iii. Minimum data value found in the tree 
iv. Change a tree so that the roles of the left and right pointers are swapped at every node 
v. Search a value
*/

//header files
#include <iostream>

using namespace std;

int level = 0;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} *Root,*Parent;

//function to create root of BST
void createBST(int val)
{
    struct Node *Newnode;

    Newnode = new struct Node;

    Newnode->data = val;
    Newnode->left = NULL;
    Newnode->right = NULL;

    if(Root == NULL)
    {
        Root = Newnode;
        cout<<"\n\t Root "<<Root->data<<" of BST is Ready Now ";
    }
    else
    {
        cout<<"\n\t Root already exists";
    }
}

//function to display BST in Pre-Order_BST
//data-leftlright
void preorderBST(struct Node *root)
{
    if(root!=NULL)
    {
        cout<<" "<<root->data;
        preorderBST(root->left);
        preorderBST(root->right);
    }
}

//Function to display BST in Inorder_BST
//(Left->Data->Right)
void inorderBST(struct Node *root)
{
    if(root!=NULL)
    {
        preorderBST(root->left);
        cout<<" "<<root->data;
        preorderBST(root->right);
    }
}

//Function to display BST in Postorder_BST
//(Left->Right->Data)
void postorderBST(struct Node *root)
{
    if(root!=NULL)
    {
        preorderBST(root->left);
        preorderBST(root->right);
        cout<<" "<<root->data;
    }
}

//Function to create New Node
struct Node* createNode(int val)
{
    struct Node *Newnode;

    Newnode = new struct Node;

    Newnode->data = val;
    Newnode->left = NULL;
    Newnode->right = NULL;

    return Newnode;
}

//Function to Insert New Nodes in BST
void insertBST(struct Node *current, struct Node *Newnode)
{
    if(current!=NULL)
    {
        if(Newnode->data <= current->data)
        {
            if(current->left == NULL)
            {
                current->left = Newnode;
                cout<<"\n\n Newnode "<<Newnode->data<<" is inserted as left child of "<<current->data;
            }
            else
            {
                insertBST(current->left,Newnode);
            }
        }
        else
        {
            if(current->right == NULL)
            {
                current->right = Newnode;
                cout<<"\n\n Newnode "<<Newnode->data<<" is inserted as right child of "<<current->data;
            }
        }
    }
    else
    {
        insertBST(current->right,Newnode);
    }
}

void searchNode(struct Node *root, int Key)
{
    if(root!=NULL)
    {
        if(Key == root->data)
        {
            cout<<"\n\t Key is found on level "<<level;
        }
        else if(Key < root->data)
        {
            level++;
            searchNode(root->left,Key);
        }
        else
        {
            level++;
            searchNode(root->right,Key);
        }   
    }
    else
    {
        cout<<"\n\t Key not found";
    }
}

void minNode()
{
    struct Node *p;

    p = Root;
    while(p->left != NULL)
    {
        p = p->left;
    }
    cout<<"\n\n Min Value : "<<p->data;
}

void maxNode()
{
    struct Node *p;

    p = Root;
    while(p->right != NULL)
    {
        p = p->right;
    }
    cout<<"\n\n Max Value : "<<p->data;
}

struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
/* loop down to find the leftmost leaf */
    while(current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct Node *deleteNode(struct Node *root, int Key)
{
    if(root = NULL)
    {
        return root;
    }
    //If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if(Key < root->data)
    {
        root->left = deleteNode(root->left,Key);
    }
    //If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if(Key > root->data)
    {
        root->right = deleteNode(root->right,Key);
    }
    else
    {
        // node has no child
        if(root->left == NULL and root->right == NULL)
        {
            return NULL;
        }
        // node with only one child or no child
        else if(root->left == NULL)
        {
            struct Node* temp = root->right;
            delete root;
            return temp;
        }
        
        else if(root->right == NULL)
        {
            struct Node* temp = root->left;
            delete root;
            return temp;
        }
       // node with two children: Get the inorder successor
        struct Node* temp = minValueNode(root->right);
    
      // Copy the inorder successor's content to this node
        root->data = temp->data;
      
      // Delete the inorder successor
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

int main()
{
    cout<<"\n\n Binary Search Tree and its operations ";
    struct Node *Newnode;
    int Key;

    Root = NULL;
    cout<<"\n\n Creating BST";
    createBST(25);
    cout<<"\n\n Inserting new nodes in BST";
    Newnode = createNode(10);
    insertBST(Root,Newnode);
    Newnode = createNode(20);
    insertBST(Root,Newnode);
    Newnode = createNode(30);
    insertBST(Root,Newnode);
    Newnode = createNode(40);
    insertBST(Root,Newnode);
    cout<<"\n\n Display / Traversing BST";
    cout<<"\n\n Preorder Traversal";
    preorderBST(Root);
    cout<<"\n\n Inorder Traversal";
    inorderBST(Root);
    cout<<"\n\n Postorder Traversal";
    postorderBST(Root);
    cout<<"\n\n Searching a Key in BST";
    cout<<"\n\n Enter the key to search : ";
    cin>>Key;
    searchNode(Root,Key);
    cout<<"\n\n Find Max and Min Nodes";
    minNode();
    maxNode();
    cout<<"\n\n Delete a Key from BST";
    level = 0;
    Root = deleteNode(Root,20);
    cout<<"\n\n After Deleting Inorder Traversal";
    inorderBST(Root);
    Root = deleteNode(Root,30);
    cout<<"\n\n After Deleting Inorder Traversal";
    inorderBST(Root);
    Root = deleteNode(Root,40);
    cout<<"\n\n After Deleting Inorder Traversal";
    inorderBST(Root);
    return 0;
}