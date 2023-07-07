// 14. Given a directed graph, design an algorithm and implement it using a program to find
// whethercycle exists in the graph or not

/*
    Cycle detection in DAG can be done using:-
    1.DFS (Using path visited array).
    2.BFS (Using Topological sort).
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int dfs(int node,vector<int>& vis,vector<int>& path_visited,vector<int>adj[])
{
    vis[node]=1;
    path_visited[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            return dfs(it,vis,path_visited,adj);
        }
        if(path_visited[it])
        {
            return -1;
        }
        path_visited[it]=0;
    }
    return 1;
}
int main()
{
    int V;
    cout<<"Enter V:";
    cin>>V;
    vector<int> adj[V];
    for(int i=0;i<V;i++)
    {
        cout<<"Enter number of Edges from "<<i<<" :";
        int x;
        cin>>x;
        while(x--)
        {
            int l;
            cin>>l;
            adj[i].push_back(l);
        }
    }
    vector<int> vis(V,0);
    vector<int> path_visited(V,0);
    if(dfs(0,vis,path_visited,adj)==-1)
    {
        cout<<"Cycle Present!";
    }
    else
    {
        cout<<"Cycle not present!";
    }
    return 0;
}