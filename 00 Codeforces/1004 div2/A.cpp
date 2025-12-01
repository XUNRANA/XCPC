#include <bits/stdc++.h>
using namespace std;
#define int long long
int s(int x)
{
    int res=0;
    while(x)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}
void solve()
{
    int x,y;
    cin>>x>>y;
    if(y==x+1) cout<<"YES\n";
    else
    {
        int d=y-x;
        if(d<0&&abs(d)%9==8) cout<<"YES\n";
        else cout<<"NO\n";
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

