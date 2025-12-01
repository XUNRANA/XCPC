#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
void solve() 
{
    int n,sum;
    cin>>n>>sum;
    for(int i=1;i<=n;i++) cin>>a[i];
    int s=0;
    int ans=-1;
    for(int i=1,j=1;j<=n;j++)
    {
        s+=a[j];
        while(s>sum)
        {
            s-=a[i];
            i++;
        }
        if(s==sum) ans=max(ans,j-i+1);
    }
    if(ans==-1) cout<<-1<<"\n";
    else cout<<n-ans<<"\n";
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