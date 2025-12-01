#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
#define p1 1331
int n;
string s;
int p[200010];
int hs[200010];
int get(int l,int r)
{
	return (hs[r]-hs[l-1]*p[r-l+1]%P+P)%P;
}
void solve()
{
	cin>>n;
	cin>>s;
	for(auto i:s)
	{
		if(isupper(i))
		{
			cout<<"shameimaru\n";
			return ;
		}
	}
	s="$"+s;
	p[0]=hs[0]=1;
	for(int i=1;i<=n;i++)
	{
		hs[i]=(hs[i-1]*p1%P+s[i]-'a')%P;
		p[i]=p[i-1]*p1%P;
	}
	set<char>st;
	for(int i=1;i<=n;i++)
	{
		if(st.count(s[i])) 
		{
			int r=n;
			int l=i;
			if((r-l+1)&1) l--;
			int len=r-l+1;
			while(l>=1&&get(l,l+len/2-1)!=get(l+len/2-1+1,r))
			{
				l-=2;
				len=r-l+1;
			}
			if(l>1&&get(l,l+len/2-1)==get(l+len/2-1+1,r)) cout<<"sya\n";
			else cout<<"shameimaru\n";
			return ;
		}
		st.insert(s[i]);
	}
	cout<<"shameimaru\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
