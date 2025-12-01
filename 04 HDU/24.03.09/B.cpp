#include <bits/stdc++.h>
using namespace std;
#define int long long
#define p 998244353
string s;
void solve()
{
	cin>>s;
	long long ans=1,t=1;
	for(int i=0;i<s.size();i++) 
	if(s[i]=='1') 
	{
		s=s.substr(i);
		break;
	}
	for(auto i:s)
	{
		ans=ans*3%p;
		if(i=='0')
		{
			t=t*2%p;
			ans=(ans-t+p)%p;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t1=1;
	//cin>>t1;
	while(t1--) solve();
}
