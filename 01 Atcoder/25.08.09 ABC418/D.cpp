#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    int c0=0;
    int ans=0;
    map<int,int>mp;
    mp[0]++;
    for(auto i:s)
    {
        c0+=(i=='0');
        ans+=mp[c0&1];
        mp[c0&1]++;
    }
    cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

