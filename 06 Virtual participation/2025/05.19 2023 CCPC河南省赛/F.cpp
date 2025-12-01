#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500010];
int d[500010];
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++) d[i]=a[i+1]-a[i];
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>q;
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {
        if(i>1) q.push({d[i-1],i-1});        
        if(i>=k) 
        {
            while(q.top()[1]<=i-k) q.pop();
            ans=min(ans,(a[i]-a[i-k+1])*q.top()[0]);
        }    
    }
    cout<<ans<<"\n";
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