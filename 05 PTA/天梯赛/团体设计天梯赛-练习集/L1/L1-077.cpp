#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[30];
void solve()
{
	for(int i=0;i<=23;i++) cin>>a[i];
	while(1)
	{
		int x;
		cin>>x;
		if(x<0||x>23) break;
		if(a[x]>50) cout<<a[x]<<" Yes\n";
		else cout<<a[x]<<" No\n";
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

