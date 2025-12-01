#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,m,k,u,v,res1,res0;
vector<int>g0[100010],g1[100010];
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
int inv(int x)
{
	return ksm(x,P-2);
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) 
	{
		cin>>u>>v;
		g1[u].push_back(v);
		g0[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		int ans=1;
		for(auto j:g1[i]) ans=ans*(1-inv(g0[j].size())+P)%P;//心动女嘉宾都不选他的概率 
		res1=(res1+(1-ans+P)%P)%P;//他被选=至少一个选他的概率 
	}
	
	for(int i=1;i<=m;i++)
	{
		int ans=1;
		for(auto j:g0[i]) ans=ans*(1-inv(g1[j].size())+P)%P;
		res0=(res0+(1-ans+P)%P)%P;
	}
	cout<<"modint\n";
	cout<<res1<<" "<<res0<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
