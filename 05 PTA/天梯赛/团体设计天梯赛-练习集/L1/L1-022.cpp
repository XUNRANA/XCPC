#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n;
	cin>>n;
	int c0=0,c1=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x&1) c1++;
		else c0++;
	}
	cout<<c1<<" "<<c0<<"\n";
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

