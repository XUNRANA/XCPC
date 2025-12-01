#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
void solve() 
{
    int n,k,x;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        ans+=x/k;
        a[i]=x%k;
    } 
    sort(a+1,a+1+n);
    int i=1,j=n;
    while(i<j)
    {
        while(i<j&&a[j]+a[i]<k) i++;
        if(i<j&&a[j]+a[i]>=k)
        {
            ans++;
            i++;
            j--;
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