// Given a sorted array of positive integers, design an algorithm and implement it using a 
// program to find three indices i, j, k such that arr[i] + arr[j] = arr[k]

#include<iostream>
using namespace std;
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
    for(int i=0,j=1,k=2;i<n && j<n && k<n;)
    {
        if(arr[i]+arr[j]==arr[k])
        {
            cout<<arr[i]<<" + "<<arr[j]<<" = "<<arr[k]<<endl;
            return 0;
        }
        else if(arr[i]+arr[j]>arr[k])
        {
            k++;
        }
        else
        {
            if(j!=k-1) j++;
            else if(i!=j-1) i++;
            else
            {
                k++;
            }
        }

    }
    cout<<"No such pattern found!"<<endl;
    return 0;
}