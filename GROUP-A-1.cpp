 /*
 SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50

GROUP-A-1.Consider telephone book database of N clients. Make use of a hash table
implementation to quickly look up client‘s telephone number. Make use of two collision 
handling techniques and compare them using number of comparisons required to find a set of 
telephone numbers.*/ 

//Header Files 

#include<iostream>
#include<string.h>
using namespace std;

struct node
{
  int v;
node* next;
}*HashTable[10];	//create hash table of size 10

class hashing
{   
public:
hashing()			// constructor of hashing class
{
for(int i=0 ; i<10 ; i++)  //initializaton
{
        HashTable[i]=NULL;	 // assign null value to hash table
    }
 }

int HashFunction(int v)
{
  return (v%10);   //division method used
 }
 node* create_node(int x)   //  create node
{
     node* temp=new node;
    temp->next=NULL;
    temp->v=x;
    return temp;
 }

 void display()
{
     for(int i=0 ; i< 10; i++)
{
        node * temp=new node;
        temp=HashTable[i];
        cout<<"a["<<i<<"] : ";
        while(temp !=NULL)
{
                cout<<" ->"<<temp->v;
                temp=temp->next;
         }
        cout<<"\n";
}
 }
//for searching 
int searchElement(int v)
{
     bool flag = false;
              int hash_val = HashFunction(v);
              node* entry = HashTable[hash_val];
              cout<<"\nElement found at : ";
              while (entry != NULL)
         {
                    if (entry->v==v)
                 {
                            cout<<hash_val<<" : "<<entry->v<<endl;
                            flag = true;
                     }
                    entry = entry->next;
              }
              if (!flag)
              return -1;
 }
//for deletion
 void deleteElement(int v)
{
     int hash_val = HashFunction(v);	//find the index of v using hashfunction
              node* entry = HashTable[hash_val];
              if (entry == NULL )	// no element is present 
              {
                 cout<<"No Element found ";
                      return;
              }

              if(entry->v==v)
{
                HashTable[hash_val]=entry->next;	//link pointer to next 
                return;
              }
              while ((entry->next)->v != v)
        {
                  entry = entry->next;
              }
              entry->next=(entry->next)->next;
 }

 //for insertion
 void insertElement(int v)
{
     int hash_val = HashFunction(v);	//index of v using hashfunction
              node* temp=new node;		//create temporary node
              node* head=new node;		//create head node
              head = create_node(v); //create node to be inseted as head node
              temp=HashTable[hash_val];//position element in hashtable
              if (temp == NULL)		
                               {
                              HashTable[hash_val] =head; //if temp null then insert head node in that position
                               }
              else
{
                 while (temp->next != NULL)	//traverse the hashtable until we get null
                {
                      temp = temp->next;
                   }    
                     temp->next =head;  	// when found null then insert head node in that position
              }
 }
};

int main()
{
    int ch;		//take choice
 int data,search,del;
    hashing h;	//object
    do
{
cout<<"\nTelephone : \n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit";
        cin>>ch;
        switch(ch)
{
            case 1:cout<<"\nEnter phone no. to be inserted : ";
                    cin>>data;
h.insertElement(data);
                 break;
            case 2:h.display();
                    break;
            case 3:cout<<"\nEnter the no to be searched : ";
                    cin>>search;

                 if (h.searchElement(search) == -1)
                            {
                                cout<<"No element found at key ";
                                 continue;
                            }
                    break;
            case 4:cout<<"\nEnter the phno. to be deleted : ";
                 cin>>del;
                 h.deleteElement(del);
                  cout<<"Phno. Deleted"<<endl;
                    break;
                }
        }while(ch!=5);
        return 0;

}



