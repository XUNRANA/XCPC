#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[200010],ans,s;
void solve()
{
	ans=s=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],ans+=a[i];
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		if(mp.count(a[i])) 
		{
			mp[a[i]]++;
			a[i]=max(a[i-1],a[i]);
		}
		else 
		{
			mp[a[i]]++;
			a[i]=a[i-1];
		}
	}
	mp.clear();
	
	for(int i=1;i<=n;i++)
	{
		ans+=a[i];
		if(mp.count(a[i])) 
		{
			mp[a[i]]++;
			a[i]=max(a[i-1],a[i]);
		}
		else 
		{
			mp[a[i]]++;
			a[i]=a[i-1];
		}
	}
	

	mp.clear();

	for(int i=1;i<=n;i++) mp[a[i]]++;
	
	vector<int>v;
	
	for(auto i:mp) if(i.first) v.push_back(i.first);
	
	s=0;
	sort(v.begin(),v.end(),greater<int>());
	for(auto i:v)
	{
		ans+=i*(mp[i]+1)*mp[i]/2+i*mp[i]*s;
		s+=mp[i]; 
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
