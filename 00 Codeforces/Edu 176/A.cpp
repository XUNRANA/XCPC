#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,k,cnt=0;
	cin>>n>>k;
	if(n&1)
	{
		if(k&1) n=max(0ll,n-k);
		else n=max(0ll,n-(k-1));
	}
	else
	{
		if(k&1) n=max(0ll,n-(k-1));
		else n=max(0ll,n-k);
	}
	if(k&1) cnt=1+(n+k-2)/(k-1);
	else cnt=1+(n+k-1)/k;
	cout<<cnt<<"\n";
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

