#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x;
	cin>>n>>m>>x;
	int a[n],b[m];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]==x) continue;
		if(a[i]<x)
		{
			for(int j=0;j<m;j++)
			if(b[j]<x) 
            {
                x=max(a[i],b[j]);
                if(a[i]==x) break;
            }
		}
		if(a[i]>x)
		{
			for(int j=0;j<m;j++)
			if(b[j]>x) 
            {
                x=min(a[i],b[j]);
                if(a[i]==x) break;
            }
		}
	}
	cout<<x;
}