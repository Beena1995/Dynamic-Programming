#include<iostream>
#include<stack>
using namespace std;

int histogram(int n,int a[])
{
	int i=0,area,max_area=0,st=0,top;
	stack<int> s;
	s.push(i);
	for(i=1;i<n;i++)
	{
		if(a[i]>=a[s.top()])
			s.push(i);
		else
			{
				while(a[i]<a[s.top()])
				{
						top=s.top();
				        s.pop();
				        if(!s.empty())
				           area=a[top]*(i-s.top()-1);
				        else
					    {

						   area=a[top]*(i-st);
					    }
					    cout<<"area:"<<area<<" ";
					    if(max_area<area)
				           max_area=area;
				}
				s.push(i);
			}
			cout<<"\n";
			if(a[i]==0)
			st=i+1;
			
	}
	st=0;
	while(!s.empty())
	{
		top=s.top();
		s.pop();
		if(!s.empty())
		   area=a[top]*(i-s.top()-1);
        else
           area=a[top]*(i-st);
		if(max_area<area)
		   max_area=area;			    
	}
	cout<<max_area<<"\n";
	return max_area;
}

void maxrec(int m, int n,int** a)
{
	int i,j,max_area=0,area;
	int b[n];
	for(j=0;j<n;j++)
		b[j]=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			  b[j]=b[j]+a[i][j];
			else
				b[j]=0;
		}
		for(int k=0;k<n;k++)
			cout<<b[k]<<" ";
		cout<<"\n";
		area=histogram(n,b);
		if(max_area<area)
			max_area=area;
	}
	cout<<max_area<<"\n";
}

main()
{
	int m,n;
	cin>>m>>n;
	int **a=new int*[m];
	for(int i=0;i<m;i++)
		a[i]=new int[n];
	for(int i=0;i<m;i++)
		a[i]=new int[n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	maxrec(m,n,a);
}