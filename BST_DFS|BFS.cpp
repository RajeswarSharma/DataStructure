#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int   data;
    Node* left;
    Node* right;
    Node()
    {
        data=0;
        left=NULL;
        right=NULL;
    }
Node* Insert(Node* root,int dat)
    {
     if(root==NULL)
     {
         root=new Node();
         root->data=dat;
         cout<<"Inserted"<<endl;
     }
    else if(root->data>=dat)
        {
            cout<<"Shift Down Left"<<endl;
            root->left=Insert(root->left,dat);
        }
    else
        {
            cout<<"Shift Down Right"<<endl;
            root->right=Insert(root->right,dat);
        }
    return root;
    }
};
void preOrderTraversal(Node* root)
{
    if(root!=NULL)
    {
       cout<<root->data<<" ";
       preOrderTraversal(root->left);
       preOrderTraversal(root->right);
       return;
    }
 return;
}
void inOrderTraversal(Node* root)
{
    if(root!=NULL)
    {
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    return;
    }
return;
}

void postOrderTraversal(Node* root)
{
    if(root!=NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
    return;
    }
return;
}
void LevelOrderTraversal(Node* root)
{
    if(root!=NULL)
    {
       Node* temp=NULL;
       queue <Node*> Qnode;
       Qnode.push(root);
       while(!Qnode.empty())
        {
            temp=Qnode.front();
            cout<<temp->data<<" ";
            if(temp->left!=NULL) Qnode.push(temp->left);
            if(temp->right!=NULL)Qnode.push(temp->right);
            Qnode.pop();
        }

    }
return;
}
int main()
{
    Node* Bin=NULL;
    int n;
    int data;
    cout<<"Size: ";cin>>n;
    while(n)
    {
    cout<<"Data : "; cin>>data;
    Bin=Bin->Insert(Bin,data);
    n--;
    }
cout<<"<root><left><right> :";
preOrderTraversal(Bin);
cout<<"\n<left><root><right> :";
inOrderTraversal(Bin);
cout<<"\n<left><right><root> :";
postOrderTraversal(Bin);
cout<<"\nBFS                 :";
LevelOrderTraversal(Bin);
return 0;
}
