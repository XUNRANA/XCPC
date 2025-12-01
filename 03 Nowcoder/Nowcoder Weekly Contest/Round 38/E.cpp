#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,t,cnt[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		cnt[t]++;
	} 
	int ans=0;
	for(int i=1;i<=200000;i++)
	if(cnt[i])
	{
        ans=max(ans,cnt[i]);
		for(int q=2;i*q<=200000;q++)
		{
			t=i;
			int res=1;
			while(t*q<=200000&&cnt[t*q])
			{
				t*=q;
				res++;
			}
			ans=max(ans,res);
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
