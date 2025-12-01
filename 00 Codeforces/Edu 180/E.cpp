#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 600010

int f[M];
vector<int> fct[M];
void init()
{
    for(int i=0;i<M;i++) f[i]=-1;
    f[1]=1;
    for(int i=1;i<M;i+=2)
    {
        for(int j=2*i;j<M;j+=i)
        fct[j].push_back(i);
    }

    for(int i=3;i<M;i+=2) 
    {
        f[i]=1e9;
        for(auto j:fct[i]) f[i]=min(f[i],f[j]+f[i/j-2]);
    }
}
void solve()
{
    int m;
    cin>>m;
    cout<<f[m]<<"\n";
}
signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}