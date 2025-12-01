#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,t,cnt[1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=1000;i++) cnt[i]=0;
    
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		cnt[t]=1;
	}
    
	ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(cnt[t]==1) cnt[t]=2,ans++;
	}
    
	if(ans)
	{
		cout<<ans<<"\n";
		for(int i=1;i<=1000;i++)
		{
			if(cnt[i]==2) cout<<i<<" ";
		}
		cout<<"\n";
	}
	else cout<<"0\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
