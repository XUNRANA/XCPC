#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}a[1600];
int ans[40][40];
void f(int n)
{
	int i=1,x1,y1;
	while(i<=n*n)
	{
	    if(i==1) 
		{
			a[i].x=1;
			a[i].y=(n+1)/2;
		}
	    else if(a[i-1].x==1&&a[i-1].y!=n)
	    {
	    	a[i].x=n;
	    	a[i].y=a[i-1].y+1;
		}
		else if(a[i-1].x!=1&&a[i-1].y==n)
		{
			a[i].x=a[i-1].x-1;
	    	a[i].y=1;
		}
		else if(a[i-1].x==1&&a[i-1].y==n)
		{
			a[i].x=a[i-1].x+1;
	    	a[i].y=a[i-1].y;
		}
		else if(a[i-1].x!=1&&a[i-1].y!=n)
		{
			x1=a[i-1].x-1;
			y1=a[i-1].y+1;
			int f=0;
			for(int j=1;j<i-1;j++) 
			if(a[j].x==x1&&a[j].y==y1) 
			{
				f=1;
				break;
			}
			if(f==1) 
			{
				a[i].x=a[i-1].x+1;
	    	    a[i].y=a[i-1].y;
		    }
			else
			{
				a[i].x=x1;
				a[i].y=y1;
			}
		}
	    i++;
	}
	for(int i=1;i<=n*n;i++) ans[a[i].x][a[i].y]=i;
	for(int i=1;i<=n;i++,cout<<"\n")
	for(int j=1;j<=n;j++) cout<<ans[i][j]<<" ";
}
int main()
{
	int n;
    cin>>n;
	f(n);	
}
