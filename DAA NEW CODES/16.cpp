// Given a directed graph with two vertices ( source and destination). Design an algorithm and
// implement it using a program to find the weight of the shortest path from source to destination
// with exactly k edges on the path.

#include<bits/stdc++.h>
#include<iostream>
#define V 4
#define INF INT_MAX
using namespace std;
int shortestdistance(int graph[][V],int u,int v,int k)
{
    if(k==0 && u==v) return 0;
    if(k==1 && graph[u][v]!=INF) return graph[u][v];
    if(k<=0) return INF;

    int res=INF;
    for(int i=0;i<V;i++)
    {
        if(graph[u][i]!=INF && u!=i && v!=i)
        {
            int rec_res= shortestdistance(graph,i,v,k-1);
            if(rec_res!=INF)
            {
                res=min(res,rec_res+graph[u][i]);
            }
        }
    }
    return res;

}
int main()
{
    int graph[V][V]={
                        {0,10,3,2},
                        {INF,0,INF,7},
                        {INF,INF,0,6},
                        {INF,INF,INF,0}
                    };
    int u=0,v=3,k=2;
    int x=shortestdistance(graph,u,v,k);
    if(x!=INF)
    {
        cout<<"Weight of the shortest path is:"<<x;
    }
    else
    {
        cout<<"No Path possible with "<<k <<" stops!";
    }
    return 0;
}