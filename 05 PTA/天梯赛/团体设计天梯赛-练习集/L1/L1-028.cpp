#include <bits/stdc++.h>
using namespace std;
#define int long long
int is(int x)
{
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void solve()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		if(is(x)) cout<<"Yes\n";
		else cout<<"No\n";
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

