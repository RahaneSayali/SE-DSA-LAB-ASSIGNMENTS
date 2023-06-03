/*
 SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50
GROUP-F-25. Implementation of a direct access file -Insertion and deletion of a record from a direct access file
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout<<"\n\n ## Program to implement Random / Direct Access Files ##";
    ofstream fout;
    fout.open("One.txt",ios::out);
    cout<<"\n Writing into the file ...";

    cout<<"\n Location : "<<fout.tellp();
    cout<<"\n Line 01 : Do you know";
    fout<<"Do you know"<<endl;

    cout<<"\n Location : "<<fout.tellp();
    cout<<"\n Line 02 : Go to Hell";
    fout<<"Go to Hell"<<endl;

    cout<<"\n Location : "<<fout.tellp();
    cout<<"\n Line 03 : You are an idiot ";
    fout<<"You are an idiot"<<endl;

    cout<<"\n Location : "<<fout.tellp();
    fout.close();

    ifstream fin;

    fin.open("One.txt",ios::in);
    cout<<"\n Reading from the file \n";
    cout<<"\n Location : "<<fin.tellg();
    cout<<"\n Shift Control to ";
    fin.seekg(23,ios::beg);
    cout<<"\n Location "<<fin.tellg();
    cout<<"\n Reading \n ";
    char c;
    while(!fin.eof())
    {
        fin.get(c);
        cout<<c;
    }
    cout<<"\n Conclusion we have directly accessed the line 03 of this file ";
    fin.close();
}
