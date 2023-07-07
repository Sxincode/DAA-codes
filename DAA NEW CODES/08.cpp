// Given an unsorted array of integers, design an algorithm and implement it using a program to
// sort an array of elements by partitioning the array into two subarrays based on a pivot element
// such that one of the sub array holds values smaller than the pivot element while another
// sub array holds values greater than the pivot element. Pivot element should be selected 
// randomly from the array. Your program should also find number of comparisons and swaps 
// required for sorting the array.

// Quick sort

#include<iostream>
using namespace std;

int partition(int arr[],int s ,int e)
{
    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<arr[s]) count++;
    }
    int pivot_index=s+count;
    swap(arr[s],arr[pivot_index]);
    int i=s,j=e;
    while(i<pivot_index && j>pivot_index)
    {
        while(arr[i]<arr[pivot_index])
        {
            i++;
        }
        while(arr[j]>arr[pivot_index])
        {
            j--;
        }
        if(i<pivot_index && j>pivot_index)
        {
            swap(arr[i],arr[j]);
        }
    }
    return pivot_index;
}
void quick_sort(int arr[],int s,int e)
{
    if(s<e)
    {
        int p=partition(arr,s,e);
        quick_sort(arr,s,p-1);
        quick_sort(arr,p+1,e);
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
    quick_sort(arr,0,n-1);
    cout<<"After Sorting:";
    print(arr,n);

    return 0;
}