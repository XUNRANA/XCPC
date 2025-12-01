#include <bits/stdc++.h>
using namespace std;
#define int long long
int sx,sy,tx,ty;
int res=1e9;
void dfs(int x,int y,int s)
{
    
    if(x==sx&&y==sy)
    {
        res=min(res,s);
        return ;
    }
    else if(x<sx||y<sy) return ;
    

    
    if(y>x)
    {
        if(y>2*x) dfs(x,y/2,s+1);
        else dfs(x,y-x,s+1);
    }
    else
    {
        if(x>2*y) dfs(x/2,y,s+1);
        else dfs(x-y,y,s+1);
    }
}

void solve()
{
    cin>>sx>>sy>>tx>>ty;
    if(tx==ty)
    {
        if(sx==tx&&sy==ty) cout<<"0\n";
        else cout<<"-1\n";
    }

    dfs(tx,ty,0);

    if(res==1e9) res=-1;
    cout<<res<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
