#include <bits/stdc++.h>
using namespace std;
int ck(int x)
{
	for(int i=2;i*i<=x;i++) if(x%i==0) return 1;
	return 0;
}
void solve()
{
	int n;
	cin>>n;
	if(ck(n)) cout<<"No\n";
	else cout<<"Yes\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
