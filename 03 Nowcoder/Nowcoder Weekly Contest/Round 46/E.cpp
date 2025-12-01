#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010],b[100010];
void solve()
{
	int n,q,k;
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		mp[b[i]]+=a[i];
	}
	vector<pair<int,int>>v;
	vector<int>d;
	for(auto i:mp) 
	{
		v.push_back({i.first,i.second});
		d.push_back(i.first);
	}
	
	vector<int>ps(v.size()),ss(v.size());
	ps[0]=v[0].first*v[0].second;
	for(int i=1;i<v.size();i++) ps[i]=ps[i-1]+v[i].first*v[i].second;
	
	ss[v.size()-1]=v[v.size()-1].second;
	for(int i=v.size()-2;i>=0;i--) ss[i]=ss[i+1]+v[i].second;
	cin>>q;
	while(q--)
	{
		cin>>k;
		int i=upper_bound(d.begin(),d.end(),k)-d.begin();
        if(k>=d.back()) cout<<ps[ps.size()-1]<<"\n";
        else if(i==0) cout<<k*ss[i]<<"\n";
        else cout<<ps[i-1]+k*ss[i]<<"\n";
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
