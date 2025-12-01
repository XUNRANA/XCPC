#include <bits/stdc++.h>
using namespace std;
#define P 131
#define mod 998244353
#define int long long
string s,t;
int p[1000010],h1[1000010],h2[1000010],h3[1000010];
int n,ans[1000010];
void init()
{
	p[0]=1;
	for(int i=1;i<=1000000;i++) p[i]=p[i-1]*P%mod;
}
int gethash(int l,int r,int op)
{
	if(!op) return (h1[r]-h1[l-1]*p[r-l+1]%mod+mod)%mod;
	return (h2[l]-h2[r+1]*p[r-l+1]%mod+mod)%mod;
}
bool ck(int x,int i)
{
    if(!x) return 1;
	if(x<=i) return gethash(i-x+1,i,1)==h3[x];
	return (gethash(1,i,1)*p[x-i]%mod+gethash(i+1,x,0))%mod==h3[x];
}
void solve()
{
	cin>>n>>s>>t;
	s=" "+s;
	t=" "+t;
    h1[0]=h3[0]=h2[n+1]=0;
	for(int i=1;i<=n;i++) h1[i]=(h1[i-1]*P+s[i]-'a')%mod;
    for(int i=n;i>=1;i--) h2[i]=(h2[i+1]*P+s[i]-'a')%mod;
	for(int i=1;i<=n;i++) h3[i]=(h3[i-1]*P+t[i]-'a')%mod;
    int res=1;
    for(int i=1;i<=n;i++)
	{
		int l=0,r=n;
		while(l<=r)
		{
			int m=l+r>>1;
			if(ck(m,i)) l=m+1;
			else r=m-1;
		}
		ans[i]=l-1;
		if(ans[i]>ans[res]) res=i;
	}
	cout<<ans[res]<<" "<<res<<"\n";
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
