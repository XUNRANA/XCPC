#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,x,y,a[100010];
void solve()
{
	cin>>n>>k;
	map<int,int>cnt,cnt1;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a+1,a+1+n);
	vector<int>b;
	map<int,int>mp;
	b.push_back(-1);
	b.push_back(1e9+1);
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		cnt1[x]=y;
		if(y==0) b.push_back(x);
		else mp[x]=y;
	}
	for(auto i:cnt)
	{
		if(cnt1.count(i.first)&&i.second>cnt1[i.first])
		{
			cout<<"Pico\n";
			return ;
		}
	}
	
	sort(b.begin(),b.end());
	int j=0,now=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(a[i]>b[j+1]) 
		{
			j++;
			now=b[j]+1;
		}
		ans+=a[i]-now;
		if(mp.count(now)) 
		{
			mp[now]--;
			if(mp[now]==0) now++;
		}
	}
	if(ans&1) cout<<"Pico\n";
	else cout<<"FuuFuu\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
