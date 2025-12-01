#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

int L[100];
int R[100];
int a[100];
int ans[100],idx;
void dfs(int rt)
{
	if(L[rt]!=-1) dfs(L[rt]);
	if(R[rt]!=-1) dfs(R[rt]);
	ans[rt]=a[idx++];
//	cout<<rt<<"\n";
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	idx=1;
	for(int i=1;i<=n;i++)
	{
		if(2*i<=n) L[i]=2*i;
		else L[i]=-1;
		if(2*i+1<=n) R[i]=2*i+1;
		else R[i]=-1;
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		if(i!=1) cout<<" ";
		cout<<ans[i];
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
