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