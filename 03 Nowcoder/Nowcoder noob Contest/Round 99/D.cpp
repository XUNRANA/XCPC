#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,f[10000010];
vector<int>p;
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		mp[t]=1;
	}
	for(int i=0;i<p.size();i++) 
	if(!mp.count(p[i])) 
	{
		cout<<p[i]<<"\n";
		return ;
	}
}
void init()
{
	for(int i=2;i<=10000000;i++) 
	if(!f[i])
	{
		p.push_back(i);
		for(int j=i+i;j<=10000000;j+=i) f[j]=1;
	}
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
