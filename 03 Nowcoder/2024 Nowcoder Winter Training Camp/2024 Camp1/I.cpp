#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int x,y,r;
		cin>>x>>y>>r;
		sum+=abs(x)+abs(y);
	}
	if(sum>90*n) cout<<"bit-noob\n";
	else cout<<"buaa-noob\n";
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
