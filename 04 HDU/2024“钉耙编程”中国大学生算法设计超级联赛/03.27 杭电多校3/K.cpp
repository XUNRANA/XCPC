#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[200010];
int y[200010];
char ch[200010];
int n;
int fx(int t)
{
    int mix=1e18;//x的最小值
    int mxx=-1e18;

    int miy=1e18;
    int mxy=-1e18;
    for(int i=1;i<=n;i++)
    {
        int xx=x[i],yy=y[i];
        if(ch[i]=='E') xx+=t;
        else if(ch[i]=='W') xx-=t;
        else if(ch[i]=='N') yy+=t;
        else yy-=t;
        mix=min(mix,xx);
        mxx=max(mxx,xx);
        miy=min(miy,yy);
        mxy=max(mxy,yy);
    } 
    return 2*(mxx-mix)+2*(mxy-miy);
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>ch[i];
    int l=0,r=1e18;
    while(l<r)
    {
        int m1=l+(r-l)/3;
        int m2=r-(r-l)/3;
        if(fx(m1)<fx(m2)) r=m2-1;
        else l=m1+1;
    }
    cout<<fx(l)<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}