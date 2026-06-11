#include <bits/stdc++.h>
using namespace std;
int n,a[500010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    // 1 3 4 5 6 9
    sort(a+1,a+1+n);
    int len=0;
    int ansl=0;

    // for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    // cout<<"\n";
    for(int i=1;i<n;i++)
    {
        int x=a[i];
        int y=a[i+1];
        int z=x+y-1;
        int j=upper_bound(a+1,a+1+n,z)-a-1;
        // cout<<i<<" "<<j<<"????\n";
        if(j>i+1) 
        {
            if(j-i+1>len)
            {
                len=max(len,j-i+1);
                ansl=i;
            }
        }
    }

    if(!len) cout<<len<<"\n";
    else
    {
        cout<<len<<" ";
        for(int i=ansl;i<ansl+len;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}