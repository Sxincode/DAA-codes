// 13. Given a graph, design an algorithm and implement it using a program to find if a graph
// is bipartite or not. (Hint: use BFS)

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int bipartite(int node,vector<vector<int>> &adj,vector<int>&col,int color)
{
    col[node]=color;
    for(int i=0;i<adj[node].size();i++)
    {
        if(adj[node][i]==1)
        {
            if(col[i]==-1)
            {
                return bipartite(i,adj,col,!color);
            }
            else
            {
                if(col[i]==color)
                {
                    return -1;
                }
            }
        }
    }
    return 1;
}
int main()
{
    int V;
    cout<<"Enter V:";
    cin>>V;
    vector<vector<int>> adj(V,vector<int>(V,0));
    for(int i=0;i<V;i++)
    {
        cout<<"Enter number of edge from "<<i<<" :";
        int x;
        cin>>x;
        if(x!=0)cout<<"Enter Edges:";
        while(x--)
        {
            int l;
            cin>>l;
            adj[i][l]=1;
        }
    }
    vector<int> col(V,-1);
    if(bipartite(0,adj,col,0)==1)
    {
        cout<<"Bipartie!";
    }
    else
    {
        cout<<"Not Bipartite!";
    }
    return 0;
}