#include <bits/stdc++.h>
using namespace std;
#define P 998244353
#define P1 1331
int p[21];

void solve()
{
    int n,m;
    cin>>n>>m;
    map<int,string>mp;
    for(int i=1;i<=n;i++)
    {
        int res=1;
        for(int j=1;j<=m;j++) 
        {
            int x;
            cin>>x;
            res=(res*P1%P+x)%P;
        }
        string s;
        cin>>s;
        mp[res]=s;
    }
    while(1)
    {
        int res=1;
        for(int i=1;i<=m;i++)
        {
            int x;
            cin>>x;
            if(!x&&(i==1)) return ;
            res=(res*P1%P+x)%P;
        }
        if(mp.count(res)) cout<<mp[res]<<"\n";
        else cout<<"Pass\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
