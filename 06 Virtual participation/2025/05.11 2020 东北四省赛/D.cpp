#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int x,c,i;
    int t;
}a[200010];
bool cmp(node a1,node a2)
{
    if(a1.t==a2.t) return a1.i<a2.i;
    return a1.t<a2.t;
}
void solve() 
{
    int n,h,H;
    cin>>n>>h>>H;
    for(int i=1;i<=n;i++) cin>>a[i].x;
    for(int i=1;i<=n;i++) cin>>a[i].c;
    
    for(int i=1;i<=n;i++)
    {
        a[i].i=i;
        int hh=a[i].x%(2*H);
        if(hh<=h)
        {
            a[i].t=a[i].x+a[i].c;
        }
        else
        {
            if(hh<=H)
            {
                a[i].t=a[i].x+H-hh+H-h+a[i].c;
            }
            else 
            {
                if(H-(hh-H)<=h) a[i].t=a[i].x+a[i].c;
                else a[i].t=a[i].x+H-(hh-H)-h+a[i].c;
            }
        }
    }
    sort(a+1,a+1+n,cmp);
    cout<<a[1].i<<"\n";
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