#include <bits/stdc++.h>
using namespace std;
#define int long long
int s[200010];
void solve() 
{
    int n,x;
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1];
        cin>>x;
        if(i>x) 
        {
            // cout<<i<<" "<<x<<"\n";
            // ans+=s;
            ans+=s[x-1];
            s[i]++;
            // s++;
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