#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int t=1;
	int x=343720;
	int y=233333;
	while(1)
	{ 
		if(t*15%x==0&&t*17%y==0) break;
		t++;
	}
	printf("%.2f\n",2*sqrt(15*15*t*t+t*t*17*17));
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
