#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ck(int a,int b,int c)
{
	if(a+b>c&&b+c>a&&a+c>b) return 1;
	return 0;
}
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(ck(2*a,b,c)||ck(a,2*b,c)||ck(a,b,2*c)) cout<<"Yes\n";
	else cout<<"No\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
