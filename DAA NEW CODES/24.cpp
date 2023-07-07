// . Given a knapsack of maximum capacity w. N items are provided, each having its own value and
// weight. Design an algorithm and implement it using a program to find the list of the selected items 
// such that the final selected content has weight <= w and has maximum value. Here, you cannot
// break an item i.e. either pick the complete item or don't pick it. (0-1 property).

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>weight;
    vector<int>value;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        weight.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        value.push_back(x);
    }
    int W;
    cout<<"Enter bag size:";
    cin>>W;

    vector<vector<int>>dp(n,vector<int>(W+1,0));
    int i=weight[0];
    for(;i<=W;i++)
    {
        dp[0][i]=value[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            int nottake=0+dp[i-1][w];
            int take=INT_MIN;
            if(weight[i]<=w)
            {
                take=value[i]+dp[i-1][w-weight[i]];
            }
            dp[i][w]=max(take,nottake);
        }
    }
    vector<int> ans;
    int res=dp[n-1][W];
    int x=W;
    for(int i=n;i>0&& res>0;i--)
    {
        if(res==dp[i-1][W]) continue;
        else
        {
            ans.push_back(i);
            res-=value[i-1];
            W-=weight[i-1];
        }
    }
    cout<<"Value:"<<dp[n-1][x]<<endl;
    cout<<"Weights selected:";
    for(int i=0;i<ans.size();i++)
    {
        cout<<weight[ans[i]]<<" ";
    }
    cout<<"\nValues selected:";
    for(int i=0;i<ans.size();i++)
    {
        cout<<value[ans[i]]<<" ";
    }

    return 0;
}