// Given an unsorted array of integers, design an algorithm and implement a program to sort this
// array using selection sort. Your program should also find number of comparisons and number 
// of swaps required.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;  
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[30];
    cout<<"Enter Element in array";   
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Before Sorting:";
    print(arr,n);
    selection_sort(arr,n);
    cout<<"After Sorting:";
    print(arr,n);

    return 0;
}