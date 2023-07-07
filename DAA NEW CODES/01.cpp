// Given an already sorted array of positive integers, design an algorithm and implement it using 
// a program to find whether a given key element is present in the sorted array or not. For an array
// arr[n], search at the indexes arr[0], arr[2], arr[4],. ,arr[2k] and so on. 
// Once the interval (arr[2k]< key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
// to find the element
// key. (Complexity < O(n), where n is the number of elements need to be scanned for searching):
// Jump Search


// Idea:- Apply Jump search and then for that particular block apply linear search.
#include<iostream>
using namespace std;

int jump_search(int arr[],int n,int target)
{
    int i=0;
    while(i<n && target>arr[i])
    {
        i+=2;        
    }
    return min(i,n);
}
int linear_search(int arr[],int n,int target)
{
    int x=jump_search(arr,n,target);
    if(x==0) 
    {
        if(arr[0]==target) return 0;
        else return -1;
    }
    for(int i=x-2;i<x;i++)
    {
        if(arr[i]==target) return i;
    }
    return -1;
}
int main()
{
    int arr[30];
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter n Elements in array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target;
    cout<<"Enter Target:";
    cin>>target;
    int x=linear_search(arr,n,target); 
    if(x==-1) cout<<"No Element Found!"<<endl;
    else cout<<"Element Found at index:"<<x<<endl;
    return 0;
}