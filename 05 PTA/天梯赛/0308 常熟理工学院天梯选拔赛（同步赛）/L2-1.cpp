#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
int a[100010];
vector<int>g[100010];
typedef struct node
{
	int val,id;
}n1;
bool c1(n1 t1,n1 t2)
{
	if(t1.val==t2.val) return t1.id<t2.id;
	return t1.val>t2.val;
}
bool c2(n1 t1,n1 t2)
{
	if(t1.val==t2.val) return t1.id<t2.id;
	return t1.val<t2.val;
}
void dfs(int u,int fa,int f)
{
	vector<n1>vt;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		n1 t={a[v],v};
		vt.push_back(t);
	}
	if(!f) sort(vt.begin(),vt.end(),c1);
	else sort(vt.begin(),vt.end(),c2);
	if(!vt.empty())
	{
		k+=vt[0].val;
		dfs(vt[0].id,u,f^1);
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=2;i<=n;i++)
	{
		int f;
		cin>>f;
		g[f].push_back(i);
		g[i].push_back(f);
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<k<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

