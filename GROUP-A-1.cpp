 /*
 SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50

GROUP-A-1.Consider telephone book database of N clients. Make use of a hash table
implementation to quickly look up client‘s telephone number. Make use of two collision 
handling techniques and compare them using number of comparisons required to find a set of 
telephone numbers.*/ 

//Header Files Used
#include<iostream>
#include<cstring>
using namespace std;

//Here created hash table of size-10
int Tablesize=10;

struct HashTable
{
	char Key[10];   //key means Client Name
	int Val;        //Value means Telephone No.

}HT1[10],HT2[10];    //HT1 Handles collision by linear probing
                     //HT2 Handles collision by quadratic probing


//Function to Initialse Keys and Values of Hash table
void init()
{
	int i;
	for(i=0;i<Tablesize;i++)
	{
		strcpy(HT1[i].Key,"....");
		HT1[i].Val=0;
	}
	
	for(i=0;i<Tablesize;i++)
	{
		strcpy(HT2[i].Key,"....");
		HT2[i].Val=0;
	}
}

// funnction for hash function
int HashFun(char key[])
{
  int i,index,sum=0;      //here used division method( technique where the hash value is obtained by taking the remainder of the division of the key by the size of the hash table.)
  
  for(i=0;key[i]!='\0';i++)
  {
  	sum=sum+key[i];
  }
  index=sum%Tablesize; 
  
  return index;
}

//function for Insertion in HT1

void insert_HT1(char Cname[],int Tele)     //insert (key,value)
{
	int i,id,index;
	
	index=HashFun(Cname);
	
     if(strcmp(HT1[index].Key,"....")==0)    //no collision 
     {
     	strcpy(HT1[index].Key,Cname);
     	HT1[index].Val=Tele;
     } 
     else                          
     {
     	while(strcmp(HT1[index].Key,"....")!=0)
     	{
     		index=(index+1)%Tablesize;
     	}
     	strcpy(HT1[index].Key,Cname);
     	HT1[index].Val=Tele;
     }
}

//function for insertion in HT2

void insert_HT2(char Cname[],int Tele)
{
	int i,index;
	index=HashFun(Cname);
	
	if(strcmp(HT2[index].Key,"....")==0)
	{
		strcpy(HT2[index].Key,Cname);
		HT2[index].Val=Tele;
	}
	else
	{
		i=1;
		int id=index;
		while(strcmp(HT2[id].Key,"....")!=0)
		{
			id=(index+i*i)%Tablesize;
			i++;
		}
	     strcpy(HT2[id].Key,Cname);
	     HT2[id].Val=Tele;
	}
}

//function to display Hash Tables
void display()
{
	int i;
	cout<<"\n\n------Hash Table 01------";
	cout<<"\n\nBucket(Key,Value)";
	for(i=0;i<Tablesize;i++)
	{
		cout<<"\n "<<i<<"-("<<HT1[i].Key<<","<<HT1[i].Val<<")";
	
	}
	cout<<"\n\n------Hash Table 02------";
	cout<<"\n\nBucket(Key,Value)";
	for(i=0;i<Tablesize;i++)
	{
		cout<<"\n "<<i<<"-("<<HT2[i].Key<<","<<HT2[i].Val<<")";
	
	}
}
//function to Search keys in hash table-1
void search_HT1(char Cname[])
{
	int index=HashFun(Cname);
	int cnt=1;
	int id=index;
	
	if(strcmp(HT1[id].Key,Cname)==0)
	{
		cout<<"\n\t"<<HT1[id].Key<<":"<<HT1[id].Val<<":"<<cnt;
	}
	else			 
	{
		int i=1;
		while(strcmp(HT1[id].Key,Cname)!=0)
		{
			id=(index+i)%Tablesize;
			i++;   
			cnt++; 
		}
	   cout<<"\n\t"<<HT1[id].Key<<":"<<HT1[id].Val<<":"<<cnt;
	}
}


//funtion to search keys in hash table-02
void search_HT2(char Cname[])
{
	int index=HashFun(Cname);
	int cnt=1;
	int id=index;
	
	if(strcmp(HT2[id].Key,Cname)==0)
	{
		cout<<"\n\t"<<HT2[id].Key<<":"<<HT2[id].Val<<":"<<cnt;
	}
	else			 
	{
		int i=1;
		while(strcmp(HT2[id].Key,Cname)!=0)
		{
			id=(index+i*i)%Tablesize;
			i++;   
			cnt++;  
		}
	   cout<<"\n\t"<<HT2[id].Key<<":"<<HT2[id].Val<<":"<<cnt;
	}
}

int main()
{
cout<<"\n\n--------Hash Table-----------";

init(); 
insert_HT1("Aishwarya",912245);
insert_HT1("Vidhi",912365);
insert_HT1("Trupti",962888);
insert_HT1("Minal",942345);
insert_HT1("Ovi",942185);
insert_HT1("Tina",962345);
insert_HT1("Sanvi",942345);
insert_HT1("Kirti",915345);



insert_HT2("Ridhi",912245);
insert_HT2("Vishwas",912365);
insert_HT2("Trisha",962888);
insert_HT2("Mina",942345);
insert_HT2("Oviya",942185);
insert_HT2("Natasha",962345);
insert_HT2("Sanika",942345);
insert_HT2("Krushna",915345);

display();

cout<<"\n\n-------Search in Hash Table-01-------";
cout<<"\n\n\tClient:Telephone:Comparisions";
cout<<"\n---------------------------------------------";
search_HT1("Ovi");
search_HT1("Tina");
search_HT1("Kirti");


cout<<"\n\n\n-------Search in Hash Table-02-------";
cout<<"\n\n\tClient:Telephone:Comparisions";
cout<<"\n---------------------------------------------";
search_HT2("Ridhi");
search_HT2("Oviya");
search_HT2("Sanika");
cout<<endl;
return 0;
}