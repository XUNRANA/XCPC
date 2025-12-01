#include <bits/stdc++.h>
using namespace std;
int cnt[200010];
void solve()
{
	int n,x,t;
	cin>>n>>x;
	for(int i=0;i<=n;i++) cnt[i]=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		if(t>n) continue;
		cnt[t]++;
	}
	map<int,int>mp;
	for(int i=0;i<=n;i++)
	{
		if(!cnt[i])
		{
			if(mp.count(i%x))
			{
				mp[i%x]--;
				if(mp[i%x]==0) mp.erase(i%x);
			}
			else
			{
				cout<<i<<"\n";
				return ;
			}
		}
		else
		{
			if(cnt[i]>1) mp[i%x]+=cnt[i]-1;
		}
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
