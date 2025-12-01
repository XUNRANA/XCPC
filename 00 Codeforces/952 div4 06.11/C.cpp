#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,t,s;
void solve()
{
	ans=s=0;
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		s+=t;
		mp[t]++;
		if(s%2==0&&mp.count(s/2)) ans++;
	}
	cout<<ans<<"\n";

}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
