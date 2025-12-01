#include <bits/stdc++.h>
using namespace std;
#define int long long
int is(int x)
{
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
signed main()
{
	int n,k;
	cin>>n>>k;
	if(is(k+1))
	{
		if((k+1)*2<=n+1) cout<<2;
		else cout<<1;
	}
	else cout<<2;
} 
