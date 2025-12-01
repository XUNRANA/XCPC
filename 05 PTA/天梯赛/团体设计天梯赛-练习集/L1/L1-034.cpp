#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n;
	cin>>n;
	int ans=0,mx=0;
	map<int,int>mp,mp1;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x;
			cin>>x;
			mp[x]++;
			if(mp[x]>mx)
			{
				mx=mp[x];
				ans=x;
			}
			else if(mp[x]==mx) ans=max(ans,x);
		}
	}
	cout<<ans<<" "<<mp[ans]<<"\n";
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

