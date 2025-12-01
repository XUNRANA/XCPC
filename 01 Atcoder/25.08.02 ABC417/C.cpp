#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    map<int,int>mp;
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        int xj=x-i;
        int xi=-x-i;
        if(mp.count(xj)) ans+=mp[xj];
        mp[xi]++;
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

