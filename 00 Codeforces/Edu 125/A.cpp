#include <bits/stdc++.h>
using namespace std;
int is(int x,int y)
{
	return sqrt(x*x+y*y)==int(sqrt(x*x+y*y));
}
void solve()
{
	int x,y;
	cin>>x>>y;
	if(!x&&!y) cout<<"0\n";
	else if(is(x,y)) cout<<"1\n";
	else cout<<"2\n";
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

