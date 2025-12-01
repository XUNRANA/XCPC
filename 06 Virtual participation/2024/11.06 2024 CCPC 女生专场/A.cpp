#include <bits/stdc++.h>
using namespace std;
int z0,h,u0,v0,u1,v1,x,y,z,q;
void solve()
{
	cin>>z0>>h>>u0>>v0>>u1>>v1;
	cin>>q;
	while(q--)
	{
		cin>>x>>y>>z;
		if(z>=z0&&z<=z0+h&&x>=min(u0,u1)&&x<=max(u0,u1)&&y>=min(v0,v1)&&y<=max(v0,v1)) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
