#include <bits/stdc++.h>
using namespace std;
#define int long long
int dis(int x1,int y1,int x2,int y2)
{
	return pow(x1-x2,2)+pow(y1-y2,2);
}
void solve()
{
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(dis(x1,y1,-x2,y2)<dis(x1,y1,x2,-y2)) cout<<"y\n";
	else cout<<"x\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
