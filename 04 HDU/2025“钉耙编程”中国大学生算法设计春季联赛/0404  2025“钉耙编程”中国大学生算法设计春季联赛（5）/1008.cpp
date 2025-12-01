#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010];
void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
	if(n>=25) cout<<"YES\n";
	else
	{
		map<int,int>mp[25];
		for(int i=1;i<(1<<n)-1;i++)
		{
			int res=0;
			for(int j=0;j<n;j++) if(i>>j&1) res+=a[j];
			if(mp[__builtin_popcount(i)].count(res))
			{
				cout<<"YES\n";
				return ;
			}
			else mp[__builtin_popcount(i)][res]=1;
		}
		cout<<"NO\n";
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