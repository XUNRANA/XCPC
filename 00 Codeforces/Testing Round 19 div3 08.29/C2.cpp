#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1331
#define mod 998244353
int p[400010],h[400010];
unsigned long long get(int l,int r)
{
	return (h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;
}
bool ck(int l,int r,int l1,int r1)
{
	return get(l,r)==get(l1,r1);
}
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	s=" "+s;
	p[0]=h[0]=1;
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]*P%mod;
		h[i]=(h[i-1]*P%mod+s[i]-'a')%mod;
	}
	for(int i=(n+1)/2;i>=2;i--)
	{
		if(ck(i,n,1,n-i+1))
		{
			cout<<"YES\n";
			cout<<s.substr(1,n-i+1)<<"\n";
			return ;
		}
	}
	cout<<"NO\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
