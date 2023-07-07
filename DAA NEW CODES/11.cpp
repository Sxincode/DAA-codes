// You have been given two sorted integer arrays of size m and n. Design an algorithm and
// implement it using a program to find list of elements which are common to both. (Time
// Complexity = O(m+n))


// EASy hai.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> cmp(vector<int> v1, vector<int> v2)
{
    int i=0,j=0;
    int n=v1.size();
    int m=v2.size();
    vector<int> ans;
    while(i<n && j<m)
    {
        if(v1[i]==v2[j])
        {
            ans.push_back(v1[i]);
            i++;
            j++;
        }
        else if(v1[i]>v2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return ans;
}
int main()
{
    vector<int> v1,v2,ans;
    int n;
    int m;
    cout<<"Enter Size of First array:";
    cin>>n;
    cout<<"Enter Size of Second array:";
    cin>>m;
    cout<<"Enter Element in first array:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v1.push_back(x);
    }
    cout<<"Enter Element in Second array:";
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        v2.push_back(x);
    }
    ans=cmp(v1,v2);
    cout<<"Intersection Array:";
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}

