#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int l,r,x;
}a[100010]; 
bool cmp(node a1,node a2)
{
    if(a1.l==a2.l) return a1.r<a2.r;
    return a1.l<a2.l;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r>>a[i].x;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) if(k>=a[i].l) k=max(k,a[i].x);
    cout<<k<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
