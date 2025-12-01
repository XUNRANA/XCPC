#include <bits/stdc++.h>
using namespace std;
int n,a[500010];
int idx[500010];
int g[500010][241];
void init()
{
    for(int i=1;i<=5e5;i++)
    {
        for(int j=i;j<=5e5;j+=i) 
        g[j][++idx[j]]=i;
    }
}
int cnt[500010];
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        cnt[x]++;
        a[i]=x;
    }
    sort(a+1,a+1+n);
    long long ans=0;
    for(int i=1;i<=n;i++) 
    {
        if(a[i]!=a[i-1])
        {
            int x=a[i];
            for(int k=1;k<=idx[x];k++)
            {
                int j=g[x][k];
                if(x+j>n) break;
                ans+=1ll*cnt[x]*cnt[x+j];
            }
        }
    }
    for(int i=1;i<=n;i++) cnt[a[i]]=0;
    cout<<ans<<"\n";
}

signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;i*(j+1)<=n;j++)
        {
            ans+=a[i*j]*a[(j+1)*i];
        }
    }
    cout<<ans<<"\n";
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
*/