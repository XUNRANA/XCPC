#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[1000010];
void solve()
{

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=n+n-1;
    for(int i=2;i<=n-1;i++) 
    {
        if(a[i]>a[i-1]&&a[i]>a[i+1]) ans++;
        if(a[i]<a[i-1]&&a[i]<a[i+1]) ans++;
    }

    for(int i1=1;i1<=n-3;i1++)
    {
        int i=a[i1];
        int j=a[i1+1];
        int k=a[i1+2];
        int l=a[i1+3];

        if(i<=j&&j<=max(k,l)) continue;
        if(i>=j&&j>=min(k,l)) continue;



        if(min(i,j)<=k&&k<=l) continue;
        if(max(i,j)>=k&&k>=l) continue;

        ans++;
    }


    // for(int i=1;i<=4;i++)
    // for(int j=1;j<=4;j++)
    // for(int k=1;k<=4;k++)
    // for(int l=1;l<=4;l++)
    // for(int m=1;m<=4;m++)
    // {
    //     if(i<=j&&j<=max(k,l)) continue;
    //     if(i>=j&&j>=min(k,l)) continue;

    //   4
    // 3 
    //      2
    //   1 
    //     if(k>=min(i,j)&&k<=l) continue;
    //     if(k<=max(i,j)&&k>=l) continue;

    //     cout<<i<<" "<<j<<" "<<k<<" "<<l<<"\n"; 
    // }

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