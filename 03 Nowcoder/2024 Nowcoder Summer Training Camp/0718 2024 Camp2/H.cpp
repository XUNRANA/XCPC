#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y,x11,y11,ans;
void solve()
{
    string s;
    cin>>n>>x>>y;
    cin>>s;
    if(x==0&&y==0)
    {
        cout<<n*(n+1)/2<<"\n";
        return ;
    }
    x11=y11=0;
    map<pair<int,int>,int>mp;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='A') x11--;
        if(s[i-1]=='D') x11++;
        if(s[i-1]=='W') y11++;
        if(s[i-1]=='S') y11--;
        if(mp.count({x11,y11})) continue;
        mp[{x11,y11}]=i;
    }
    x11=y11=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='A') x11--;
        if(s[i-1]=='D') x11++;
        if(s[i-1]=='W') y11++;
        if(s[i-1]=='S') y11--;
        if(mp.count({x+x11,y+y11})) ans+=n-mp[{x+x11,y+y11}]+1;
        mp.erase({x11,y11});
    }
    cout<<ans<<"\n";
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve(); 
}

