#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b;
	cin>>a>>b;
	printf("%d/%.1f=%d",a,1.0*a/b,b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
