/* 
 SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50
 GROUP-F-23. Department maintains a student information. The file contains roll number, name, division and 
 address. Allow user to add, delete information of student. Display information of particular employee. 
 If record of student does not exist an appropriate message is displayed. If it is, then the system displays 
 the student details. Use sequential file to main the data.
 */
//Header files 
#include <iostream>
using namespace std;

struct Node  //NOde structure For BST
{
    int marks;
    struct Node *l;
    struct Node *r;
} *r;

struct Node *createNode()   //create node function
{
    struct Node *tmp;
    tmp = new struct Node;
    cout << "\n\t Enter Marks : ";
    cin >> tmp->marks;
    tmp->l = NULL;
    tmp->r = NULL;
    return tmp;
}

void createBST()    create root functions
{
    if (r == NULL)
    {
        r = createNode();
        cout << "\n\t ## Root of BST Tree is created ##";
    }
}
//insert nodes in BST function
void insert(struct Node *Root, struct Node *newnode)
{
    if (newnode->marks < Root->marks)
    {
        if(Root->l == NULL)
        {
            Root->l = newnode;
        }
        else
        {
            insert(Root->l,newnode);
        }
    }
    else
    {
        if(Root->r == NULL)
        {
            Root->r = newnode;
        }
        else
        {
            insert(Root->r,newnode);
        }
    }
}
// void preorder traversal function
void preorder(struct Node *Root)
{
    if(Root != NULL)
    {
        cout<<" "<<Root->marks;
        preorder(Root->l);
        preorder(Root->r);
    }
}
//function to convert BST into MAX Heap Tree
void maxHeapify(struct Node *Parent)
{
    int val;
    val = Parent->r->marks;
    Parent->r->marks = Parent->marks;
    Parent->marks = val;
}

int main()   //main function
{
    int cnt,i,j;
    struct Node *newnode;
    cout<<"\n\n ## Create and Display MAX Heap Tree";
    r = NULL;
    i = j = 0;
    createBST();   //step1 create BST
    //step 2 insert nodes in BST
    cout<<"\n\n How many nodes to insert ? : ";
    cin>>cnt;
    for(i=0;i<cnt;i++)
    {
        newnode = createNode();
        insert(r,newnode);
    }
    cout<<"\n\n Preorder Traversal : ";  //step3 display BST
    preorder(r);

//step 4 convert BST into MAX Heap Tree
    maxHeapify(r);
    maxHeapify(r->l);
    maxHeapify(r->r);
    maxHeapify(r);
//step 5 display MAX Heap Tree
    cout<<"\n\n After Heapifying BST ";
    cout<<"\n\n Max Heap Tree Preorder Traversal : ";
    preorder(r);

    cout<<"\n\n Maximum Marks : "<<r->marks;
    cout<<"\n\n";
    return 0;
}