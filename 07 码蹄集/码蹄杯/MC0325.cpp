#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353

int fa[100];
int find(int x)
{
    return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    fa[fx]=fy;
}
void solve()
{
    int n;
    cin>>n;
    vector<array<int,3>>v;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        for(int j=1;j<=n;j++)
        {
            int d;
            cin>>d;
            v.push_back({d,i,j});
        }
    }
    sort(v.begin(),v.end());
    
    int ans=0;
    for(auto i:v)
    {
        if(find(i[1])==find(i[2])) continue;
        ans+=i[0];
        merge(i[1],i[2]);
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
