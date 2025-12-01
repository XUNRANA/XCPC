#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[3010];
bool ck(int x)
{
    int tx=x;
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(x>=a[i]) 
        {
            x-=a[i];
            c++;
        }
        else
        {
            if(x) c++;
            return c+(tx-c)/k>=n;
        }
    }
    return c+(tx-c)/k>=n;
}

void solve()
{
    cin>>n>>k;       
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    int l=1,r=k*n;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) r=m-1;
        else l=m+1;
    }
    cout<<l<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}