#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define INF 9999
using namespace std;
struct Graph
{
int vertices;
int edges;
int **AdjMatrix;
};
Graph* createGraph()
{
int v,u,weight=0;
Graph *G=(Graph*)malloc(sizeof(Graph));
cout<<"Number of Vertex : ";cin>>G->vertices;
cout<<"Number of Edges  : ";cin>>G->edges;
G->AdjMatrix=(int**)malloc(sizeof(int*)*G->vertices*G->vertices);

for(int i=0;i<G->vertices*G->vertices;i++)
    G->AdjMatrix[i]=(int*)malloc(sizeof(int));

for(int i=0;i<G->vertices;i++)
    for(int j=0;j<G->vertices;j++)
    {
        if(i==j) G->AdjMatrix[i][j]=0;
        else     G->AdjMatrix[i][j]=INF;
    }

cout<<" Adjacent Matrix Initiated "<<endl;
cout<<" Enter the Edges"<<endl;
for(int i=0;i<G->edges;i++)
    {
    try
        {
        cout<<"Vertex : ";cin>>u;
        cout<<"Vertex : ";cin>>v;
        if(u>=G->vertices||v>=G->vertices)
            throw 1;
        cout<<"Weight : ";cin>>weight;
        G->AdjMatrix[u][v]=weight;
        cout<<endl;
        }
    catch(int e)
        {
        cout<<"*******ERROR : Vertex-Pair does not exist*******"<<endl;
        i--;
        }
    }
return G;
}
Graph* flyodSol(Graph *G)
{
for(int k=0;k<G->vertices;k++)
    {
     for(int i=0;i<G->vertices;i++)
        {
            for(int j=0;j<G->vertices;j++)
            {
                if(G->AdjMatrix[i][k]+G->AdjMatrix[k][j] < G->AdjMatrix[i][j])
                    G->AdjMatrix[i][j]=G->AdjMatrix[i][k]+G->AdjMatrix[k][j];
            }
        }
    }
return G;
}

void display(Graph* G)
{
for(int i=0;i<G->vertices;i++)
    {
        for(int j=0;j<G->vertices;j++)
        {
            if(G->AdjMatrix[i][j]==INF) cout<<"INF\t";
            else cout<<G->AdjMatrix[i][j]<<"\t";
        }
    cout<<endl;
    }
}
int main()
{
Graph *G1;
G1=createGraph();
cout<<"#######Adjacency Matrix OF the Graph#########"<<endl;
display(G1);
cout<<"#########Applying Floyed's Algorithm#########"<<endl;
G1=flyodSol(G1);
display(G1);
    return 0;
}
