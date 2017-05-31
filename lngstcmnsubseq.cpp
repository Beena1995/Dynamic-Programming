#include<iostream>
using namespace std;

int subseq(char* str1,char* str2,int l1,int l2)
{
	int dp[l2+1][l1+1];
	int i,j;
	for(i=0;i<=l2;i++)
	{
		for(j=0;j<=l1;j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(str1[j-1]==str2[i-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=(dp[i-1][j]>dp[i][j-1])?dp[i-1][j]:dp[i][j-1];
		}
	}
	for(i=0;i<=l2;i++)
	{
		for(j=0;j<=l1;j++)
			cout<<dp[i][j]<<"\t";
		cout<<"\n";
	}
	return dp[l2][l1];
}

int main()
{
	int i,j;
	char* str1=new char(10);
	char* str2=new char(10);
	cout<<"Enter string 1"<<"\n";
	for(i=0;i<6;i++)
	{
		cin>>str1[i];
		//if(str1[i]=='\n')
		//	break;
	}
	cout<<"Enter string 2"<<"\n";
	for(j=0;j<5;j++)
	{
		cin>>str2[j];
		//if(str2[j]=='\n')
		//	break;
	}
	int res=subseq(str1,str2,6,5);
	cout<<res<<endl;
}