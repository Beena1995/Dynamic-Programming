#include<iostream>
using namespace std;

int binarysearch(int b[],int st,int lt,int s)
{
	if(lt<1)
		return 0;
	int mid=(st+lt)/2;
	if(b[mid]<s)
		return mid+1;
	else
		binarysearch(b,0,mid-1,s)

}

void lngseq(int a[],int n)
{
	int b[n];
	b[0]=a[0];
	int len=0,j=0,k;
	for(int i=1;i<n;i++)
	{
		if(a[i]>b[j])
		{
			b[j+1]=a[i];
			j++;
		}
		else
		{
			k=binarysearch(b,0,j,a[i]);
			b[k]=a[i];
		}
	}
	cout<<j<<"\n";
}

main(
{
	int n=16;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	lngseq(a,n);
})