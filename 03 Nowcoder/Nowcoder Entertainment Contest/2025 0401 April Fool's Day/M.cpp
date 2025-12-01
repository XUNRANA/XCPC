#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin>>s;
    int cnt=count(s.begin(),s.end(),'1');
    for(auto i:s)
    if(i=='2') 
    {
        if(!cnt) cout<<i;
    }
    else cout<<i; 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
