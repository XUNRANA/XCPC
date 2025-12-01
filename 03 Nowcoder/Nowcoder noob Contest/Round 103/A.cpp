#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,x;
    cin>>n;
    map<int,int>mp;
    int ans=1e9;
    while(n--)
    {
        cin>>x;
        mp[x]++;
        if(mp[x]==3) ans=min(ans,x*3);
    }
    if(ans==1e9) 
    {
        cout<<"no\n";
        ans=-1;
    }
    else
    {
        cout<<"yes\n";
        cout<<ans<<"\n";
    }
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
