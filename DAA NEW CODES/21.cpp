//  Given an unsorted array of elements, design an algorithm and implement it using a program to find 
// whether majority element exists or not. Also find median of the array. A majority element is an 
// element that appears more than n/2 times, where n is the size of array


#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int> arr;
    cout<<"Enter Elements:";
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        arr.push_back(b);
    }
    unordered_map<int,int> m;
    unordered_map<int,int> ::iterator it;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second>(n/2))
        {
            cout<<"yes"<<endl<<it->first<<endl;
        }
    }
    return 0;
}