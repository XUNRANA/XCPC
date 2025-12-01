#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],s[100010],ans;
int flag[100010];
vector<int>p;
void init()
{
	for(int i=2;i<=100000;i++)
	{
		if(!flag[i]) p.push_back(i);
		for(int j=0;j<p.size()&&p[j]*i<=100000;j++)
		{
			flag[p[j]*i]=1;
			if(p[j]%i==0) break;
		}
	}
}
void solve()
{
	ans=-1e18;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	for(int i=1;i<=n;i++)
	{
		for(auto j:p)
		{
			if(i+j-1>n) break;
			ans=max(ans,s[i+j-1]-s[i-1]);
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
	//cin>>T;
	while(T--) solve();
} 
