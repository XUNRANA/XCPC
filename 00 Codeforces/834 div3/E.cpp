#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,h,a[200010];
void solve()
{
    cin>>n>>h;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=3;i++)
    {
        int res=h;
        int c=1;
        int j;
        for(j=1;j<=n&&c<=4;)
        {
            if(res>a[j])
            {
                res+=a[j]/2;
                j++;
            }
            else 
            {
                if(c==i) res*=3;
                else res*=2;
                c++;
            } 
        }
        ans=max(ans,j-1);
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


