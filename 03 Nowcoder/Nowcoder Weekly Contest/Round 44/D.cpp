#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,q,t,a[100010];
void solve()
{
	cin>>n>>q;
	map<int,int>mp;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		a[i]=t;
		if(t==1) continue;
		if(mp.count(t)) 
		{
			a[i]=mp[t];
			continue;
		}
		map<int,int>cnt;
		for(int j=2;j*j<=t;j++)
		{
			while(t%j==0)
			{
				cnt[j]++;
				t/=j;
			}
		}
		if(t!=1) cnt[t]++;
				
		int res=1;
		for(auto i:cnt) res*=i.second+1;
		
		mp[a[i]]=res;
		a[i]=res;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
	while(q--)
	{
		int l,r,ans=0;
		cin>>l>>r;
		map<int,int>cnt;
		for(int i=l;i<=r;i++) cnt[a[i]]++;
		for(auto i:cnt)
		{
			if(i.second!=1) ans+=(i.second-1)*i.second/2;
		}
		cout<<ans<<"\n";
		
	}
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
