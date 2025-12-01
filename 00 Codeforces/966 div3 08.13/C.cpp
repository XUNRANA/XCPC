#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
int n,q,f;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		if(s.size()!=n) 
		{
			cout<<"NO\n";
			continue;
		}
		map<char,int>mp;
		map<int,char>mp1;
		s=" "+s;
		f=0;
		for(int i=1;i<=n;i++) 
		{
			if(mp.count(s[i])&&mp[s[i]]!=a[i])
			{
				f=1;
				break;
			}
			if(mp1.count(a[i])&&mp1[a[i]]!=s[i])
			{
				f=1;
				break;
			}
			mp1[a[i]]=s[i];
			mp[s[i]]=a[i];
		}
		if(f) cout<<"NO\n";		
		else cout<<"YES\n";
	} 
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
