#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[10010];
void solve()
{
	int n,k,m,q,x;
	cin>>n>>k>>m>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		int s=1;
		for(int j=1;j<=k;j++)
		{
			s=s*x%n;
			f[s]=1;
		}
	}
	while(q--)
	{
		cin>>x;
		int s=1;
		int flag=0;
		for(int j=1;j<=k;j++)
		{
			s=s*x%n;
			if(!f[s]) flag=1;
		}
		if(flag==0) cout<<"1 ";
		else cout<<"0 ";
	}
}
/*
11 3 4 5
1 5 3 8
4 7 1 0 4
*/


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
