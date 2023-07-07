// Week 9 Q:1->

// Given a graph, Design an algorithm and implement it using a program to 
// implement Floyd Warshall all pair shortest path algorithm.

#include<bits/stdc++.h>
#include<iostream>
#define V 4
#define INF INT_MAX
using namespace std;
int main()
{
    int matrix[V][V]={
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0}
    };
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(matrix[i][k]!=INF && matrix[k][j]!=INF)
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(matrix[i][j]==INF)
            {
                cout<<"INF"<<" ";
            }
            else cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
