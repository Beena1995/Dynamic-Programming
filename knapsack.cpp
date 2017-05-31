#include<iostream>
 using namespace std;

 struct Item{
 	int* wt;
 	int* val;
 };

int knap(Item item,int n,int t)
{
	int dp[n][t+1];
	int i,j,m1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=t;j++)
	{
		if(j==0)
			dp[i][j]=0;
		
			
		else if(i==0)
			{if(i==0&&item.wt[i]<=j)
			        dp[0][j]=item.val[i];
		     else
		        	dp[0][j]=0;
		    }
		else if(item.wt[i]>j)
			dp[i][j]=dp[i-1][j];
		else
		{
			m1=item.val[i]+dp[i-1][j-item.wt[i]];
			if(m1>dp[i-1][j])
				dp[i][j]=m1;
			else
				dp[i][j]=dp[i-1][j];

		}
	}
    }
    for(i=0;i<n;i++)
    {
    	for(j=0;j<=t;j++)
    		cout<<dp[i][j]<<"\t";
    	cout<<"\n";
    }
    return dp[n-1][t];
}

 int main()
 {
 	int i,n,t;
 	Item item;

 	cout<<"Enter the no.of items\n";
 	cin>>n;
 	item.wt=new int(n);
 	item.val=new int(n);
 	for(i=0;i<n;i++)
 	{
 		cin>>item.wt[i];
 		cin>>item.val[i];
 	}
 	cout<<"Enter the max total wt"<<endl;
 	cin>>t;
 	cout<<"Max sum of values "<<knap(item,n,t)<<"\n";
 }