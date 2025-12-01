#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
#define P1 13331
int p[100010];
int hz[100010];
int hf[100010];
int gz(int l,int r)
{
	return (hz[r]-hz[l-1]*p[r-l+1]%P+P)%P;
}
int gf(int l,int r)
{
	return (hf[l]-hf[r+1]*p[r-l+1]%P+P)%P;
}
void solve()
{
	string s;
	while(cin>>s)
	{
		int n=s.size();
		s=" "+s;
		p[0]=hz[0]=1;
		for(int i=1;i<=n;i++)
		{
			p[i]=p[i-1]*P1%P;
			hz[i]=(hz[i-1]*P1+s[i])%P;
		}
		hf[n+1]=1;
		for(int i=n;i>=1;i--)
		{
			hf[i]=(hf[i+1]*P1+s[i])%P;
		}
				
		for(int i=1;i<=n;i++)
		{
			if(gz(i,n)==gf(i,n))
			{
				if(i-1)
				{
					string t=s.substr(1,i-1);
					reverse(t.begin(),t.end());
					cout<<s.substr(1)+t<<"\n";
				}
				else cout<<s.substr(1)<<"\n";
				break;
			}
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
