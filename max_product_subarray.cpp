#include<iostream>
#include<limits.h>

using namespace std;

int maxProduct(const int* A, int n1) {
    int dp[n1][n1];
    int i,j,max=INT_MIN;
    for(i=0;i<n1;i++)
    {
        for(j=i;j<n1;j++)
        {
            if(i==j)
            {
                dp[i][j]=A[i];
            }
            else
                dp[i][j]=A[j]*dp[i][j-1];
            if(max<dp[i][j])
                max=dp[i][j];
        }
    }
    return max;
}

int main()
{
    int arr[4]={2,3,-2,4};
    cout<<maxProduct(arr,4)<<"\n";
}