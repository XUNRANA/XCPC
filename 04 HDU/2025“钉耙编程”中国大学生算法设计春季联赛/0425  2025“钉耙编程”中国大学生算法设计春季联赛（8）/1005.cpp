#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m;
    string s1,s2;
    cin>>n>>m;
    cin>>s1>>s2;
    s1=" "+s1;
    s2=" "+s2;
    map<int,vector<int>>mp;
    int mx=0;
    for(int i=1;i<=m&&m-i+1>=n;i++)
    {
        int i1=i;
        int j=1;
        while(i1<=m&&j<=n&&s2[i1]!=s1[j]) j++,i1++;
        mp[i1-i].push_back(i);
        mx=max(mx,i1-i);
    }
    string s="";
    for(int i=1;i<=n;i++) s+='0';
    for(auto idx:mp[mx])
    {
        string t="";
        for(int j=idx;j<=idx+n-1;j++) 
        if(s2[j]==s1[j-idx+1]) t+='0';
        else t+='1';
        s=max(s,t);
    }
    int ans=0;
    for(auto i:s) ans+=i=='1';
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
