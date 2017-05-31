#include<iostream>
#include<limits.h>
using namespace std;

struct Matrix
{
	int x;
	int y;
};

int chaincost(Matrix mat[],int n)
{
	int dp[n][n];
	int i,j,l,k,q;
	for(l=1;l<=n;l++)
	{
		for(i=0;i<=n-l;i++)
		{
			j=i+l-1;
			if(j==i)
				dp[i][j]=0;
			else
			{
				dp[i][j]=INT_MAX;
				for(k=i;k<=j-1;k++)
				{
					q=dp[i][k]+dp[k+1][j]+mat[i].x*mat[j].y*mat[k].y;
					if(q<dp[i][j])
						dp[i][j]=q;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j<i)
				cout<<"-1\t";
			else
				cout<<dp[i][j]<<"\t";

		}
		cout<<"\n";
	}
	return dp[0][n-1];
}

int main()
{
	int i,n;
    //Matrix *mat;
	cout<<"Enter no. of matrices to multiply \n";
	cin>>n;
	//mat=new Matrix(n);
	Matrix mat[n];
	for(i=0;i<n;i++)
	{
		cin>>mat[i].x;
		cin>>mat[i].y;
	}
	cout<<"Cost of multiplication  "<<chaincost(mat,n)<<"\n";
}