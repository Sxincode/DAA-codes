// Given a (directed/undirected) graph, design an algorithm and implement it using a program
// to find if a path exists between two given vertices or not. (Hint: use DFS)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dfs(int i,vector<int> adj[],vector<int>& vis,int target)
{
    vis[i]=1;
    cout<<i<<" ";
    if(i==target) return 1;
    for(auto it:adj[i])
    {
        if(vis[it]==0)
        {
            return dfs(it,adj,vis,target);
        }
        else
        {
            return -1;
        }
    }
    return -1;
}
int main()
{
    int V;
    cout<<"Enter number of vertex:";
    cin>>V;
    vector<int> adj[V];
    for(int i=0;i<V;i++)
    {
        int x;
        cout<<"Enter number of edges from "<<i<<" :";
        cin>>x;
        if(x!=0) cout<<"Enter Edges:";
        while(x--)
        {
            int l;
            cin>>l;
            adj[i].push_back(l);
        }
    }
    vector<int> vis(V,0);
    int target;
    cout<<"Enter Target:";
    cin>>target;
    if(dfs(0,adj,vis,target)==1)
    {
        cout<<"Found!";
    }
    else
    {
        cout<<"Not Found!";
    }
    return 0;
}