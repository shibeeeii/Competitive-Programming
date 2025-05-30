#include<iostream>
#include<math.h>
#include<string.h>
#include<climits>
#include<cstdio>
using namespace std;
bool dp[1000][1000];
int arr[1000];
int main()
{
    int i,j,k,p,q,r,s,n,m=1,t;
    string str;
    cin>>n;
    while(n--)
    {
        cin>>str;
        p=str.length();
        for(i=0; i<p; i++)
        {
            dp[i][i]=true;
        }
        for(k=2; k<=p; k++)
        {
            for(i=0; i<p-k+1; i++)
            {
                j=k+i-1;
                if(k==2)
                {
                    dp[i][j]=(str[i]==str[j]);
                }
                else
                {
                    dp[i][j]=(str[i]==str[j]) && dp[i+1][j-1];
                }
            }
        }
        for(i=0; i<p; i++)
        {
            if(dp[0][i]==true)
            {
                arr[i]=0;
            }
            else
            {
                arr[i]=INT_MAX;
                for(j=0; j<i; j++)
                {
                    if(dp[j+1][i]==true && 1+arr[j]<arr[i])
                    {
                        arr[i]=1+arr[j];
                    }
                }
            }
        }
        cout<<"Case "<<m<<": "<<arr[p-1]+1<<endl;
        m++;
    }
    return 0;
}

// Palindrome Partitioning