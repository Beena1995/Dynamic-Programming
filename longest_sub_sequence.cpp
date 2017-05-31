#include<iostream>
#include<algorithm>
using namespace std;

int max(int a,int b)
{
	int m=(a>b)?a:b;
	return m;
}

void lngseq(int a[],int n)
{
	int i,j=0;
	int b[n];
	for(i=0;i<n;i++)
		b[i]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				b[i]=max(b[i],b[j]+1);
			}
		}
	}
	sort(b,b+n);
	cout<<b[n-1]<<"\n";
	for(i=0;i<n;i++)
		cout<<b[i]<<"\t";
	cout<<"\n";
}

main()
{
	int i,n=16;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	lngseq(a,n);
}