#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
int a[200010];
int f[200010];
int de[200010];
void solve()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++) f[i]=1,de[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		de[a[i]]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	if(!de[i]) q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		f[u]=0;
		if(--de[a[u]]==0) q.push(a[u]);
	}
	int ans=0;
	while(!f[x])
	{
		ans++;
		x=a[x];
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
