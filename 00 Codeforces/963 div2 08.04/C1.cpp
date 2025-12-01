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
		if(t%(2*k)+k>2*k-1)
		{
			d[0]++;
			d[t%(2*k)+k-2*k]--;
		}
		else d[t%(2*k)+k]--;
	}
	ans=1e9;
	for(int i=1;i<2*k;i++)  d[i]+=d[i-1];
	for(int i=0;i<2*k;i++) 
	{
		int t=mx/(2*k)*(2*k)+i;
		if(t<mx) t+=2*k;
		if(d[i]==n) ans=min(ans,t);	
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
