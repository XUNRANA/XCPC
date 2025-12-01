#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    cin>>n;
    vector<int>cnt(4,0);
    int s=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==3) continue;
        cnt[x]+=y;
        s+=y;
    }
    if(s*0.2<=cnt[2]&&cnt[2]<=s*0.6)
    {
        if(cnt[1]<s*0.55&&cnt[0]>=0.1*s&&cnt[0]<=0.3*s) cout<<"Great! "<<s<<"\n";
        else if((cnt[1]<s*0.55)||(cnt[0]>=0.1*s&&cnt[0]<=0.3*s))  cout<<"Normal "<<s<<"\n";
        else cout<<"Little Bad "<<s<<"\n";
    }
    else cout<<"Bad! "<<s<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}