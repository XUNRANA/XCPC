#include <bits/stdc++.h>
using namespace std;
int n,m,q,bad,i,x;
int a[200010];
int b[200010];
int val[200010];
int pos[200010];
set<int>g[200010];
void update(int i)
{
	if(i-1>=1) bad-=val[i-1]>val[i];
	if(i+1<=n) bad-=val[i]>val[i+1];
	val[i]=*g[a[i]].begin();
	if(i-1>=1) bad+=val[i-1]>val[i];
	if(i+1<=n) bad+=val[i]>val[i+1];
}
void solve()
{
	cin>>n>>m>>q;
	
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		pos[a[i]]=i;
		g[i].clear();
		g[i].insert(m+1);
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		g[b[i]].insert(i);
	}
	
	bad=0;
	for(int i=1;i<=n;i++) val[i]=*g[a[i]].begin();
	
	for(int i=1;i<n;i++) bad+=val[i]>val[i+1];
	if(bad) cout<<"TIDAK\n";
	else cout<<"YA\n";
	
	while(q--)
	{
		cin>>i>>x;
		int old=b[i];
		g[b[i]].erase(i);
		b[i]=x;
		g[b[i]].insert(i);
		update(pos[old]);
		update(pos[x]);
		if(bad) cout<<"TIDAK\n";
		else cout<<"YA\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
