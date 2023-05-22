 /*
 SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50

GROUP-B-7. Construct an expression tree from the given prefix expression eg.
 +--a*bc/def and traverse it using postordertraversal(non recursive) and then delete the entire tree.
 */

//Header files
#include <iostream>
using namespace std;

//Input to Program
char postfix[10];

struct Node   //Node of Expression Tree
{
    char data;
    struct Node *left;
    struct Node *right;
} *Root;

struct Node* stack[5];   //stack to store Pointers of Nodes
int top = -1;

void pushSTK(struct Node *newnode)   //to push pointers in stack
{
    top++;
    stack[top] = newnode;
}

struct Node* popSTK()    //to pop pointers from stack
{
    struct Node *temp;
    temp = stack[top];
    top--;
    return temp;
}

//function to create new node
struct Node* createNode(char val)
{
    struct Node *newnode;
    newnode = new struct Node;
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

//function to create an expression tree
void createEXPTREE()
{
    int i;
    struct Node *newnode;
    cout<<"\n\n Enter the postfix expression : ";
    cin>>postfix;

    for(i=0;postfix[i] != '\0';i++)
    {                                  //if operand
        if(postfix[i] == 'a' || postfix[i] == 'b' || postfix[i] == 'c' || postfix[i] == 'd')
        {
            newnode = createNode(postfix[i]);
            pushSTK(newnode);
        }                              //if operand
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            newnode = createNode(postfix[i]);  //create new node for operand
            newnode->right = popSTK();  //pop an operand from stack and attach as right child
            newnode->left = popSTK();   //pop an operand from stack and attach as left child
            pushSTK(newnode);
        }
    }
    if(Root == NULL)
    {                   //pop pointer from stack and assign to root
        Root = popSTK();
        cout<<"\n\t Expression Tree is ready now";
    }
}
//function to display expressions tree in preorder
void preorderEXPTREE(struct Node *root)
{
    if(root)
    {
        cout<<" "<<root->data;
        preorderEXPTREE(root->left);
        preorderEXPTREE(root->right);
    }
}
//function to display expressions tree in inorder
void inorderEXPTREE(struct Node *root)
{
    if(root)
    {
        inorderEXPTREE(root->left);
        cout<<" "<<root->data;
        inorderEXPTREE(root->right);
    }
}
//function to display expressions tree in postorder
void postorderEXPTREE(struct Node *root)
{
    if(root)
    {
        postorderEXPTREE(root->left);
        postorderEXPTREE(root->right);
        cout<<" "<<root->data;
    }
}
//main function
int main()
{
    cout<<"\n\n A C++ Program To Create and Display an Expression Tree";
    Root = NULL;
    createEXPTREE();
    cout<<"\n\n Preorder Traversal of Expression Tree";
    preorderEXPTREE(Root);
    cout<<"\n\n Inorder Traversal of Expression Tree";
    inorderEXPTREE(Root);
    cout<<"\n\n Postorder Traversal of Expression Tree";
    postorderEXPTREE(Root);
    return 0;
}