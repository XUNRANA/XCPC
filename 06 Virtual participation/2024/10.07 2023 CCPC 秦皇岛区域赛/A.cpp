#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
void solve()
{
	cin>>n>>k;
	map<pair<int,int>,int>mp;
	for(int i=1;i<n;i++)
	{
		mp[{i,i}]=1;
		mp[{i,i+1}]=1;
		cout<<i<<" "<<i<<"\n";
		cout<<i<<" "<<i+1<<"\n";
		k-=2;
	}
	mp[{n,n}]=1;
	mp[{n,1}]=1;
	cout<<n<<" "<<n<<"\n";
	cout<<n<<" "<<1<<"\n";
	k-=2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!k) return ;
			if(mp.count({i,j})) continue;
			cout<<i<<" "<<j<<"\n";
			k--;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
