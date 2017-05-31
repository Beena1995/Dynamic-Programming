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

int minedit(char ch1[],char ch2[],int n1,int n2)
{
	int dp[n1][n2];
	int k,l;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			if(i==0||j==0)
			{
				if(i==0&&j==0)
				{
					if(ch1[0]==ch2[0])
					{
						dp[0][0]=0;
						k=0;
						l=0;
                    }
					else
					{
						dp[0][0]=1;
						k=1;
						l=1;
					}
				}
				else if(j==0)
					dp[i][j]=++k;
				else if(i==0)
					dp[i][j]=++l;
			}
			else
			{
				if(ch2[j]==ch1[i])
					dp[i][j]=dp[i-1][j-1];
				else
					dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
			}
		}
	}
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
	return dp[n1-1][n2-1];
}

main()
{
	int n1,n2;
	cin>>n1;
	char* ch1=new char[n1];
	for(int i=0;i<n1;i++)
		cin>>ch1[i];
	cin>>n2;
	char* ch2=new char[n2];
	for(int i=0;i<n2;i++)
		cin>>ch2[i];
	cout<<minedit(ch1,ch2,n1,n2)<<"\n";
}