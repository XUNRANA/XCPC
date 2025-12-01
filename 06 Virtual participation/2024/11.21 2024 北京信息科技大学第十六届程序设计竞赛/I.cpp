#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	s=" "+s;
	int ans=0;
	while(k>=1&&k<=n)
	{
		if(s[k]=='<') 
		{
			s[k]='>';
			k--;
		}
		else 
		{
			s[k]='<';
			k++;
		}
		ans++;
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
