#include <bits/stdc++.h>
using namespace std;
#define int long long

void fx(int x,int d)
{
    if(x==0) return ;
    fx(x/d,d);
    cout<<x%d;
}
void solve()
{
    int a,b,d;
    cin>>a>>b>>d;
    if(a+b==0) cout<<0;
    else fx(a+b,d);
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

