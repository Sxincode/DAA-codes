// Given an unsorted array of integers, design an algorithm and implement it using a program to
// find whether two elements exist such that their sum is equal to the given key element. (Time
// Complexity = O(n log n))
// Using Randomized Quick sort.
#include<iostream>
#include<time.h>
using namespace std;
int partition(int arr[],int s ,int e)
{
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<=e-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return (i+1);
}
int r_partition(int arr[],int s ,int e)
{
    srand(time(NULL));
    int random =s+rand()% (e-s);
    swap(arr[random],arr[e]);
    return partition(arr,s,e);
}
void quick_sort(int arr[],int s,int e)
{
    if(s<e)
    {
        int p=r_partition(arr,s,e);
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
void find_target(int arr[],int i,int j,int target)
{
    while(i<j)
    {
        if(arr[i]+arr[j]==target)
        {
            cout<<"Found:"<<arr[i]<<" "<<arr[j]<<endl;
            return;
        }
        else if(arr[i]+arr[j]>target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout<<"Not Found!"<<endl;
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
    int target;
    cout<<"Enter Target:";
    cin>>target;
    quick_sort(arr,0,n-1);
    cout<<"After Sorting:";
    print(arr,n);
    find_target(arr,0,n-1,target);
    return 0;
}