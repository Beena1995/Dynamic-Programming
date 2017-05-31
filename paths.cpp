#include<iostream>
 
 using namespace std;

int paths(int m,int n,int *a,int row,int col)
{
	if(row==m-1&&col==n-1&&*((a+row*n)+col)==0)
		return 1;
	if(*((a+row*n)+col)==1)
		return 0;
	else
		{
			if(row<m&&col<n)
			return paths(m,n,(int*)a,row+1,col)+paths(m,n,(int*)a,row,col+1);
		    else if(row==m-1)
		    	return paths(m,n,(int*)a,row,col+1);
		    else
		    	return paths(m,n,(int*)a,row+1,col);
	    }

}

int dpaths(int m,int n,int *a,int row,int col)
{
	int p[m][n];
	if(row==m-1&&col==n-1&&*((a+row*n)+col)==0)
		return 1;
	if(p[row][col]!=0)
		p[row][col]=p[row+1][col]+p[row][col+1];
	if(*((a+row*n)+col)==1)
		return 0;

	else
	{
        if(row<m&&col<n)
		{
			p[row][col]=p[row+1][col]+p[row][col+1];
			p[row][col]=dpaths(m,n,(int*)a,row+1,col)+dpaths(m,n,(int*)a,row,col+1);
		}
	    else if(row==m-1)
		    	p[row][col]= paths(m,n,(int*)a,row,col+1);
		else
		    	p[row][col]= paths(m,n,(int*)a,row+1,col);
    }
    return p[row][col];
}

 int main()
 {
 	int i,j,row,col;
 	cout<<"Enter dimension of matrix:"<<"\n";
 	cin>>row>>col;
 	int a[row][col];
 	for(i=0;i<row;i++)
 	{
 		for(j=0;j<col;j++)
 			cin>>a[i][j];
 	}
 	cout<<"No. of paths:"<<paths(row,col,(int*)a,0,0)<<"\n";
 }