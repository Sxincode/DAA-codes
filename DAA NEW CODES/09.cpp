// Given an unsorted array of alphabets containing duplicate elements. Design an algorithm
// and implement it using a program to find which alphabet has maximum number of
// occurrences and print it. (Time Complexity = O(n)) (Hint: Use counting sort)
#include<iostream>
using namespace std;
int main()
{
    int ans[256]={0};
    char arr[20];
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter Element in array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        ans[arr[i]]++;
    }
    int max_index=0;
    for(int i=1;i<256;i++)
    {
        if(ans[i]>ans[max_index])
        {
            max_index=i;
        }
    }
    cout<<char(max_index)<<" "<<ans[max_index]<<endl;    
    return 0;
}
