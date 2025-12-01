#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[100010];
void solve()
{
    cin>>n;
    int ans=0;
    int mx=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        mx=max(mx,__lg(a[i]));
        ans+=a[i];
    }

    
    for(int j=0;j<=mx;j++)
    {
        int c1=0,c0=0;
        for(int i=1;i<=n;i++) 
        if(a[i]>>j&1) 
        {
            ans+=2*c1*(1<<j);
            ans+=c0*(1<<j);
            c1++;
        }
        else 
        {
            ans+=c1*(1<<j);
            c0++;
        }


        // cout<<j<<" "<<c0<<" "<<c1<<"\n";
        // cout<<ans<<"\n";
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
}


// 0011
// 0100
// 0110
// 1001
//& |

//1 1-> 1 1
//1 0/0 1 ->1 0
// 0 0-> 0 0

