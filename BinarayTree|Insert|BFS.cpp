#include <iostream>
#include<stdlib.h>
using namespace std;
class Node{
public:
Node* left;
Node* right;
Node* getNode()
{
   Node* temp = new Node();
   return temp;
}
friend void BFS(Node*);

int data;
    Node()
    {
        data=0;
        left=NULL;
        right=NULL;
    }

Node* Insert(int dat,Node* root)
    {
    if(root==NULL)
        {
            root=getNode();
            root->data=dat;
        return root;
        }
    else if(dat<=root->data)
        {
         cout<<"Shifting Down Left"<<endl;
         root->left=Insert(dat,root->left);
        }
    else
        {
        cout<<"Shifting Down Right"<<endl;
        root->right=Insert(dat,root->right);
        }
return root;
    }
};

Node *Bin=NULL;

struct Qnode
{
Node *element;
Qnode *Next;
};

Qnode *Front=NULL;
Qnode *Rear=NULL;

void push(Node *B)
{
    Qnode* temp=new Qnode;
    temp->element=B;
    temp->Next=NULL;
    if(Front==NULL)
    {
        Front=Rear=temp;
    }
    else
    {
        Rear->Next=temp;
        Rear=temp;
    }
}
void pop()
{
if(Front == NULL)
    {
       Rear=NULL;
    }
else
    {
     Qnode* temp=Front;
     cout<<Front->element->data<<" ";
     Front=Front->Next;
     free(temp);
    }
}
void BFS()
{
Node * root = Bin;
if(root!=NULL)
    {
        push(root);
        while(Front)
            {
            root=Front->element;
            if(root->left!=NULL)  push(root->left);
            if(root->right!=NULL) push(root->right);
            pop();
            }
    }
else
    {
    cout<<"Tree is empty"<<endl;
    }

}
int main()
{

   int data;
   int n;
   cout<<"Number of Data: "; cin>>n;
   while(n)
   {
       cout<<"DATA :"; cin>>data;
       Bin=Bin->Insert(data,Bin);
       n--;
   }
BFS();
return 0;
}
