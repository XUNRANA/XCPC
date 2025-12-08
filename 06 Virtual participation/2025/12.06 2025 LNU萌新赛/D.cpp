#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p;
int a[100010];
void solve()
{
    cin>>n>>p;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        a[i]%=p;
    }
    sort(a+1,a+1+n);

    int ans=0;
    for(int i=1;i<=n;i++) 
    {
        int x=a[i];
        int y=p-x-1;
        int j=upper_bound(a+1,a+1+n,y)-a;
        j--;
        if(j==i) j--;
        if(j) ans=max(ans,a[i]+a[j]); 


        y=2*p-x-1;
        j=upper_bound(a+1,a+1+n,y)-a;
        j--;
        if(j==i) j--;
        if(j) ans=max(ans,(a[i]+a[j])%p); 

    }
    cout<<ans<<"\n";
} 
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}