#include <bits/stdc++.h>
using namespace std;
#define P 998244353
#define int long long
int l,r;
int f(int x)
{      
	int len=x+1,r=1,res=0;
	for(int i=0;i<=60;i++)
	{
		r*=2;
		res+=len/r*(r/2)%P+max(0ll,len%r-r/2);
		res%=P;
	}
	return res;
}
void solve()
{
	cin>>l>>r;
	cout<<(f(r)-f(l-1)+P)%P<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
