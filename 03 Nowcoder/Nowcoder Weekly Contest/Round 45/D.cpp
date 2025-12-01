#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans,t,n,k,x;
void solve()
{
	cin>>n>>k;
    map<int,int>mp;
	for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(mp.count(t)&&i-mp[t]>k) x=max(x,mp[t]);
        ans+=i-x;
        mp[t]=i;
    }
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
