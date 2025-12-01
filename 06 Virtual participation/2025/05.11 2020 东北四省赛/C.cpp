#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x)
{
    int p=x+1;
    int k=10;
    int res=x;
    while(k<x)
    {
        res=res*(x%k)%p;
        k*=10;
    }
    return res;
}

int g(int n,int m)
{
    if(m==1) return f(n);
    else return f(g(n,m-1));
}
void solve() 
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    int p;
    for(int i=1;i<=m;i++)
    {
        if(g(n,i)==p)
        {
            ans+=(m-i+1)*p;
            break;
        }
        ans+=g(n,i);
        p=g(n,i);
    }
    cout<<ans<<"\n";
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