#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,c0,c1;
void solve()
{
	cin>>n;
    map<int,int>mp;
    while(n--)
    {
        cin>>t;
        mp[t]++;
    }
    for(auto i:mp)
    {
        if(i.first<0) c0+=i.second;
        else c1+=i.second&1;
    }
    if(c0>=c1) cout<<((c0+c1)&1);
    else cout<<c1-c0;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
