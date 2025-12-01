#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 988444333
int a,b,c,k;
void solve()
{
	cin>>a>>b>>c>>k;
	cout<<(a+k)*(b+k)%P*(c+k)%P<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
