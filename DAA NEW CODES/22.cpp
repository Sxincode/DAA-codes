// Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
// matrices together. To find the optimal solution, you need to find the order in which these
// matrices should be multiplied.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int func(int i,int j,vector<int> &arr,vector<vector<int>> &dp)
{
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j]+ func(i,k,arr,dp) +func(k+1,j,arr,dp);
        if(steps<mini) mini=steps;
    }
    return dp[i][j]=mini;
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        arr.push_back(b);
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<"Operations:"<<func(1,n-1,arr,dp);
    
    return 0;
}