#include <bits/stdc++.h>
using namespace std;
int x,y,l,r,g,c1,c2;
void solve()
{
	cin>>x>>y>>l>>r;
    g=__gcd(x,y);
    x/=g;
    y/=g;
    if(x>y) swap(x,y);
    c1=(l+x-1)/x;
    c2=r/y;
    if(c2-c1+1>0) cout<<c2-c1+1;
    else cout<<0;

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

