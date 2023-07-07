// WEEK 9 : Q->2

// II. Given a knapsack of maximum capacity w. N items are provided, each having its own value and
// weight. You have to Design an algorithm and implement it using a program to find the list of the
// selected items such that the final selected content has weight w and has maximum value. You can
// take fractions of items,i.e. the items can be broken into smaller pieces so that you have to carry
// only a fraction xi of item i, where 0 ≤xi≤ 1.


#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    double r1=(double) a.first/a.second;
    double r2=(double) b.first/b.second;

    return r1>r2;

}
double fractionalknapsack(int n,pair<int,int> arr[],int bagsize)
{
    sort(arr,arr+n,cmp);
    double res=0.0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].second<=bagsize)
        {
            res+=arr[i].first;
            bagsize-=arr[i].second;
        }
        else
        {
            res=res+ arr[i].first*((double)bagsize/arr[i].second);
        }
    }
    return res;
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    pair<int,int> arr[n];
    cout<<"Enter Values with weights:";
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i]={a,b};
    }
    int bagsize;
    cout<<"Enter Bag size:";
    cin>>bagsize;
    double profit= fractionalknapsack(n,arr,bagsize);
    cout<<"Profit:"<<profit;
    return 0;
}