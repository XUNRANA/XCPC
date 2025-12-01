#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k,mx,t,cnt,ans,d[400010];
void solve()
{
	mx=cnt=0;
	cin>>n>>k;	
	for(int i=0;i<2*k;i++) d[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		mx=max(mx,t);
		d[t%(2*k)]++;
	}
	ans=1e9;
	for(int i=0;i<k-1;i++) cnt+=d[i];
	for(int l=0,r=k-1;l<2*k;l++,r++)
	{
		if(r>=2*k) r-=2*k;
		cnt+=d[r];
		if(cnt==n)
		{
			t=(r-mx)%(2*k);
			if(t<0) t+=2*k;
			ans=min(ans,mx+t);
		}
		cnt-=d[l];
	} 
	if(ans==1e9) ans=-1;
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
