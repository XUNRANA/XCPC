#include <bits/stdc++.h>
using namespace std;
set<int>st[200010];
int is[200010];
void solve()
{
    int n,m,q,op,x,y;
    cin>>n>>m>>q;
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x>>y;
            st[x].insert(y);
        }
        else if(op==2)
        {
            cin>>x;
            is[x]=1;
        }
        else
        {
            cin>>x>>y;
            if(is[x]) cout<<"Yes\n";
            else if(st[x].count(y)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }

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