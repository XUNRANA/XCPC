#include <bits/stdc++.h>
using namespace std;
#define int long long
int op[2010];
int x[2010];
int y[2010];
int h[2010];
int vt[2010];
int dis(int i,int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i];
        if(op[i]==1)
        {
            cin>>x[i]>>y[i]>>h[i];
        }
        else
        {
            int atk,r;
            cin>>x[i]>>y[i]>>atk>>r;
            int idx=-1,mi=1e18;
            for(int j=1;j<i;j++)
            {
                if(op[j]==2||vt[j]) continue;
                if(dis(j,i)<mi)
                {
                    mi=dis(j,i);
                    idx=j;
                }
            }

            if(idx!=-1) 
            {
                for(int j=1;j<i;j++)
                {
                    if(op[j]==2||vt[j]) continue;
                    if(dis(j,idx)<=r*r)
                    {
                        h[j]-=3*atk;
                        if(h[j]<=0) vt[j]=1;
                        else vt[i]=1;
                    }
                }
            }
        }
    }

    for(int i=1;i<=n;i++) if(vt[i]) cout<<"No\n";
    else cout<<"Yes\n";

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
