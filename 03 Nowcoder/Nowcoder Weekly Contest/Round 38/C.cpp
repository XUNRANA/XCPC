#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,k;
	string ans;
	cin>>n>>k;
	for(int i=1;i<=k;i++) 
	if(i%3==1) ans+="aa";
	else if(i%3==2) ans+="bb";
	else ans+="cc";
	int j=0;
	while(ans.size()<n)
	{
		ans+=('d'+j);
		j++;
		j%=3;
	}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
