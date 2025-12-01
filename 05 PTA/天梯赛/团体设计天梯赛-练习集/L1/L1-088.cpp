#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[200];
void solve()
{
	int n,k,s;
	cin>>n>>k>>s;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a>=175)
		{
			if(b>=s) ans++;
			else
			{
				if(cnt[a]<k) 
				{
					ans++;
					cnt[a]++;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

