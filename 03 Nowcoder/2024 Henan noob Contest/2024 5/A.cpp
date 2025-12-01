#include <bits/stdc++.h>
using namespace std;
int x,y,z;
void solve()
{
	cin>>x>>y>>z;
	if(y==9&&z==30||y==11&&z==30||(y+z)%2==0) cout<<"YES\n";
	else cout<<"NO\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
