#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100];
void solve()
{
	a[1]=0;
	a[2]=1;
	a[3]=1;
	int n=4;
	while(1)
	{
		a[n]=a[n-1]+a[n-2];
		if(a[n]>1e9) break;
		n++;
	}
	map<int,vector<int>>mp;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				int t=a[i]+a[j]+a[k];
				if(t>1e9) break;
				mp[t]={a[i],a[j],a[k]};
			}
		}
	}
	int q,x;
	cin>>q;
	while(q--)
	{
		cin>>x;
		if(mp.count(x))
		{
			for(auto i:mp[x]) cout<<i<<" ";
			cout<<"\n";
		}
		else cout<<"-1\n";
	}
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
