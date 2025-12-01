#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353 
int n,x,ans[1000010];
void solve()
{
	cin>>n;
	map<int,vector<int>>g;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		map<int,int>mp;
		for(int i=2;i*i<=x;i++)
		{
			while(x%i==0)
			{
				x/=i;
				mp[i]++;
			}
		}
		if(x!=1) mp[x]++;
		for(auto i:mp) g[i.first].push_back(i.second);
	}
	for(int i=1;i<=n;i++) ans[i]=1;
	for(auto i:g)
	{
		sort(i.second.begin(),i.second.end(),greater<int>());
		int k=1;
		for(auto j:i.second)
		{
			ans[k]=ans[k]*(int)pow(i.first,j)%P;
			k++;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++) res=(res+ans[i])%P;
	cout<<res<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
