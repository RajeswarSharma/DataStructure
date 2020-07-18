#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#define UNVISITED -1

using namespace std;

vector<int>nodeID;
vector<int>lowLink;
vector<bool>inStack;
stack<int>Stack;
int ID=0;
int components=0;

void DFS(vector<vector<int> >&adj,int counter)
{
  nodeID[counter]=lowLink[counter]=ID++;
  Stack.push(counter);
  inStack[counter]=true;
  int node;
  int temp;
  for(size_t i=0;i<adj[counter].size();i++)
  {
      node=adj[counter][i];
      if(nodeID[node]==UNVISITED) DFS(adj,node);
      if(inStack[node]) lowLink[counter]=min(lowLink[counter],lowLink[node]);
  }

if(nodeID[counter]==lowLink[counter])
    {
        temp=Stack.top();
        while(temp!=counter)
        {
            Stack.pop();
            inStack[temp]=false;
            temp=Stack.top();
        }
        Stack.pop();
        inStack[temp]=false;
        components++;
    }
return;
}


void number_of_strongly_connected_components(vector<vector<int> > &adj) {
   for(size_t i=0;i<adj.size();i++)
   {
       if(nodeID[i]==UNVISITED)
       {

           DFS(adj,i);
       }
   }
}

int main() {
  size_t n, m;

  std::cin >> n >> m;

  inStack.resize(n,false);
  lowLink.resize(n,0);
  nodeID.resize(n,UNVISITED);
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
number_of_strongly_connected_components(adj);
cout<<components;
return 0;
}
