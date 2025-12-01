#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,l,r,a[200010],sa[200010];
void solve()
{
	cin>>n>>q;
	map<int,vector<int>>mp;
	for(int i=1;i<=n;i++) cin>>a[i],sa[i]=sa[i-1]^a[i],mp[sa[i]].push_back(i);
	for(auto i:mp) sort(i.second.begin(),i.second.end());
	while(q--)
	{
		cin>>l>>r;
		int x=(sa[r]^sa[l-1]);
		int p=(x^sa[l-1]),p1=(p^x);
		if(x==0) cout<<"YES\n";
		else 
		{
			int it=lower_bound(mp[p].begin(),mp[p].end(),l)-mp[p].begin();
			if(mp[p][it]==r) 
			{
				cout<<"NO\n";
				continue;
			}
			int it0=upper_bound(mp[p1].begin(),mp[p1].end(),mp[p][it])-mp[p1].begin();
			if(it0<mp[p1].size()&&mp[p1][it0]<r) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
