#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P1 131
#define P 998244353
string s;
int n,q,pos;
int hs[1000010];
int p[1000010];
int ans[1000010];
int get(int l,int r)
{
	return (hs[r]-hs[l-1]*p[r-l+1]%P+P)%P;
}
void solve()
{
	cin>>s;
	n=s.size();
	s=" "+s;
	hs[0]=p[0]=1;
	for(int i=1;i<=n;i++)
	{
		hs[i]=(hs[i-1]*P1%P+s[i]-'a')%P;
		p[i]=p[i-1]*P1%P;
	}
	
	for(int i=1;i<=(n+1)/2;i++)
	{
		ans[i]=ans[i-1];
		if(get(1,i)==get(n-i+1,n)) ans[i]++;
	}
	
	cin>>q; 
	while(q--)
	{
		cin>>pos;
		cout<<ans[min(pos-1,n-pos)]<<"\n";
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
