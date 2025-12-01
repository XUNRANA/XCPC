#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,ans,f[100100];
vector<int>p;
void init()
{
	f[0]=f[1]=1;
	for(int i=2;i<100100;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&i*p[j]<100100;j++)
		{
			f[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(!f[t]) continue;
		for(int j=1;j;j++)
		{
			if(!f[t+j]||(t-j>=0&&!f[t-j]))
			{
				ans+=j;
				break;
			}
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
