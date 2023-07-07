// Given an array of nonnegative integers, design an algorithm and a program to count the number
// of pairs of integers such that their difference is equal to a given key, K.

#include<iostream>
using namespace std;
int main()
{
    int n;
    int arr[20];
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter Elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int diff;
    cout<<"Enter difference:";
    cin>>diff;
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(abs(arr[i]-arr[j])==diff)
            {
                count++;
            }
        }
    }
    cout<<"Count::"<<count<<endl;
    return 0;
}