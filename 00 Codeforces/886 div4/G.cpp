#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    map<int,int>mp[4];
    for(int i=1;i<=n;i++) 
    {
        int x,y;
        cin>>x>>y;
        mp[0][x]++;
        mp[1][y]++;
        mp[2][x-y]++;
        mp[3][x+y]++;
    }
    int ans=0;
    for(auto i:mp[0]) ans+=i.second*(i.second-1); 
    for(auto i:mp[1]) ans+=i.second*(i.second-1); 
    for(auto i:mp[2]) ans+=i.second*(i.second-1); 
    for(auto i:mp[3]) ans+=i.second*(i.second-1); 
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
