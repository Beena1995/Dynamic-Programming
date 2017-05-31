#include<iostream>
using namespace std;

int min(int a,int b,int c)
{
	if(a<b)
	{
		if(a<c)
			return a;
		else
			return c;
	}
	else
	{
		if(b<c)
			return b;
		else 
			return c;
	}
}

void maxsq(int m,int n,int** a)
{
	int i,j,max=0;
	int row,col;
	int dp[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==0||j==0)
				dp[i][j]=a[i][j];
			else
				{
					if(a[i][j]!=0)
					  dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
					else
						dp[i][j]=0;
				}
				if(max<dp[i][j])
					{
						max=dp[i][j];
						row=i;col=j;
					}
		}
	}
	cout<<max<<"\n";
    for(i=row;i>row-max;i--)
    {
    	for(j=col;j>col-max;j--)
    		cout<<a[i][j]<<" ";
    	cout<<"\n";
    }
}

main()
{
	int n,m;
	cin>>m>>n;
	int** a=new int*[m];
	for(int i=0;i<m;i++)
		a[i]=new int[n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	maxsq(m,n,a);
}