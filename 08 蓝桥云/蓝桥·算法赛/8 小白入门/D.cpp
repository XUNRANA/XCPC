#include <bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]==2)
	{
		b[1]=b[2]=1;
		for(int i=2;i<n;i++) b[i+1]=a[i]-b[i]-b[i-1];
		for(int i=1;i<=n;i++) cout<<b[i]<<" ";
		cout<<"\n";
	}
	else if(a[1]==1)
	{
		b[1]=0;
		b[2]=1;
		for(int i=2;i<n;i++) 
		{
			b[i+1]=a[i]-b[i]-b[i-1];
			if(b[i+1]>1||b[i+1]<0)
			{
				b[1]=1;
				b[2]=0;
				for(int j=2;j<n;j++) b[j+1]=a[j]-b[j]-b[j-1];
				for(int j=1;j<=n;j++) cout<<b[j]<<" ";
				cout<<"\n";
				return 0;
			}
		}
		for(int i=1;i<=n;i++) cout<<b[i]<<" ";
		cout<<"\n";
	}
  	else
  	{
  		b[1]=b[2]=0;
		for(int i=2;i<n;i++) b[i+1]=a[i]-b[i]-b[i-1];
		for(int i=1;i<=n;i++) cout<<b[i]<<" ";
		cout<<"\n";
  	}
}
