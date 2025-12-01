#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,x,cnt;
void solve()
{
	cin>>n>>m>>k;
	vector<int>a;
	vector<int>c;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(!a.size())
		{
			a.push_back(x);
			cnt=1;
			continue;
		}
		if(a.back()==x) cnt++;
		else 
		{
			c.push_back(cnt);
			a.push_back(x);
			cnt=1;
		}
	}
	c.push_back(cnt);
	
	if(a.size()==1)
	{
		cout<<(n+k-1)/k<<"\n";
		return ;
	}
	
	if(a.size()>=2&&a[0]==a.back())
	{
		a.pop_back();
		int t=c.back();
		c[0]+=t;
		c.pop_back();
	}
	int mx=0;
	for(auto i:c) mx=max(mx,i);
	if(mx<k) 
	{
		cout<<"-1\n";
		return ;
	}
	int ans=0;
	for(auto i:c) ans+=(i+k-1)/k;
	cout<<ans<<"\n";
}
/*
3
11 4 2
1 1 1 2 2 3 3 3 4 4 1
5 2 1
1 2 1 2 1
6 2 2
1 2 1 2 1 2
*/
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
