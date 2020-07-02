#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Avl
{
public:
  int data;
  int height;
  Avl *left;
  Avl *right;
    Avl ()
  {
    left = NULL;
    right = NULL;
    height = 0;
  }
};
int Get_height (Avl * node)
{
  if (node == NULL)
    return 0;
  return node->height;
}

int updateHeight (Avl * node)
{
  if (node == NULL)
    return 0;

  node->height=max (updateHeight (node->left), updateHeight (node->right)) + 1;
  return node->height;
}

int getBalanceFactor (Avl * node)
{
  return Get_height (node->left) - Get_height (node->right);
}

Avl *rotateRight (Avl * node)
{
 Avl *B=node->left;
 node->left=B->right;
 B->right=node;
 node->height=updateHeight(node);
 B->height=updateHeight(B);
}

Avl *rotateLeft (Avl * node)
{
  Avl *C = node->right;
  node->right = C->left;
  C->left = node;
  node->height =updateHeight(node);
  C->height    =updateHeight (C);
  return C;
}

Avl *insert (Avl * root,int key)
{
  if (root == NULL)
    {
      root =(Avl*)malloc(sizeof(Avl));
      root->data = key;
      return root;
    }
  else if (key <= root->data)
    {
      root->left = insert (root->left, key);
      root->height = updateHeight (root);
    }
  else if (key > root->data)
    {
      root->right = insert (root->right, key);
      root->height = updateHeight (root);
    }

//   root->height=updateHeight(root);
   int BalanceFactor = getBalanceFactor (root);
  
  if (BalanceFactor > 1 && key < root->left->data)
    {
      return rotateRight (root);
    }
  if (BalanceFactor > 1 && key > root->left->data)
    {
      root->left = rotateLeft (root->left);	//rotate left , root->left
      return rotateRight (root);	//rotate right root
    }
  if (BalanceFactor < -1 && key > root->right->data)
    {
      root=rotateLeft(root);//rotate left root
    }
  if (BalanceFactor < -1 && key < root->right->data)
    {
      root->right=rotateRight(root->right);//rotate right root->right
      return rotateLeft(root);//rotate left root
    }
return root;
}

void Preorder(Avl* root)
{
    if(root==NULL) return;
    
    cout<<root->data<<"  "; 
    
    Preorder(root->left);
   
    Preorder(root->right);
}
void BFS(Avl* root)
{
    queue<Avl*> List;
    if(root==NULL) return;
    List.push(root);
    while(!List.empty())
    {
        cout<<List.front()->data<<"  ";
        if(List.front()->left!=NULL) List.push(List.front()->left);
        if(List.front()->right!=NULL)List.push(List.front()->right);
        List.pop();
    }
}
int main ()
{
  Avl* Tree;
  int temp;
  for(int i=0;i<13;i++)
  {
      cin>>temp;
      Tree=insert(Tree,temp);
  }
cout<<"Preorder: ";
Preorder(Tree);
cout<<"\n";

cout<<"BFS:      ";
BFS(Tree);
  return 0;
}
