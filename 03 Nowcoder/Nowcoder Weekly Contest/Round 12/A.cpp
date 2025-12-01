#include <bits/stdc++.h>
using namespace std;
long long x,y,z,k1,k2;
void solve()
{
	cin>>x>>y>>z;
	int k1=z%(3*x+y),k2=z/(3*x+y);
	if(!k1) cout<<3*k2<<"\n";
	else if(k1<=x+y) cout<<k2*3+1;
	else if(k1<=2*x+y) cout<<k2*3+2;
	else cout<<k2*3+3<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
