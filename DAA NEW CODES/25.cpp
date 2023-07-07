// WEEK 13

// Given an array of characters, you have to find distinct characters from this array. Design an
// algorithm and implement it using a program to solve this problem using hashing. (Time
// Complexity = O(n))

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }   
    map<char,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}