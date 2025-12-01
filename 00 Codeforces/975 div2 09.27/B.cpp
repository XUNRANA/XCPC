#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[100010],n,q,t,x1;
void solve()
{
	cin>>n>>q;
	map<int,int>mp;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) 
	{
		int t=(i-1)*(n-i+1)+(n-i);
		mp[t]++;
		if(i-1>=1&&x[i]-x[i-1]!=1)
		{
			int t=(i-1)*(n-i+1);
			mp[t]+=x[i]-x[i-1]-1;
		}
	}
	
//	for(auto i:mp) cout<<i.first<<" "<<i.second<<"\n";

	while(q--)
	{
		cin>>x1;
		if(mp.count(x1)) cout<<mp[x1]<<" ";
		else cout<<"0 ";
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
