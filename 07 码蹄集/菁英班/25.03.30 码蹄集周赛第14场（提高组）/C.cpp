#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n,m;
    cin>>n>>m;
    vector<int>r(n+1,0);
    vector<int>c(m+1,0);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) 
    {
        char ch;
        cin>>ch;
        if(ch=='X') 
        {
            r[i]^=1;
            c[j]^=1;
        }
    }
    int c1=0,c2=0;
    for(int i=1;i<=n;i++) if(r[i]) c1++;
    for(int i=1;i<=m;i++) if(c[i]) c2++;
    cout<<max(c1,c2)<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}