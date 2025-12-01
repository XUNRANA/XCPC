#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t,f,za,fa,zb,fb,mxa=-1e9,mxb=-1e9,mia=1e9,mib=1e9;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t==0) f=1;
		za+=t;
		fa+=t;
		mxa=max(mxa,za);
		mia=min(mia,fa);
		if(za<0) za=0;
		if(fa>0) fa=0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>t;
		if(t==0) f=1;
		zb+=t;
		fb+=t;
		mxb=max(mxb,zb);
		mib=min(mib,fb);
		if(zb<0) zb=0;
		if(fb>0) fb=0;
	}
	if(f) cout<<max({mxa*mib,mxa*mxb,mia*mib,mia*mxb,0ll});
	else cout<<max({mxa*mib,mxa*mxb,mia*mib,mia*mxb});
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
