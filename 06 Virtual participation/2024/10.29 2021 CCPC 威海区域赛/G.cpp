#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int jc[100010];
void init()
{
	jc[0]=1;
	for(int i=1;i<=100000;i++) jc[i]=jc[i-1]*i%P;
}
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
int C(int a,int b)
{
	return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}
void solve()
{
	int n,m,mx=0;
	cin>>n>>m;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		mp[x]++;
		mx=max(mx,x);
	}
	
	for(int i=1;i<min(mx,m);i++) cout<<"0\n";
	
	for(int i=mx;i<=m;i++)
	{
		int ans=1;
		for(auto j:mp)
		{
			ans=ans*ksm(C(i,j.first),j.second)%P;
		}
		cout<<ans<<"\n";
	}
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
