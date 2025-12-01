#include <bits/stdc++.h>
using namespace std;
int n,x,q,a[200010];
void solve()
{
	cin>>n;
	vector<int>v;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>x;
		auto pos=lower_bound(v.begin(),v.end(),a[x]);
		v.erase(pos);
		if(v.size()&1) printf("%.1f ",1.0*v[v.size()/2]);
		else printf("%.1f ",1.0*(v[v.size()/2]+v[v.size()/2-1])/2);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
