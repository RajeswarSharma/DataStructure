#include <iostream>

using namespace std;

int BST[1024]={0};
int counterRight=0,counterLeft=0;
bool isEmpty=true;

void Insert(int data)
{
 bool isInserted=false;
 int counter=0;
    while(!isInserted)
    {
        if(isEmpty||BST[counter]==0)
        {
            BST[counter]=data;
            isInserted=true;
            isEmpty=false;
        }
        else if(data<=BST[counter])
        {
            counter=counter*2+1;
            cout<<"Down Left"<<endl;
        }
        else if (data>BST[counter])
        {
            counter=counter*2+2;
            cout<<"Down Right"<<endl;
        }
    }
}
/*void Insert(int data)
{
    if(counter==0)
    {
    cout<<"Root Inserted"<<endl;
    BST[counter]=data;
    }
    else if(data<)
}*/
int main()
{

    int n;
    int data;
    cout<<"Number of Elements: "; cin>>n;
    while(n>=50)
    {
        cout<<"Number of Elements: "; cin>>n;
    }
    while(n)
    {
        cout<<"Data :"; cin>>data;
        Insert(data);
        n--;
    }
cout<<"Inserted...!"<<endl;
for(int i=0;i<10;i++)
    cout<<BST[i]<<"  ";
cout<<"Printed"<<endl;
return 0;
}
