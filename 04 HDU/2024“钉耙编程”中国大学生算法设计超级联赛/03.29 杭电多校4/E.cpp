#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353

void solve() 
{
    int n,m,hp,dmg;
    cin>>n>>m>>hp>>dmg;
    vector<int>ans(m+1,-1);
    
    if(hp>=m)
    {
        for(int i=0;i<m;i++)
        {
            if(i<hp%m) ans[i]=hp/m;
            else ans[i]=hp/m-1;
        }
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            if(i<hp) ans[i]=0;
        }
    }
    
    if(dmg>=m)
    {
        for(int i=0;i<m;i++) if(ans[i]!=-1) ans[i]=-2;
    }

    else
    {
        for(int i=0;i<dmg;i++)
        {
            int idx=hp%m-1-i;
            idx=(idx+m)%m;
            if(ans[idx]!=-1) ans[idx]=-2; 
        }
    }
    string res1="";
    string res2="";
    res1+='+';
    for(int i=0;i<m;i++) res1+='-';
    res1+='+';

    res2+='|';
    for(int i=0;i<m;i++) if(ans[i]==-2) res2+='.';
    else if(ans[i]==-1) res2+=' ';
    else res2+=char('A'+ans[i]%5);
    res2+='|';
    
    for(int i=0;i<=n+1;i++) if(i==0||i==n+1) cout<<res1<<"\n";
    else cout<<res2<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
     cin>>T;
    while(T--) solve();
}