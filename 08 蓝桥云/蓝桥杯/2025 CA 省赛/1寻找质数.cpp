#include <bits/stdc++.h>
using namespace std;
#define int long long
int is(int x)
{
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void solve()
{
	int cnt=0;
	for(int i=2;i<1e5;i++)
	{
		if(is(i)) 
		{
			cnt++;
			if(cnt==2025) cout<<i<<"\n";
		}
	}
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
