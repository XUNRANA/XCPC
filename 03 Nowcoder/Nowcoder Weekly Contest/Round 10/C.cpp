#include <bits/stdc++.h>
using namespace std;
void solve()
{
    double v0,x,y;
    cin>>v0>>x>>y;
    if(v0>sqrt(x*y)) printf("%.12f",y/v0);
    else printf("%.12f",2*sqrt(y/x)-v0/x);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
