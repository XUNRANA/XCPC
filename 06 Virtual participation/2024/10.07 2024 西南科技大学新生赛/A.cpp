#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,z,s,t,ans1,ans2;
void solve()
{
	cin>>n>>z>>s;
	ans1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t>s) ans1-=2;
		else ans1+=1;
		ans1=max(ans1,0ll);
	} 
	ans2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t>z) ans2-=2;
		else ans2+=1;
		ans2=max(ans2,0ll);
	} 
	if(ans1>ans2) cout<<"zy\n";
	else if(ans1<ans2) cout<<"sdy\n";
	else cout<<"none\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
