#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y,a[200010];

void solve()
{
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        a[i]=min(a[i],y);
    }
    sort(a+1,a+1+n);
    int ans=0,cur=-n;
    for(int i=1;i<=n;i++)
    {
        if(x<a[i])
        {
            if(cur<=0)
            {
                cout<<"-1\n";
                return ;
            }
            int t=(a[i]-x+cur-1)/cur;
            x+=t*cur;
            ans+=t*n;
        }
        if(x>=y) break;
        x++;
        cur+=2;
        ans++;
    }
    cout<<ans+y-x<<"\n";
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