#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct Avl
{
 public:
 int key=10;
 int height;
 Avl* left;
 Avl* right;
 Avl()
 {
     height =0;
     left   =NULL; 
     right  =NULL;
 }
};
int getHeight(Avl* node)
{
    if(node==NULL) return 0;
    return node->height;
}

int updateHeight(Avl* node)
{
    if(node==NULL) 
    return 0;

    return max(updateHeight(node->left),updateHeight(node->right))+1;
    
}
int getBalanceFactor(Avl* node)
{
        if(node==NULL) return 0;
        return getHeight(node->left)-getHeight(node->right);
}
Avl* rotateRight(Avl* node)
{
 if(node==NULL) return node;
 Avl* B=node->left;
 node->left=B->right;
 B->right=node;
 node->height=updateHeight(node);
 B->height=updateHeight(B);
 return B;
}

Avl* rotateLeft(Avl* node)
{
 
 if(node==NULL) return node;
 Avl* C=node->right;
 node->right=C->left;
 C->left=node;
 node->height=updateHeight(node);
 C ->height=updateHeight(C);
 return C;
}
Avl* rebalance(Avl* root,int key)
{
    int balanceFactor=getBalanceFactor(root);
    if(balanceFactor>1 && key < root->left->key)
    return rotateRight(root);
    
    else if(balanceFactor>1 && key > root->left->key)
    {
        root->left=rotateLeft(root->left);
        return rotateRight(root);
    }
    else if(balanceFactor<-1 && key > root->right->key)
    return rotateLeft(root);
    
    else if(balanceFactor<-1 && key< root->right->key)
    {
        root->right=rotateRight(root->right);
        return rotateLeft(root);
    }
return root;    
}
Avl* Insert(Avl *root,int key)
{
    if(root==NULL)
    {
        Avl* root = new Avl();
        root->key=key;
        return root;
    }
    
    if(key < root->key)
    {
        root->left=Insert(root->left,key);
        //root->left->height=updateHeight(root->left);
        root->height=updateHeight(root);
    }
    else if(key > root->key)
    {
        root->right=Insert(root->right,key);
        //root->right->height=updateHeight(root->right);
        root->height=updateHeight(root);
    }
    return rebalance(root,key);
}
Avl* inorderSucc(Avl* node)
{
    if(node->left==NULL) return node;
    return inorderSucc(node->left);
}
    
Avl* deleteNode(Avl*root,int key)
{
    if(root==NULL) return root;
    else if(key>root->key)  root->right=deleteNode(root->right,key);
    else if(key<root->key)  root->left=deleteNode(root->left,key);
    else // When element is found
    {
        if(root->left==NULL || root->right==NULL)
        {
                Avl* temp = root->left ? root->left : root->right;
                if(temp==NULL)
                {
                    temp=root;
                    root=NULL;
                }
                else
                {
                    *root = *temp;
                }
                free(temp);
            
        }
        else
        {
            Avl* temp=inorderSucc(root->right);
            root->key=temp->key;
            root->right=deleteNode(root->right,temp->key);
        }
    }

    if(root==NULL) return root;

    root->height=updateHeight(root);
    int balanceFactor=getBalanceFactor(root);

//rebalancing
    if(balanceFactor>1 && getBalanceFactor(root->left)>=0)
    {
        return rotateRight(root);
    }
    else if(balanceFactor>1 && getBalanceFactor(root->left)<0)
    {
        root->left=rotateLeft(root->left);
        return rotateRight(root);
    }
    else if(balanceFactor<-1 && getBalanceFactor(root->right)>=0)
        return rotateLeft(root);
    else if(balanceFactor<-1&& getBalanceFactor(root->right)<0)
    {
        root->right=rotateRight(root->right);
        return rotateLeft(root);
    }

return root;
}
void preorder(Avl*root)
{
    if(root==NULL) return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}

//Driver Function
int main()
{
    Avl* Tree=NULL;
    

    for(int i=0;i<10;i++)
    Tree=Insert(Tree,i);
    
    cout<<"Tree: ";
    preorder(Tree);
    cout<<endl;
    
    for(int i=0;i<10;i++)
    {
        Tree=deleteNode(Tree,i);
        preorder(Tree);
        cout<<endl;
    }
}


