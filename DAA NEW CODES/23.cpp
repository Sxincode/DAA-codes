/* WEEK:12 , Q->1*/
// Given two sequences, Design an algorithm and implement it using a program to find the length
// of longest subsequence present in both of them. A subsequence is a sequence that appears in the
// same relative order, but not necessarily contiguous.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// int LCS(int i,int j,string &s,string &t,vector<vector<int>>& dp)
// {
//     if(i<0 || j<0) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(s[i]==t[j])
//     {
//         return dp[i][j]=1+LCS(i-1,j-1,s,t,dp);
//     }
//     return dp[i][j]=max(LCS(i-1,j,s,t,dp),LCS(i,j-1,s,t,dp));
// }
int main()
{
    string s1,s2;
    cout<<"Sequence 1:";
    cin>>s1;
    cout<<"Sequence 2:";
    cin>>s2;
    // vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
    // cout<<"Length:"<<LCS(s1.size()-1,s2.size()-1,s1,s2,dp);

    int n=s1.size();
    int m=s2.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    int i=n;
    int j=m;
    string ans="";
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            ans+=s1[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"LCS:"<<ans;
    cout<<"\nLCS Length:"<<dp[n][m];

    return 0;
}

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string str1,str2;
//     cout<<"Sequence1: ";
//     cin>>str1; 
//     cout<<"Sequence2: ";
//     cin>>str2;
//     int n=str1.size(),m=str2.size();
//     int t[n+1][m+1];
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             if(i==0||j==0)
//             {
//                 t[i][j]=0;
//             }
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             if(str1[i-1]==str2[j-1])
//             {
//                 t[i][j]=1+t[i-1][j-1];
//             }
//             else
//             {
//                 t[i][j]=max(t[i][j-1],t[i-1][j]);
//             }
//         }
//     }
//     string str="";
//     int i=n,j=m;
//     while(i>0&&j>0)
//     {
//     if(str1[i-1]==str2[j-1])
//     {
//         str+=str1[i-1];
//         i--;
//         j--;
//     }
//     else
//     {
//         if(t[i][j-1]>t[i-1][j])
//         j--;
//         else
//         i--;
//     }
//     }
//     reverse(str.begin(),str.end());
//     cout<<"Longest Common Subsequence: "<<str<<endl;
//     cout<<"Length = "<<t[n][m]<<endl;
// }