#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,y,a,b,f,mx;
void dfs(int n,int s)
{
    if(s>=10)
    {
        f=1;
        return ;
    }
    mx=max(mx,n);
    if(n%x==0) dfs(n+a,s+1);
    if(n%y==0) dfs(n+b,s+1);
}

void solve()
{
	int n;
	cin>>n>>x>>y>>a>>b;
    f=0;
    mx=n;
    dfs(n,0);
    if(f) cout<<"baka\n";
    else cout<<mx<<"\n"; 
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
