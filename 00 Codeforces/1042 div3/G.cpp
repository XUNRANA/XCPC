#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int mx=1;
int f[50];
int g[50];
void init()
{
    f[0]=0;//f[i]移除1,2,,i需要的操作次数
    g[0]=1;//g[i]移除1,2,,i可获得的贡献
    while(1)
    {
        f[mx]=f[mx-1]*2+1;
        g[mx]=g[mx-1]*g[mx-1]%P*mx%P;
        if(f[mx]>1e9) break;
        mx++;
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;
    set<int>s;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }

    int ans=1;
    while(s.size()&&k)
    {
        int val=*s.begin();
        s.erase(s.begin());
        if(val<=mx&&f[val-1]+1<=k)
        {
            k-=f[val-1]+1;
            ans=ans*g[val-1]%P*val%P;
            ans%=P;
        }
        else
        {
            ans=ans*val%P;
            k--;
            for(int i=1;i<=min(mx,val-1);i++) s.insert(i);
        }
    }
    cout<<ans<<"\n";

}

signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}