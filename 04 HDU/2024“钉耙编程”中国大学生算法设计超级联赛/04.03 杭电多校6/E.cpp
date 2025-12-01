#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k,m;
void print(int x)
{
    string ans="";
    for(int i=0;i<k;i++)
    {
        ans=char(x%3+'A')+ans;
        x/=3;
    }
    cout<<ans<<" ";
}
void solve() 
{
    cin>>n>>k>>m;
    int mx=pow(3,k);
    vector<int>dp(mx,0);
    vector<int>vtt;
    vector<int>vt(mx,0);
    dp[0]=1;
    vt[0]=1;
    vtt.push_back(0);
    for(int i=1;i<=n;i++)
    {
        auto g=dp;
        string s;
        cin>>s;
        
        vector<int>op(k,0);
        for(int j=0;j<k;j++) 
        if(s[j]=='+') op[j]=1;
        else if(s[j]=='-') op[j]=2;
        vector<int>t;
        for(auto j:vtt)
        {
            int cur=0;
            int v=1;
            int jj=j;
            for(int j1=k-1;j1>=0;j1--)
            {
                int ch=j%3;
                j/=3;
                cur+=((ch+op[j1])%3)*v;
                v*=3;
            }
            dp[cur]=(dp[cur]+g[jj])%m;
            if(!vt[cur]) t.push_back(cur);
        }
        for(auto j:t) 
        {
            vt[j]=1;
            vtt.push_back(j);
        }
    }

    for(int i=0;i<mx;i++) 
    if(vt[i]) 
    {
        print(i);
        cout<<dp[i]<<"\n";
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