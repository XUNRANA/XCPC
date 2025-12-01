#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
void solve() 
{
    cin>>n>>k;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    vector<int>a;
    for(auto i:mp) if(i.second>=k) a.push_back(i.first);
    int ans=0;
    int l=-1,r=-1;
    for(int i=0;i<a.size();i++)
    {
        int j=i+1;
        while(j<a.size()&&a[j]-a[i]==j-i) j++;
        if(j-i>ans)
        {
            ans=j-i;
            l=a[i];
            r=a[j-1];
        }
        i=j-1;
    }
    if(l==-1) cout<<"-1\n";
    else cout<<l<<" "<<r<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}