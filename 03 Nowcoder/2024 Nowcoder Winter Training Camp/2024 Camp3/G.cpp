#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y,z,a,b,c;
void solve()
{
    cin>>n;
    if(n==1)
    {
        cin>>x>>y>>z;
        if(x==y&&z==1) cout<<"No\n";
        else cout<<"Yes\n";
    }
    else
    {
        cin>>x>>y>>z;
        cin>>a>>b>>c;
        if(x==y&&z||a==b&&c) 
        {
            cout<<"No\n";
            return ;
        }
        if(x==a&&y==b)
        {
            if(z!=c) cout<<"No\n";
            else cout<<"Yes\n";
            return ;
        }
        
        if(x==b&&y==a)
        {
            if(z==c&&z==1) cout<<"No\n";
            else cout<<"Yes\n";
            return ;
        }
        cout<<"Yes\n";
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
