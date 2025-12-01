#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s[300010];
int a,b,c;
bool ck(int l)
{
    for(int i=1;i+l-1<=n;i++)
    {
        int lf=i;
        int ri=i+l-1;
        if(s[ri]-s[lf-1]>a*(b*ri-c*lf)) return 1; 
    }
    return 0;
}
void solve()
{
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n;i++) cin>>s[i],s[i]+=s[i-1];
    int l=1,r=n;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) l=m+1;
        else r=m-1;
    }
    l--;
    cout<<l<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
