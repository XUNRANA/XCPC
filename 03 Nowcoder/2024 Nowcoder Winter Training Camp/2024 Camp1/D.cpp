#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,m,a[100010];
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
    int t=a[(n+1)/2];
	for(int i=1;i<=n;i++) a[i]-=t;
	map<int,int>mp;
	for(int i=-1e6/n;i<=1e6/n;i++)
	{
		int ans=1,f=0;
		for(int j=1;j<=n;j++)
		{
			ans*=a[j]+i;
			if(abs(ans)>1e9) 
			{
				f=1;
				break;
			}
		}
		if(f==0) mp[ans]=1;
	}
    mp[0]=1;
	while(q--)
	{
		cin>>m;
		if(mp.count(m)) cout<<"Yes\n";
		else cout<<"No\n";
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
