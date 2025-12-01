#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200010];
int p[200010];
int n,s;
int get(int x)
{
    int ans=0;
    map<int,int>cnt;
    cnt[0]++;
    
    for(int i=1;i<=n;i++)
    {
        if(a[i]>x)
        {
            cnt.clear();
        }
        if(cnt.count(p[i]-s))
        {
            ans+=cnt[p[i]-s];
        }
        cnt[p[i]]++;
    }
    return ans;
}
void solve()
{
    int x;
    cin>>n>>s>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
    cout<<get(x)-get(x-1)<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}