#include <iostream>
#include <algorithm>
using namespace std;

class node
{
public:
int data;
int height;
node* left,*right;
node()
    {
        height=0;
        left=NULL;
        right=NULL;
    }
};
class Wrapper
{
  public:
    node*root1;
    node*root2;
Wrapper()
    {
        root1=NULL;
        root2=NULL;
    }
};
int get_height(node* root)
{
    if(root==NULL) return 0;
    return root->height;
}
int update_height(node* root)
{
 if(root==NULL) return 0;
 return max(update_height(root->left),update_height(root->right))+1;
}
node* rotateLeft(node* root)
{
 node*C=root->right;
 root->right=C->left;
 C->left=root;
 root->height=update_height(root);
 C->height=update_height(C);
 return C;
}
node* rotateRight(node* root)
{
    node*B=root->left;
    root->left=B->right;
    B->right=root;
    root->height=update_height(root);
    B->height=update_height(B);
    return B;
}
node*rightBalance(node*root)
{
   if(root==NULL) return root;

   node* rightNode=root->right;
   if( get_height(rightNode->left) > get_height(rightNode->right) )
   {
      rightNode=rotateRight(rightNode);
   }
   root->right=rightNode;
   return rotateLeft(root);
}
node* leftBalance(node*root)
{
    if(root==NULL) return 0;
    node* leftNode=root->left;
    if(get_height(leftNode->right) >get_height(leftNode->left))
    {
        leftNode=rotateLeft(leftNode);
    }
    root->left=leftNode;
    return rotateRight(root);
}
node* balance(node*root)
{
    if(root==NULL) return root;
    if(get_height(root->left) > get_height(root->right)+1)
    {
        root=leftBalance(root);
    }
    if(get_height(root->right)> get_height(root->left)+1)
    {
        root=rightBalance(root);
    }
root->height=update_height(root);
return root;
}
node*Insert(node* root,int data)
{
    if(root==NULL)
    {
        root=new node();
        root->data=data;
        return root;
    }
    else if(data<root->data)
    {
        root->left=Insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=Insert(root->right,data);
    }
return balance(root);
}
node* InorderSuccessor(node*root)
{
    if(root->left==NULL) return root;
    return InorderSuccessor(root->left);
}
node* Delete(node* root,int data)
{
    if(root==NULL) return root;
    else if(data<root->data) root->left=Delete(root->left,data);
    else if(data>root->data) root->right=Delete(root->right,data);
    else
        {
            if(root->left==NULL || root->right==NULL)
            {
                node* temp = root->left? root->left : root->right;
                if(temp==NULL)
                {
                    temp=root;
                    root=NULL;
                    free(temp);
                }
                else
                {
                    node* T = root;
                    root=temp;
                    free(T);
                }
            }
           else
            {
              node* temp= InorderSuccessor(root->right);
              root->data=temp->data;
              root->right=Delete(root->right,temp->data);
              root->right->height=update_height(root->right);
            }
        }
    if(root==NULL) return root;
    root->height=update_height(root);
    return balance(root);
}
void preOrder(node*root)
{
    if(root==NULL) return;
    cout<<root->data<<"  ";//<<" balance factor:"<<get_height(root->left)-get_height(root->right)<<endl;
    preOrder(root->left);
    preOrder(root->right);
}
node* Merge(node* root1,node* T , node *root2) // This algorithm is valid when all of the roots in root1 are smaller than the roots of root2
{
 int HeightDifference = get_height(root1)-get_height(root2);
 if(HeightDifference>=-1 && HeightDifference<=1)
    {
        T->left=root1;
        T->right=root2;
        T->height=update_height(T);
        return T;
    }
 else if( root1->height > root2->height)
    {
        root1->right=Merge(root1->right,T,root2);
        root1->height=update_height(root1);
        return balance(root1);
    }
 else if(root1->height < root2->height)
    {
       root2->left=Merge(root1,T,root2->left);
       root2->height=update_height(root2);
       return balance(root2);
    }
}
node* mergeDriver(node* root1,node*root2)
{
    node* T=new node();
    node* x=root1;
    while(x->right!=NULL && x!=NULL)
    {
      x=x->right;
    }
    T->data=x->data;
    root1=Delete(root1,T->data);
    return Merge(root1,T,root2);

}
Wrapper* split(node*root,int data)
{
 Wrapper *W=NULL;
    if(root==NULL)
    {
        return W;
    }

    if(root->data==data)
    {
        W=new Wrapper();
        node* temp=root;
        root=NULL;
        W->root1=temp->left;
        W->root2=temp->right;
        free(temp);
        return W;
    }
    else if(data<root->data)
    {

        W=split(root->left,data);
        if(W==NULL) return NULL;
        root->left=W->root2;
        root=balance(root);
        W->root2=root;
        return W;
    }
    else if(data>root->data)
    {

        W=split(root->right,data);
        if(W==NULL)
        {
            return NULL;
        }
        root->right=W->root1;
        root=balance(root);
        W->root1=root;
        return W;
    }
}
int main()
{
node* Root1=NULL;
node* Root2=NULL;
int tem;
for(int i=0;i<5;i++)
     Root1=Insert(Root1,i);
for(int i=5;i<20;i++)
     Root2=Insert(Root2,i);

cout<<"Tree 1 :  ";
preOrder(Root1);
cout<<"\nTree 2:  ";
preOrder(Root2);
cout<<"\n\nMerging...!"<<endl;
node* T=mergeDriver(Root1,Root2);
preOrder(T);
try
{
    cout<<"\nSplitting Node: "; cin>>tem;
    Wrapper* W=split(T,tem);
    if(W==NULL) throw -1;
    cout<<"\n\nsplitting....!"<<endl;
    cout<<"\nSegment 1: ";
    preOrder(W->root1);
    cout<<"\nSegment 2: ";
    preOrder(W->root2);
    cout<<endl;
}
catch(int e)
{
    cout<<"\n\n\n**ERR CODE -1 : Splitting node is undefined"<<endl;
}
return 0;
}
