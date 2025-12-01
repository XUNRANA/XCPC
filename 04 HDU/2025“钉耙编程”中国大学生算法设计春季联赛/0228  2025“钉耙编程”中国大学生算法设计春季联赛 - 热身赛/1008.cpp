#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    map<char,int>mp;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        mp[s[0]]++;
        mp[s[1]]++;
    }
    // for(auto [x,y]:mp) cout<<x<<" "<<y<<"\n";
    cout<<min(mp['A'],mp['u'])<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
