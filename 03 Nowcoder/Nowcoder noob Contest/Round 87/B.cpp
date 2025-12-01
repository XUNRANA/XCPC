#include <bits/stdc++.h>
using namespace std;
int t,n,mi,mx,a[200010];
int main()
{
    cin>>t;
    while(t--)
    {
        mi=1e9;
        mx=1;
        cin>>n;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            mi=min(mi,a[i]);
            mx=max(mx,a[i]);
        }
        if(a[1]==mi||a[n]==mx) cout<<"YES\n";
        else cout<<"NO\n";
    }
}