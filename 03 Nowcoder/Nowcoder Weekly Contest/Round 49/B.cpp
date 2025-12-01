#include <bits/stdc++.h>
using namespace std;
#define int long long
int dfs(int x)
{
	if(x==0) return 0;
	if(x==1) return 1;
	return 2*dfs(x/2)+1;
}
void solve()
{
	int h;
	cin>>h;
	cout<<dfs(h);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
