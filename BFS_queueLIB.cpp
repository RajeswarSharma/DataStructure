#include<iostream>
#include<queue>
using namespace std;
class Node
{
public :
    int data;
    Node* left;
    Node* right;
    Node()
    {
        data=0;
        left=NULL;
        right=NULL;
    }
};

Node* Insert(Node* root,int data)
{
   if(root==NULL)
   {
       root=new Node();
       root->data=data;
   }
   else if(root->data>=data)
       root->left=Insert(root->left,data);
   else
       root->right=Insert(root->right,data);

return root;
}

void LevelOrderTraversal(Node* root)
{
    if(root!=NULL)
    {
        queue <Node*> Qnode;
        Node* temp=NULL;
        Qnode.push(root);
        while(!Qnode.empty())
        {
            temp=Qnode.front();
            cout<<temp->data<<" ";
            if(temp->left!=NULL) Qnode.push(temp->left);
            if(temp->right!=NULL) Qnode.push(temp->right);
            Qnode.pop();
        }
    }
else
    {
    cout<<"Tree is Empty"<<endl;
    }
}

int main()
{
    Node* bin=NULL;
    int n=10;
    int data;
    while(n)
    {   cout<<"Data : ";cin>>data;
        bin = Insert(bin,data);
        n--;
    }
LevelOrderTraversal(bin);
return 0;
}
