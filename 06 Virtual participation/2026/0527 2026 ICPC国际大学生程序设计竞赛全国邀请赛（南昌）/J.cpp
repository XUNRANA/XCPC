#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1010];
// 0 1 2 3

bool ck
void solve()
{
    for(int i=1;i<=1000;i++) a[i]=i;
    for(int i=1;i<=1000;i++) 
    {
        for(int j=i+1;j<=1000;j++)
        {
            int l=1,r=min(i,j);
            while(l<=r)
            {
                int m=(l+r)>>1;
                if(ck(m)) r=m-1;
                else l=m+1;
            }
            cout<<i<<" "<<j<<" "<<l<<"\n";



            
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
