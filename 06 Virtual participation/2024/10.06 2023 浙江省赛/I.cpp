#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
#define p1 1331
int hz[1000010],hf[1000010],p[1000010];
string s;
int n,q,l,r;
int get_hz(int l,int r)
{
	return (hz[r]-hz[l-1]*p[r-l+1]%P+P)%P;
}
int get_hf(int l,int r)
{
	return (hf[l]-hf[r+1]*p[r-l+1]%P+P)%P;
}
bool ck(int l,int r)
{
	if(get_hz(l,r)==get_hf(l,r)) return 1;
	return 0;
}
void solve()
{
	cin>>n>>q;
	cin>>s;
	s=" "+s;
	p[0]=hz[0]=1;
	hf[n+1]=1;
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]*p1%P;
		hz[i]=(hz[i-1]*p1%P+s[i]-'a')%P;
		hf[n-i+1]=(hf[n-i+1+1]*p1%P+s[n-i+1]-'a')%P;
	}
/*
7 3
abababa
1 3
3 5
1 6
*/
	while(q--)
	{
		cin>>l>>r;
		if(ck(l,r)||(ck(l+1,r)&&ck(l,r-1))) cout<<"Budada\n";
		else 
		{
			if((r-l+1)&1) cout<<"Putata\n";
			else cout<<"Budada\n";
		}
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
