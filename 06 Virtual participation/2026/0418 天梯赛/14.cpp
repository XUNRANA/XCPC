#include <bits/stdc++.h>
using namespace std;
//N<=1e4
int n;
struct node
{
    int r,b,i;
}a[100010];
int vt[100010];
bool cmpr(node a1,node a2)
{
    if(a1.r==a2.r) return a1.b<a2.b;
    return a1.r<a2.r;
}

bool cmpb(node a1,node a2)
{
    if(a1.b==a2.b) return a1.r<a2.r;
    return a1.b<a2.b;
}
int fx1(int x)
{
    sort(a+1,a+1+n,cmpr);
    int cnt1=0;
    for(int i=2;i<=n;i++) if(!vt[a[i].i]&&a[i].r==a[i-1].r) cnt1++;


    sort(a+1,a+1+n,cmpb);
    int cnt2=0;
    for(int i=2;i<=n;i++) if(!vt[a[i].i]&&a[i].b==a[i-1].b) cnt2++;

    return 2*n-max(cnt1,cnt2+x);
}

int fx2(int x)
{
    sort(a+1,a+1+n,cmpr);
    int cnt1=0;
    for(int i=2;i<=n;i++) if(!vt[a[i].i]&&a[i].r==a[i-1].r) cnt1++;


    sort(a+1,a+1+n,cmpb);
    int cnt2=0;
    for(int i=2;i<=n;i++) if(!vt[a[i].i]&&a[i].b==a[i-1].b) cnt2++;

    return 2*n-max(cnt1+x,cnt2);
}


void solve()
{
    cin>>n;
    map<int,vector<int>>mpr,mpb;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i].r>>a[i].b;
        a[i].i=i;
        mpr[a[i].r].push_back(i);
        mpb[a[i].b].push_back(i);
    }

    int ans=2*n;
    int mx=0;
    for(auto i:mpr) mx=max(mx,(int)i.second.size());
    for(auto i:mpb) mx=max(mx,(int)i.second.size());

    for(auto i:mpr)
    {
        if((int)i.second.size()==mx)
        {
            for(auto j:i.second) vt[j]=1;
            ans=min(ans,fx1(mx));
            for(auto j:i.second) vt[j]=0;
        }
    }

    for(auto i:mpb)
    {
        if((int)i.second.size()==mx)
        {
            for(auto j:i.second) vt[j]=1;
            ans=min(ans,fx2(mx));
            for(auto j:i.second) vt[j]=0;
        }
    }
    cout<<ans<<"\n";

    // cout<<i.second.size()<<"??\n";
    // for(auto i:mpb) cout<<i.second.size()<<"!!\n";

    // for(int )


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}