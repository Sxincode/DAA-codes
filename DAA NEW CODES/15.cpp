// 15. After end term examination, Akshay wants to party with his friends. All his friends are living 
// as paying guest and it has been decided to first gather at Akshay’s house and then move towards
// party location. The problem is that no one knows the exact address of his house in the city.
// Akshay as a computer science wizard knows how to apply his theory subjects in his real life 
// and came up with an amazing idea to help his friends. He draws a graph by looking in to 
// location of his house and his friends’ location (as a node in the graph) on a map. He wishes to 
// find out shortest distance and path covering that distance from each of his friend’s location to 
// his house and then whatsapp them this path so that they can reach his house in minimum time. 
// Akshay has developed the program that implements Dijkstra’s algorithm but not sure about 
// correctness of results. Can you also implement the same algorithm and verify the correctness 
// of Akshay’s results? (Hint: Print shortest path and distance from friends’ location to Akshay’s 
// house)
//  Design an algorithm and implement it using a program to solve using Bellman- Ford's shortest
// path algorithm.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int V;
    cout<<"Enter V:";
    cin>>V;
    vector<pair<int,int>> adj[V];
    for(int i=0;i<V;i++)
    {
        int x;
        cout<<"Enter no of Edges from "<<i<<" :";
        cin>>x;
        while(x--)
        {
            int l ,h;
            cout<<"Enter node:";
            cin>>l;
            cout<<"Enter Weight:";
            cin>>h;
            adj[i].push_back({l,h});
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    vector<int> parent(V);
    for(int i=0;i<V;i++)
    {
        parent[i]=i;
    }
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int wt=it.first;
        int node=it.second;
        for(auto adjacent:adj[node])
        {
            int adj_n=adjacent.first;
            int adj_wt=adjacent.second;
            if(wt + adj_wt < dist[adj_n])
            {
                parent[adj_n]=node;
                dist[adj_n]=wt+adj_wt;
                pq.push({dist[adj_n],adj_n});
            }
        }
    }
    cout<<"Distance Array:";
    for(auto it:dist)
    {
        cout<<it<<" ";
    }
    cout<<"\nParent Array:";
    for(auto it:parent)
    {
        cout<<it<<" ";
    }
    cout<<"\nPaths:"<<endl;
    for(int i=0;i<V;i++)
    {
        int it=i;
        while(parent[it]!=it)
        {
            cout<<it<<" ";
            it=parent[it];
        }
        cout<<0<<endl;

    }

    return 0;
}