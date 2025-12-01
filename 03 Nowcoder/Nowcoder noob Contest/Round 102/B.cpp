#include <bits/stdc++.h>
using namespace std;
void solve()
{
	double a;
	cin>>a;
	double ans=sqrt((a*a+4)/4)+a/2;
	printf("%.20f\n",ans);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
