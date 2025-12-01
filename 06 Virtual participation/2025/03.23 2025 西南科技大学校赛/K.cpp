#include <bits/stdc++.h>
using namespace std;
#define int long long
int pre[100010][30];
int a[100010];
bool ck1(int l,int r,int x)
{
    int ans=0;
    for(int i=0;i<30;i++)
    {
        if(r-l+1==pre[r][i]-pre[l-1][i]) ans^=1<<i;
    }
    return ans>=x;
}
bool ck2(int l,int r,int x)
{
    int ans=0;
    for(int i=0;i<30;i++)
    {
        if(pre[r][i]-pre[l-1][i]>=1) ans^=1<<i;
    }
    return ans<=x;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;j<30;j++) 
        {
            pre[i][j]=pre[i-1][j];
            if(a[i]>>j&1) pre[i][j]++;
        }
    }
    while(q--)
    {
        int id,k;
        cin>>id>>k;
        int lx=k-a[id];
        int rx=k+a[id];
        if(a[id]>=lx&&a[id]<=rx)
        {
            int l,r,m,ansl,ansr;
            l=1,r=id;
            // for(int i=l;i<=r;i++) cout<<i<<" "<<ck1(i,id,lx)<<"\n";
            while(l<=r)
            {
                m=l+r>>1;
                if(ck1(m,id,lx)) r=m-1;
                else l=m+1;
            }
            ansl=l;

            l=id,r=n;
            // for(int i=l;i<=r;i++) cout<<i<<" "<<ck2(id,i,rx)<<"?\n";
            while(l<=r)
            {
                m=l+r>>1;
                if(ck2(id,m,rx)) l=m+1;
                else r=m-1;
            }
            ansr=l-1;
            cout<<ansl<<" "<<ansr<<"\n";
        }
        else cout<<"-1\n";
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
