// Given an unsorted array of positive integers, design an algorithm and implement it using a
// program to find whether there are any duplicate elements in the array or not. (use sorting)
// (Time Complexity = O(n log n))
#include<iostream>
using namespace std;
//Merge Sort.(nlogn)
void merge(int arr[],int s,int e ,int mid)
{
    int s1=mid-s+1;
    int s2=e-mid;
    int *l1=new int(s1);
    int *l2=new int(s2);
    int k=s;
    for(int i=0;i<s1;i++)
    {
        l1[i]=arr[k++];
    }
    for(int i=0;i<s2;i++)
    {
        l2[i]=arr[k++];
    }
    int i=0,j=0;k=s;
    while(i<s1 &&j<s2)
    {
        if(l1[i]<l2[j])
        {
            arr[k++]=l1[i++];
        }
        else
        {
            arr[k++]=l2[j++];
        }
    }
    while(i<s1)
    {
        arr[k++]=l1[i++];
    }
    while(j<s2)
    {
        arr[k++]=l2[j++];
    }
    delete[] l1;
    delete[] l2;
}
void merge_sort(int arr[],int s,int e)
{
    if(s<e)
    {
        int mid=s+(e-s)/2;
        merge_sort(arr,s,mid);
        merge_sort(arr,mid+1,e);
        merge(arr,s,e,mid);
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
void find_duplicate(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1]) 
        {
            cout<<"YES\n";
            return ;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[30];
    cout<<"Enter Element in array:";   
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    cout<<"After Sorting:";
    print(arr,n);
    cout<<"Duplicate:";
    find_duplicate(arr,n);

    return 0;
}