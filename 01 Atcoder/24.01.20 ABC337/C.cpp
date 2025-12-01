#include <bits/stdc++.h>
using namespace std;
int n,f,t,a[300010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t==-1) f=i;
		a[t]=i;
	}
	while(n--)
	{
		cout<<f<<" ";
		f=a[f];
	}
}
