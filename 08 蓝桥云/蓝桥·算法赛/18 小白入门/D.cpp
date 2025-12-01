#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	int f=a%c;
	int s=b%c;
	int p=(c+1)/2;
	int ans=1+(c-1-f+1)/2;
	if(b/c-a/c-1>=0) cout<<1+(c-1-f+1)/2+(b/c-a/c-1)*p+(s-1+1)/2<<"\n";
	else cout<<(b-a+1)/2<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
