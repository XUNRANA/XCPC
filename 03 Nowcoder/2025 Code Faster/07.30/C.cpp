#include <bits/stdc++.h>
using namespace std;
int n,k;
void solve()
{
    cin>>n>>k;
    multiset<int>a,b;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        a.insert(x);
        b.insert(x^k);
    }
    for(int i=1;i<n;i++)
    {
        if(i&1)
        {
            int x=*b.begin();
            b.erase(b.begin());
            a.erase(a.find(x^k));
        }
        else
        {
            int x=*a.begin();
            a.erase(a.begin());
            b.erase(b.find(x^k));
        }
    }

    if(n&1) cout<<*a.begin();
    else cout<<*b.begin();
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}