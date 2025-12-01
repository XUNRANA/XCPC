#include <bits/stdc++.h>
using namespace std;
int n,q,u,v,w,op,x,y,z;
int a[500010];
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) a[i]=0;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		a[u]^=w;
		a[v]^=w; 
	}
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y>>z;
			a[x]^=z;
			a[y]^=z;
		}
		else
		{
			cin>>x;
			cout<<a[x]<<"\n";
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
