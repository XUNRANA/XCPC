#include <bits/stdc++.h>
using namespace std;
#define int long long


int n,m,l;
int a[21];
int val[1<<20];
int is[1<<20];

void dfs(int s)
{
    if(is[s]) return ;
    is[s]=1;
    for(int i=0;i<l;i++)
    {
        if(!(s>>i&1))
        {
            if((i+1)%m!=0)
            {
                if(!(s>>(i+1)&1))
                {
                    dfs(s^(1<<i)^(1<<(i+1)));
                }
            }
            if(i+m<l)
            {
                if(!(s>>(i+m)&1))
                {
                    dfs(s^(1<<i)^(1<<(i+m)));
                }
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    l=n*m;
    int s=0;
    for(int i=0;i<l;i++) 
    {
        cin>>a[i];
        s^=a[i];
    }
    dfs(0);
    int res=0;
    for(int i=0;i<(1<<l);i++)
    {
        if(is[i])
        {
            int ans=s;
            for(int j=0;j<l;j++) if(i>>j&1) ans^=a[j];
            res=max(res,ans);
        }
    }
    cout<<res<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}