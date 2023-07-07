// Given an unsorted array of integers, design an algorithm and a program to sort the array using
// insertion sort. Your program should be able to find number of comparisons and shifts ( shifts 
// - total number of times the array elements are shifted from their place) required for sorting the
// array.

// Insertion sort.
#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    int arr[20];
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter Element in array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Before Sorted:";
    print(arr,n);
    insertion_sort(arr,n);
    cout<<"After Sorted:";
    print(arr,n);
    return 0;
}