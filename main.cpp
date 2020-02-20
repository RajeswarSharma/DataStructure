#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node{
int data;
node* next;
};
node*head=0,*ptr=0;
void Insert()
{
    node* newnode=(node*)malloc(sizeof(node));
    cout<<"Enter the Element: ";
    cin>>newnode->data;
    newnode->next=0;
    if(head==0)
    {
        head=ptr=newnode;
    }
else{
    ptr->next=newnode;
    ptr=newnode;
    }
}
void InsertBeg()
{
    node* newnode=(node*)malloc(sizeof(node));
    cout<<"Enter the data : ";
    cin>>newnode->data;
    newnode->next=head;
    head=newnode;
}
void InsertEnd()
{
 node* newnode=(node*)malloc(sizeof(node));
 cout<<"Enter the Element :";
 cin>>newnode->data;
 newnode->next=0;
 ptr->next=newnode;
 ptr=newnode;
}
void InsertPos()
 {  node*temp;

    temp=head;
    int pos;
    node* newnode=(node*)malloc(sizeof(node));
    cout<<"Enter the position : ";
    cin>>pos;
    int i=1;
    while(i<pos-1)
    {
    temp=temp->next;

    i++;
    }
cout<<"Enter the data : ";
cin>>newnode->data;
newnode->next=temp->next;
temp->next=newnode;
}
void Display()
{
  node* temp;
  temp=head;
  while(temp!=0)
  {
      cout<<temp->data<<" ";
      temp=temp->next;
  }
}
void Delete()
{
    node* temp;
if(head==0)
{
    cout<<"List is Empty\n";
}
else
    {
    temp=head;
    head=head->next;
    free(temp);
    }
}
int main()
{
    int option;
   for(int i=0;i<5;i++)
   {
       Insert();
   }

while(1)
 {
    cout<<"\nSelect the option \n(1)Insert at Beg \n(2)Insert at Position\n(3)Insert at end\n(4)Delete\n(0)Exit"<<endl;
    cin>>option;

    switch(option)
    {
        case 1: InsertBeg();
                Display();
                break;
        case 2: InsertPos();
                Display();
                break;
        case 3: InsertEnd();
                Display();
                break;
        case 4: Delete();
                Display();
                break;
        case 0: exit(0);
        default: cout<<"Invalid option\n";
    }

 }
    return 0;
}
