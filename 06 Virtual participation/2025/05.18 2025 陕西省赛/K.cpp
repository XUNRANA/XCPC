#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,y;
void solve()
{
    cin>>n>>m>>x>>y;

    if(!n&&!m) cout<<"0\n";
    else if(!n) 
    {
        if(x>y) cout<<x<<"\n";
        else cout<<m*y<<"\n";
    }
    else if(!m)
    {
        cout<<(n-1)*y+max(x,y)<<"\n";
    }
    else
    {
        if(!y)
        {
            cout<<x<<"\n";
        }
        else if(x<=y) cout<<(n+m)*y<<"\n";
        else//x>y
        {
            int ans=x+n*y;
            int c=(x-1)/y;
            if(c<=n) ans=max(ans,x+(n+m-c)*y);
            cout<<ans<<"\n";
        }
    }
        
    
   
    
    
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}