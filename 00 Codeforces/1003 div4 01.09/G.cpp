#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[200010];
void init()
{
	for(int i=2;i<=2e5;i++) if(!f[i]) for(int j=i;j<=2e5;j+=i) f[j]=i;
}
void solve()
{
	int n,x;
	cin>>n;
	int cp=0;//素数的个数 
	int ans=0;
	map<int,int>cnt,fac;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cnt[x]++;
		int p=f[x],q=x/f[x];
		if(q==1)//质数 
		{
			cp++;
			ans+=fac[p]+cp-cnt[p];
		}
		else if(p==q)
		{
			ans+=cnt[p]+cnt[p*q];
			fac[p]++;
		}
		else if(f[q]==q)
		{
			ans+=cnt[p]+cnt[q]+cnt[x];
			fac[q]++;
			fac[p]++;
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
	cin>>T;
	while(T--) solve();
}
