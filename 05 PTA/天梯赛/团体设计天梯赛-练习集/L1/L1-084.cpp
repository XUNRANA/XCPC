#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x)
{
	if(x==1) return 1;
	return x*f(x-1);
}
void solve()
{
	int a,b;
	cin>>a>>b;
	cout<<f(a+b);
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

