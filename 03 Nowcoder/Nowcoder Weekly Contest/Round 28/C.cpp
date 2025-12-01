#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,a[1010];
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) a[i]=n;
	while(k--)
	{
		cin>>x>>y;
		if(a[y]>n-x) a[y]--; 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(n-i+1>a[j]) cout<<".";
			else cout<<"*";
		}
		cout<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

