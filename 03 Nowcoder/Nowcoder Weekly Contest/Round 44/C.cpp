#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	string s;
	cin>>s;
	int n=s.size(),f=0,ans=0,f1=0;
	
	for(int i=n-1;i>=1;i--)
	{
		if(s[i]=='0'&&f1==0) continue;
		f1=1;
		if(f==1) ans+=9-(s[i]-'0');
		else ans+=10-(s[i]-'0'),f=1;
	}
	cout<<ans<<"\n";

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
